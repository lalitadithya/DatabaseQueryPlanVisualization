using System.Runtime.InteropServices;
using System.Threading;
using System.Windows;

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
            new Thread(() => { OpenGl.DisplayHelloFromDLL(); }).Start();
        }
    }

    class OpenGl
    {
        [DllImport("MyWrapper.dll")]

        public static extern void DisplayHelloFromDLL();
    }
}
