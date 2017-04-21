using System.Collections.Generic;
using System.Data.SqlClient;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows;
using System.Xml;
using System.Xml.Linq;
using System.Linq;
using System.Windows.Documents;

namespace Launcher
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string query = new TextRange(QueryTextBox.Document.ContentStart, QueryTextBox.Document.ContentEnd).Text.Trim();

            if (string.IsNullOrWhiteSpace(query))
            {
                MessageBox.Show("Query can not be empty");
            }
            else
            {
                ShowStatButton.IsEnabled = false;

                Node root = new Node()
                {
                    Name = "Select"
                };
                XNamespace ns = "http://schemas.microsoft.com/sqlserver/2004/07/showplan";
                XDocument doc = XDocument.Parse(SqlQueryPlan.GetXmlPlanForQuery(query));
                SqlQueryPlan.ExtractDataFromXml(doc.Descendants(ns + "QueryPlan").First().ToString(), ref root);

                string toWrite = "";
                SqlQueryPlan.SerilizeTree(ref root, ref toWrite);

                System.IO.File.WriteAllText("query.txt", toWrite);

                OpenGl.DisplayVisualization();

                ShowStatButton.IsEnabled = true;
            }
        }
    }

    class OpenGl
    {
        [DllImport("MyWrapper.dll", CallingConvention = CallingConvention.Cdecl)]

        public static extern void DisplayVisualization();
    }
}
