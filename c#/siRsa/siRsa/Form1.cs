using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Security.Cryptography;

namespace siRsa
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(Convert.ToInt32(comboBox1.Text));
            AesManaged myAES = new AesManaged();
            byte[] RSAciphertext;
            byte[] plaintext;

            long start_time = DateTime.Now.Ticks;
            int count = 10000;
            for (int i = 0; i < count; i++)
            {
                myAES.GenerateKey();
            }
            double opp_time = DateTime.Now.Ticks - start_time;
            opp_time = opp_time / (10 * count);
            if (Convert.ToInt32(comboBox1.Text) == 1024)
                textBox1.Text = opp_time.ToString() + "ms";
            else
                if (Convert.ToInt32(comboBox1.Text) == 2048)
                    textBox2.Text = opp_time.ToString() + "ms";
                else
                    if (Convert.ToInt32(comboBox1.Text) == 3072)
                        textBox3.Text = opp_time.ToString() + "ms";
                    else
                            textBox4.Text = opp_time.ToString() + "ms";
        }

        private void button2_Click(object sender, EventArgs e)
        {

            RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(Convert.ToInt32(comboBox1.Text));
            AesManaged myAES = new AesManaged();
            byte[] RSAciphertext;
            byte[] plaintext;

            long start_time = DateTime.Now.Ticks;
            int count = 10000;
            for (int i = 0; i < count; i++)
            {
                RSAciphertext = myRSA.Encrypt(myAES.Key, true);
            }
            double opp_time = DateTime.Now.Ticks - start_time;
            opp_time = opp_time / (10 * count);
            if (Convert.ToInt32(comboBox1.Text) == 1024)
                textBox1.Text = opp_time.ToString() + "ms";
            else
                if (Convert.ToInt32(comboBox1.Text) == 2048)
                    textBox2.Text = opp_time.ToString() + "ms";
                else
                    if (Convert.ToInt32(comboBox1.Text) == 3072)
                        textBox3.Text = opp_time.ToString() + "ms";
                    else
                        textBox4.Text = opp_time.ToString() + "ms";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            
            RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(Convert.ToInt32(comboBox1.Text));
            AesManaged myAES = new AesManaged();
            byte[] RSAciphertext;
            byte[] plaintext;

            long start_time = DateTime.Now.Ticks;
            int count = 10000;
            for (int i = 0; i < count; i++)
            {
                RSAciphertext = myRSA.Encrypt(myAES.Key, true);
                plaintext = myRSA.Decrypt(RSAciphertext, true);


            }
            double opp_time = DateTime.Now.Ticks - start_time;
            opp_time = opp_time / (10 * count);
            if (Convert.ToInt32(comboBox1.Text) == 1024)
                textBox1.Text = opp_time.ToString() + "ms";
            else
                if (Convert.ToInt32(comboBox1.Text) == 2048)
                    textBox2.Text = opp_time.ToString() + "ms";
                else
                    if (Convert.ToInt32(comboBox1.Text) == 3072)
                        textBox3.Text = opp_time.ToString() + "ms";
                    else
                        textBox4.Text = opp_time.ToString() + "ms";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(Convert.ToInt32(comboBox1.Text));
            AesManaged myAES = new AesManaged();
            SHA256Managed myHash = new SHA256Managed();
            string some_text = "this is an important message";
            //sign the message
            byte[] signature;

            long start_time = DateTime.Now.Ticks;
            int count = 10000;
            for (int i = 0; i < count; i++)
            {
                signature = myRSA.SignData(System.Text.Encoding.ASCII.GetBytes(some_text), myHash);

            }
            double opp_time = DateTime.Now.Ticks - start_time;
            opp_time = opp_time / (10 * count);
            if (Convert.ToInt32(comboBox1.Text) == 1024)
                textBox1.Text = opp_time.ToString() + "ms";
            else
                if (Convert.ToInt32(comboBox1.Text) == 2048)
                    textBox2.Text = opp_time.ToString() + "ms";
                else
                    if (Convert.ToInt32(comboBox1.Text) == 3072)
                        textBox3.Text = opp_time.ToString() + "ms";
                    else
                        textBox4.Text = opp_time.ToString() + "ms";

        }

        private void button5_Click(object sender, EventArgs e)
        {
            RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(Convert.ToInt32(comboBox1.Text));
            AesManaged myAES = new AesManaged();
            SHA256Managed myHash = new SHA256Managed();
            string some_text = "this is an important message";
            //sign the message
            byte[] signature = myRSA.SignData(System.Text.Encoding.ASCII.GetBytes(some_text), myHash);;

            long start_time = DateTime.Now.Ticks;
            int count = 10000;
            bool verified;
            for (int i = 0; i < count; i++)
            {
                verified = myRSA.VerifyData(System.Text.Encoding.ASCII.GetBytes(some_text),myHash, signature);

            }
            double opp_time = DateTime.Now.Ticks - start_time;
            opp_time = opp_time / (10 * count);
            if (Convert.ToInt32(comboBox1.Text) == 1024)
                textBox1.Text = opp_time.ToString() + "ms";
            else
                if (Convert.ToInt32(comboBox1.Text) == 2048)
                    textBox2.Text = opp_time.ToString() + "ms";
                else
                    if (Convert.ToInt32(comboBox1.Text) == 3072)
                        textBox3.Text = opp_time.ToString() + "ms";
                    else
                        textBox4.Text = opp_time.ToString() + "ms";

        }
    }
}
