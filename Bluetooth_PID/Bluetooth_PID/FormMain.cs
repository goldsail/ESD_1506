using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bluetooth_PID
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
            PortChat.SetPortName(label);
            buttonSend.Enabled = false;
            
        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            try
            {
                PortChat.Initialize(textBoxCom.Text);
                buttonSend.Enabled = true;
                buttonConnect.Enabled = false;
            }
            catch (Exception)
            {
                MessageBox.Show("连接失败");
            }
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            string[] paras = new string[]
            {
                textBox1.Text,
                textBox2.Text,
                textBox3.Text,
                textBox4.Text,
                textBox5.Text,
                textBox6.Text,
                textBox7.Text,
                textBox8.Text,
                textBox9.Text,
                textBox10.Text,
            };

            float tempF = 0;
            int tempD = 0;
            
            if (!float.TryParse(paras[0], out tempF))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!float.TryParse(paras[1], out tempF))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!float.TryParse(paras[2], out tempF))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!float.TryParse(paras[3], out tempF))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!float.TryParse(paras[4], out tempF))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!float.TryParse(paras[5], out tempF))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!float.TryParse(paras[6], out tempF))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!int.TryParse(paras[7], out tempD))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!int.TryParse(paras[8], out tempD))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            if (!float.TryParse(paras[9], out tempF))
            {
                MessageBox.Show("参数不合法");
                return;
            }

            string ret = "";

            for (int i =0; i < 10; i++)
            {
                if (i > 0)
                {
                    ret += " ";
                }
                ret += paras[i];
            }

            try
            {
                PortChat.SendRawString(ret);
            }
            catch (Exception)
            {
                MessageBox.Show("发送失败");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
