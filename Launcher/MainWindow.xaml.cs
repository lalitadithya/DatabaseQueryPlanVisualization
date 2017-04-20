using System.Collections.Generic;
using System.Data.SqlClient;
using System.Runtime.InteropServices;
using System.Text;
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
            List<string> node = new List<string>();
            List<int> nodeLength = new List<int>();

            XmlDocument doc = new XmlDocument();
            doc.LoadXml(SqlQueryPlan.GetXmlPlanForQuery("select * from Student order by Semester"));

            XmlNodeList nodes = doc.GetElementsByTagName("RelOp");

            for(int i = 0; i <nodes.Count; i++)
            {
                node.Add(nodes[i].Attributes["PhysicalOp"].Value);
                nodeLength.Add(nodes[i].Attributes["PhysicalOp"].Value.Length);
            }

            new Thread(() => {
                int temp = nodeLength.ToArray().Length;
                OpenGl.DisplayVisualization(node.ToArray(), temp);
            }).Start();
        }
    }

    class OpenGl
    {
        [DllImport("MyWrapper.dll", CallingConvention = CallingConvention.Cdecl)]

        public static extern void DisplayVisualization(string[] queryPlan, int numberOfElements);
    }
}
