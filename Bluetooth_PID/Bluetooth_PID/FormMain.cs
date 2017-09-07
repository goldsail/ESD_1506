using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Microsoft.Kinect;


namespace Bluetooth_PID
{
    public partial class FormMain : Form
    {
        private bool isKinectMode = false;

        private KinectSensor kinectSensor = null;

        public FormMain()
        {
            InitializeComponent();
            PortChat.SetPortName(label);
            buttonSend.Enabled = false;
            buttonMode.Enabled = false;

        }

        public void kinectFrameReader_FrameArrived(object sender, BodyFrameArrivedEventArgs e)
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
                                if (body.IsTracked)
                                {
                                    Joint handRight = body.Joints[JointType.WristRight];
                                    Joint handLeft = body.Joints[JointType.WristLeft];

                                    if (handLeft.Position.Y > handRight.Position.Y)
                                    {

                                        int temp = (int)((handRight.Position.Z - 0.8) * 200 - 40);

                                        temp = Math.Min(Math.Max(temp, -70), -10);

                                        string str = $" {temp}";

                                        PortChat.SendRawString(str);

                                        labelJustSent.Text = str;

                                        break;
                                    }

                                }
                            }
                        }
                    }
                }
            }
            catch (PortChat.PortDisconnectException)
            {
                Console.WriteLine("serial port disconnected");
            }
        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            try
            {
                PortChat.Initialize(textBoxCom.Text);
                buttonSend.Enabled = true;
                buttonMode.Enabled = true;
                buttonConnect.Enabled = false;
            }
            catch (Exception)
            {
                MessageBox.Show("连接失败");
            }
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            int val = (int)numericUpDown.Value;
            
            if (val < -200 || val > 200)
            {
                MessageBox.Show("参数不合法");
                return;
            }

            string ret = " " + val.ToString();

            try
            {
                PortChat.SendRawString(ret);
                labelJustSent.Text = ret;
            }
            catch (Exception)
            {
                MessageBox.Show("发送失败");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void buttonMode_Click(object sender, EventArgs e)
        {
            if (isKinectMode)
            {
                buttonSend.Enabled = true;
                isKinectMode = false;
                kinectSensor.BodyFrameSource.OpenReader().FrameArrived -= kinectFrameReader_FrameArrived;
                labelMode.Text = "当前：Bluetooth模式";
            }
            else
            {
                buttonSend.Enabled = false;
                isKinectMode = true;
                kinectSensor = KinectSensor.GetDefault();
                kinectSensor.BodyFrameSource.OpenReader().FrameArrived += kinectFrameReader_FrameArrived;
                labelMode.Text = "当前：Kinect模式";
                kinectSensor.Open();
            }
        }
    }
}
