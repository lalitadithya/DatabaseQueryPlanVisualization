using System.Data.SqlClient;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows;
using System.Xml;

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
            string nodeToDisplay = "";

            XmlDocument doc = new XmlDocument();
            doc.LoadXml(SqlQueryPlan.GetXmlPlanForQuery("select * from Student order by Semester"));

            XmlNodeList nodes = doc.GetElementsByTagName("RelOp");

            for(int i = 0; i <nodes.Count; i++)
            {
                nodeToDisplay += nodes[i].Attributes["PhysicalOp"].Value + "\n";
            }

            //new Thread(() => { OpenGl.DisplayHelloFromDLL(); }).Start();
        }
    }

    class OpenGl
    {
        [DllImport("MyWrapper.dll")]

        public static extern void DisplayHelloFromDLL();
    }
}
