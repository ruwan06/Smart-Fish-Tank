using System;
using LiveCharts.Wpf;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO.Ports;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Diagnostics;
using System.Threading;

namespace Smart_Tank
{
    /// <summary>
    /// Interaction      for MainWindow.xaml
    /// </summary>

    public partial class MainWindow : Window
    {
        public delegate void d1(string indata);
        SerialPort sp = new SerialPort();
        private string MyPort = "COM10";
        bool n = false, o = false, p = false, q = false, r = false;

        public ObservableCollection<double> Values { get; set; }
        public MainWindow()
        {
            InitializeComponent();
            SetupSerialPort();
            scanAndConn();
            Values = new ObservableCollection<double> { 1, 4, 6, 8, 2 };
            DataContext = this;
        }

        private void scanAndConn()
        {
            //scan Port
            //string[] portNames= SerialPort.GetPortNames();
            

            //connect port
            sp.BaudRate = 9600;
            //sp.ReadTimeout = 2000;
            sp.PortName = MyPort;
            sp.Open();
        }
        private void SetupSerialPort()
        {
            // Set up event handler for DataReceived
            sp.DataReceived += Sp_DataReceived;
        }

        private void Sp_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string indata = sp.ReadLine();
            d1 writeit = new d1(getData);
            Dispatcher.Invoke(writeit, indata);
        }
        public void getData(string indata="n:1")
        {
            try
            {
                string[] recive=indata.Split(' ');
                textBox.Text = indata;

                foreach (string item in recive)
                {
                    string rKey = item.Trim().Split(':')[0].Trim();
                    string rValue = item.Trim().Split(':')[1].Trim();

                    switch (rKey)
                    {
                        case "a":
                            bdrWaterLevel.Height=50 + (Convert.ToInt16(rValue) * 2);
                            break;
                        case "b":
                            //oxygen chart
                            break;
                        case "c":
                            //Hardness chart
                            break;
                        case "d":
                            //Temperature chart
                            break;
                        case "e":
                            //PH chart
                            break;
                        case "n":
                            bool cvtValue_n= Convert.ToBoolean(int.Parse(rValue));
                            if (n!= cvtValue_n)
                            {
                                n = cvtValue_n;
                                if (rValue.Trim() == "1") { valveInOpen(); }
                                else if (rValue.Trim() == "0") { valveInClose(); }
                            }
                            break;
                        case "o":
                            bool cvtValue_o = Convert.ToBoolean(int.Parse(rValue));
                            if (o != cvtValue_o)
                            {
                                o = cvtValue_o;
                                if (rValue.Trim() == "1") { valveOutOpen(); }
                                else if (rValue.Trim() == "0") { valveOutClose(); }
                            }
                            break;
                        case "p":
                            bool cvtValue_p = Convert.ToBoolean(int.Parse(rValue));
                            if (p != cvtValue_p)
                            {
                                p = cvtValue_p;
                                if (rValue.Trim() == "1") { OxygenMotorOn(); }
                                else if (rValue.Trim() == "0") { OxygenMotorOff(); }
                            }
                            break;
                        case "q":
                            bool cvtValue_q = Convert.ToBoolean(int.Parse(rValue));
                            if (q != cvtValue_q)
                            {
                                q = cvtValue_q;
                                if (rValue.Trim() == "1") { lightOn(); }
                                else if (rValue.Trim() == "0") { lightOff(); }
                            }
                            break;
                        case "r":
                            bool cvtValue_r = Convert.ToBoolean(int.Parse(rValue));
                            if (r != cvtValue_r)
                            {
                                r = cvtValue_r;
                                if (rValue.Trim() == "1") { filterOn(); }
                                else if (rValue.Trim() == "0") { filterOff(); }
                            }
                            break;
                    }
                }
            }
            catch (Exception e)
            {
                //MessageBox.Show(e.Message);
            }
        }
        private void valveInOpen()
        {
            imgWaterIn.Visibility = Visibility.Visible;
            tglValveIn.IsChecked = true;
            sp.WriteLine("A:1");
        }

        private void valveInClose()
        {
            imgWaterIn.Visibility = Visibility.Collapsed;
            tglValveIn.IsChecked = false;
            sp.WriteLine("A:0");
        }

        private void valveOutOpen()
        {
            imgWaterOut.Visibility = Visibility.Visible;
            tglValveOut.IsChecked = true;
            sp.WriteLine("B:1");
        }

        private void OxygenMotorOn()
        {
            imgOxygenBubble.Visibility = Visibility.Visible;
            tglOxygenMotor.IsChecked = true;
            sp.WriteLine("C:1");
        }
        private void OxygenMotorOff()
        {
            imgOxygenBubble.Visibility = Visibility.Collapsed;
            tglOxygenMotor.IsChecked = false;
            sp.WriteLine("C:0");
        }

        private void lightOn()
        {
            imgLight.Visibility = Visibility.Visible;
            tglLight.IsChecked = true;
            sp.WriteLine("D:1");
        }
        private void lightOff()
        {
            imgLight.Visibility = Visibility.Collapsed;
            tglLight.IsChecked = false;
            sp.WriteLine("D:0");
        }

        private void filterOn() 
        {
            tglWaterFilter.IsChecked = true;
            sp.WriteLine("E:1");
        }

        private void filterOff()
        {
            tglWaterFilter.IsChecked = false;
            sp.WriteLine("E:0");
        }

        private void valveOutClose()
        {
            imgWaterOut.Visibility = Visibility.Collapsed;
            tglValveOut.IsChecked = false;
            sp.WriteLine("B:0");
        }

        private void tglOxygenMotor_Click(object sender, RoutedEventArgs e)
        {
            if (tglOxygenMotor.IsChecked == true) { OxygenMotorOn(); }
            else { OxygenMotorOff(); }
        }

        private void tglValveIn_Click(object sender, RoutedEventArgs e)
        {
            if (tglValveIn.IsChecked == true) { valveInOpen(); }
            else { valveInClose(); }
        }

        private void button_Click_1(object sender, RoutedEventArgs e)
        {
            Values = new ObservableCollection<double> { 0.1,0.5,0.3,0.4 };
        }

        private void tglValveOut_Click(object sender, RoutedEventArgs e)
        {
            if (tglValveOut.IsChecked == true) { valveOutOpen(); }
            else { valveOutClose(); }
        }

        private void tglLight_Click(object sender, RoutedEventArgs e)
        {
            if (tglLight.IsChecked == true) { lightOn(); }
            else { lightOff(); }
        }

        private void tglWaterFilter_Click(object sender, RoutedEventArgs e)
        {
            if (tglWaterFilter.IsChecked == true) { filterOn(); }
            else { filterOff(); }
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            bool n = true;
            n = Convert.ToBoolean(int.Parse("0"));
            MessageBox.Show("n=" + n.ToString());
        }
    }

    public class MeasureModel
    {
        public double ElapsedMilliseconds { get; set; }
        public double Value { get; set; }
    }
}
