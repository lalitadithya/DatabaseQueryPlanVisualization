using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;

namespace Launcher
{
    class SqlQueryPlan
    {

        public static string GetXmlPlanForQuery(string queryText)
        {
            string result = null;
            string connectionString = "Data Source=LALIT-ADITHYA\\SQLEXPRESS;" +
                    "Initial Catalog=RoSAT;" +
                    "Integrated Security=SSPI;";
            using (var connection = new SqlConnection(connectionString))
            using (var command = new SqlCommand())
            {
                connection.Open();
                command.Connection = connection;

                //Enable the statistics.
                command.CommandText = "SET STATISTICS XML ON";
                command.ExecuteNonQuery();

                //Run through the query, keeping the first row first column of the last result set.
                command.CommandText = queryText;
                using (var reader = command.ExecuteReader())
                {
                    object lastValue = null;
                    do
                    {
                        if (reader.Read())
                        {
                            lastValue = reader.GetValue(0);
                        }
                    } while (reader.NextResult());

                    if (lastValue != null)
                    {
                        result = lastValue as string;
                    }
                }
            }
            return result;
        }

        public static void ExtractDataFromXml(string xml, ref Node root, int level = 0)
        {
            XNamespace ns = "http://schemas.microsoft.com/sqlserver/2004/07/showplan";
            XDocument doc = XDocument.Parse(xml);

            bool foundNodeInImmediateChildern = false;

            foreach (var element in doc.Root.Elements(ns + "RelOp"))
            {
                foundNodeInImmediateChildern = true;
                Node myNode = new Node
                {
                    Id = 0,
                    Name = element.Attribute("PhysicalOp").Value
                };
                root.AddChild(myNode);

                ExtractDataFromXml(element.ToString(), ref myNode, level + 1);
            }

            if (!foundNodeInImmediateChildern)
            {
                foreach (var element in doc.Root.Elements())
                {
                    ExtractDataFromXml(element.ToString(), ref root, level);
                }
            }
        }

        public static int id = 0;

        public static void SerilizeTree(ref Node root, ref string text, int level = 0, int parnet_id = 0)
        {
            int currentNodeId = id++;
            text += currentNodeId + " " + parnet_id + " " + root.Name.Replace(" ", "_") + "\n";
            foreach (var child in root.GetChildren())
            {
                Node temp = child;
                SerilizeTree(ref temp, ref text, level + 2, currentNodeId);
            }
        }
    }
}
