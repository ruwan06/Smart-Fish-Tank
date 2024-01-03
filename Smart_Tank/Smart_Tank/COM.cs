using System;
using System.IO.Ports;
using System.Windows.Controls;

namespace Smart_Tank
{
    public class COM
    {
        private SerialPort sp = new SerialPort();
        private string[] portNames;
        private string MyPort = "COM10";
        private TextBlock textBlock; // Add a reference to the TextBlock
        private Border waterLevel;

        public COM(MainWindow wid) // Pass the TextBlock as a parameter to the constructor
        {
            //this.textBlock = wid.textBlock; // Assign the TextBlock reference
            this.waterLevel = wid.bdrWaterLevel;

            this.sp.BaudRate = 9600;
            sp.PortName = MyPort;
            sp.Open();

            // Subscribe to the DataReceived event
            sp.DataReceived += Sp_DataReceived;
        }


        public string[] AllCOM()
        {
            portNames = SerialPort.GetPortNames();
            return portNames;
        }

        // Event handler for DataReceived event
        private void Sp_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            // Handle the received data here
            // You can access the received data using the ReadExisting or ReadLine methods
            string receivedData = sp.ReadExisting();

            // Example: Display received data in textBlock
            UpdateTextBlock(receivedData);
        }

        // Method to update the TextBlock with received data
        private void UpdateTextBlock(string data)
        {
            // Ensure the UI update runs on the UI thread
            textBlock.Dispatcher.Invoke(() =>
            {
                // Append the received data to the existing text

                textBlock.Text += data;
            });
        }
    }
}
