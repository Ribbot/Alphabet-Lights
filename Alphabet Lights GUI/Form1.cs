using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Alphabet_Lights_GUI
{
    public partial class Form1 : Form
    {
        static SerialPort serialPort;
        Color color1 = Color.Fuchsia, color2 = Color.Cyan, color3 = Color.Green; // Initialize colors with default values


        public Form1()
        {
            InitializeComponent();

            serialPort = new SerialPort("COM7", 9600); //Initialize serial communication with Arduino over USB

            updateColors();
        }


        private void On_Click(object sender, EventArgs e)
        {
            serialPort.Open();
            serialPort.WriteLine("1"); //Send "On" command
            serialPort.Close();
        }


        private void Off_Click(object sender, EventArgs e)
        {
            serialPort.Open();
            serialPort.WriteLine("2"); //Send "Off" command
            serialPort.Close();
        }


        private void Choose_Color1_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                color1 = colorDialog1.Color; //Change color1 to color selected by user
                updateColors();
            }
        }


        private void Choose_Color2_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                color2 = colorDialog1.Color; //Change color2 to color selected by user
                updateColors();
            }
        }

        private void Choose_Color3_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                color3 = colorDialog1.Color; //Change color3 to color selected by user
                updateColors();
            }
        }

        private void updateColors()
        {
            // Change each button background to match its selected color
            button3.BackColor = color1;
            button4.BackColor = color2;
            button5.BackColor = color3;

            serialPort.Open();
            serialPort.WriteLine("3 " + color1.R + " " + color1.G + " " + color1.B + " " + color2.R + " " + color2.G + " " + color2.B + " " + color3.R + " " + color3.G + " " + color3.B); //Send color selection command
            serialPort.Close();
        }

        private void Phrase_Click(object sender, EventArgs e)
        {
            string phrase = textBox1.Text;

            serialPort.Open();
            serialPort.WriteLine("4 " + phrase); //Send phrase command
            serialPort.Close();
        }
    }
}
