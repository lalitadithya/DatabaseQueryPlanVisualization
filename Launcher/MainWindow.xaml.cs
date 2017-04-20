using System.Collections.Generic;
using System.Data.SqlClient;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows;
using System.Xml;
using System.Xml.Linq;
using System.Linq;

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
            Node root = new Node()
            {
                Name = "Select"
            };
            XNamespace ns = "http://schemas.microsoft.com/sqlserver/2004/07/showplan";
            XDocument doc = XDocument.Parse(SqlQueryPlan.GetXmlPlanForQuery("select * from Marks inner join Student on Marks.StudentId = Student.Id"));
            SqlQueryPlan.ExtractDataFromXml(doc.Descendants(ns + "QueryPlan").First().ToString(), ref root);

            string toWrite = "";
            SqlQueryPlan.SerilizeTree(ref root, ref toWrite);

            System.IO.File.WriteAllText("query.txt", toWrite);

            new Thread(() =>
            {
                OpenGl.DisplayVisualization();
            }).Start();
        }
    }

    class OpenGl
    {
        [DllImport("MyWrapper.dll", CallingConvention = CallingConvention.Cdecl)]

        public static extern void DisplayVisualization();
    }
}
