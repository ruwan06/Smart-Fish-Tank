using System;
using System.Windows;
using LiveCharts;
using LiveCharts.Wpf;

namespace WpfApp1
{
    public partial class MainWindow : Window
    {
        public SeriesCollection SeriesCollection { get; set; }
        public string[] Labels { get; set; }
        public Func<double, string> YFormatter { get; set; }

        public MainWindow()
        {
            InitializeComponent();

            SeriesCollection = new SeriesCollection
            {
                new LineSeries
                {
                    Title = "My Series",
                    // Change the type of the Y-axis values to int
                    Values = new ChartValues<int> { 1,2,3,4,5,10,15,20 }
                }
            };

            Labels = new[] { "1","2","3","4","5","6","7","8","9","10" };
            YFormatter = value => value.ToString("C");

            DataContext = this;
        }
    }
}
