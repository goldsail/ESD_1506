using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

using System.IO.Ports;

namespace Kinect_Controller
{
    public static class PortChat
    {
        public static void Initialize()
        {
            StringComparer stringComparer = StringComparer.OrdinalIgnoreCase;

            // Create a new SerialPort object with default settings.
            _serialPort = new SerialPort();

            // Allow the user to set the appropriate properties.
            _serialPort.PortName = SetPortName(_serialPort.PortName);
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
        private static string SetPortName(string defaultPortName)
        {
            string portName;

            Console.WriteLine("Available Ports:");
            foreach (string s in SerialPort.GetPortNames())
            {
                Console.WriteLine("   {0}", s);
            }

            Console.Write("Enter COM port value (Default: {0}): ", defaultPortName);
            portName = Console.ReadLine();

            if (portName == "" || !(portName.ToLower()).StartsWith("com"))
            {
                portName = defaultPortName;
            }
            return portName;
        }
        
    }
}
