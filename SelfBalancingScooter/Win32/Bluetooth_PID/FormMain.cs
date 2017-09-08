using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
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

            this.KeyDown += formMain_KeyDown;


            numericUpDown.Maximum = (decimal)biasMax;
            numericUpDown.Minimum = (decimal)biasMin;
            numericUpDown.Value = (decimal)biasDefault;

            label1.Text = "bias (" + biasMin.ToString() + " ~ " + biasMax.ToString() + ")";


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
                                        int temp = (int)((handRight.Position.Z - 1.6) * 40 + biasDefault);

                                        temp = Math.Min(Math.Max(temp, biasMin), biasMax);

                                        string str = $"    {temp}";


                                        labelJustSent.Text = str;

                                        PortChat.SendRawString(str);


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
            
            if (val < -70 || val > -10)
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

        private void numericUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (buttonSend.Enabled)
            {
                buttonSend_Click(null, null);
            }
        }

        private int biasMin = -82;
        private int biasMax = -2;
        private int biasDefault = -42;

        private int moveBias = 15;

        private void buttonForward_Click(object sender, EventArgs e)
        {
            int val = (int)numericUpDown.Value;

            numericUpDown.Value = val + moveBias;
            Thread.Sleep(1500);

            numericUpDown.Value = val;
            Thread.Sleep(500);
        }

        private void buttonBackward_Click(object sender, EventArgs e)
        {
            int val = (int)numericUpDown.Value;

            numericUpDown.Value = val - moveBias;
            Thread.Sleep(1500);

            numericUpDown.Value = val;
            Thread.Sleep(500);
        }

        private void formMain_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Up:
                    buttonForward_Click(null, null);
                    break;
                case Keys.Down:
                    buttonBackward_Click(null, null);
                    break;
                default:
                    break;
            }
        }
    }
}
