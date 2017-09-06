using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

using System.Windows.Forms;

using System.IO.Ports;

namespace Bluetooth_PID
{
    public static class PortChat
    {
        public static void Initialize(string portName)
        {
            StringComparer stringComparer = StringComparer.OrdinalIgnoreCase;

            // Create a new SerialPort object with default settings.
            _serialPort = new SerialPort();

            // Allow the user to set the appropriate properties.
            _serialPort.PortName = portName;
            // _serialPort.PortName = "COM2";
            _serialPort.BaudRate = 9600;
            _serialPort.Parity = Parity.None;
            _serialPort.DataBits = 8;
            _serialPort.StopBits = StopBits.One;
            _serialPort.Handshake = Handshake.None;
            

            // Set the read/write timeouts
            _serialPort.ReadTimeout = 1000;
            _serialPort.WriteTimeout = 1000;

            Console.WriteLine("waiting for serial port to open");
            while (true)
            {
                try
                {
                    _serialPort.Open();
                    break;
                }
                catch (System.IO.IOException)
                {
                    Console.WriteLine("serial port not connected");
                    Thread.Sleep(1000);
                }
            }
            Console.WriteLine("serial port connected");
        }
        
        static SerialPort _serialPort;

        public class PortDisconnectException : Exception
        {

        }

        public static void SendRawString(string rawString)
        {
            try
            {
                _serialPort.WriteLine(rawString);
                Console.WriteLine(rawString);
            }
            catch (Exception)
            {
                _serialPort.Close();
                throw new PortDisconnectException();
            }
        }

        // Display Port values and prompt user to enter a port.
        public static void SetPortName(Label label)
        {
            string portName = "Available Ports:";
            
            foreach (string s in SerialPort.GetPortNames())
            {
                portName += ("  " + s);
            }


            if (portName == "" && !(portName.ToLower()).StartsWith("com"))
            {
                portName = "未找到COM端口";
            }


            label.Text = portName;
        }
        
    }
}
