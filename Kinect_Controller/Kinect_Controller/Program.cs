using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Kinect;
using Microsoft.Kinect.Input;
using System.Threading.Tasks;
using System.IO.Ports;

namespace Kinect_Controller
{
    class Program
    {

        static private bool _terminate = false;

        static void Main(string[] args)
        {
            PortChat.Initialize();

            // 控制台背景色  
            Console.ForegroundColor = ConsoleColor.DarkGreen;

            // 获得传感器  
            KinectSensor kinectSensor = KinectSensor.GetDefault();

            BodyFrameReader bodyFrameSource = kinectSensor.BodyFrameSource.OpenReader();
            // 帧到达  
            bodyFrameSource.FrameArrived += bodyFrameReader_FrameArrived;

            // 开帧描述  
            FrameDescription depthFrameDescription = kinectSensor.DepthFrameSource.FrameDescription;
            
            kinectSensor.Open();
            while (Console.ReadKey().Key != ConsoleKey.Enter)
            {
                if (_terminate)
                {
                    return;
                }
            }
            kinectSensor.Close();
        }

        static void bodyFrameReader_FrameArrived(object sender, BodyFrameArrivedEventArgs e)
        {
            try
            {


                using (BodyFrame bf = e.FrameReference.AcquireFrame())
                {

                    if (bf != null)
                    {
                        Body[] bodies = new Body[bf.BodyCount];
                        bf.GetAndRefreshBodyData(bodies);

                        foreach (Body body in bodies)
                        {
                            if (body != null)
                            {
                                if (body.HandRightState == HandState.Open && body.HandRightConfidence == TrackingConfidence.High)
                                {
                                    Joint handRight = body.Joints[JointType.HandRight];
                                    if (body.HandLeftState == HandState.Closed && body.HandLeftConfidence == TrackingConfidence.High)
                                    {
                                        // rotation mode
                                        float rotationSpeed = handRight.Position.X;
                                        PortChat.SendRawString($"R {(int)(1000 * rotationSpeed)}");
                                    }
                                    else
                                    {
                                        // displacement mode
                                        PortChat.SendRawString($"D {(int)(1000 * handRight.Position.X)} {(int)(1000 * handRight.Position.Y)} {(int)(1000 * handRight.Position.Z)}");
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            catch (PortChat.PortDisconnectException)
            {
                Console.WriteLine("serial port disconnected");
                _terminate = true;
            }
        }
    }
}