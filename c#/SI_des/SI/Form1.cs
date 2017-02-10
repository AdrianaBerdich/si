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

namespace SI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            DESCryptoServiceProvider mydes = new DESCryptoServiceProvider();
            mydes.Key = ASCIIEncoding.ASCII.GetBytes("12345678");
            mydes.IV = ASCIIEncoding.ASCII.GetBytes("12345678");
            ICryptoTransform enc = mydes.CreateEncryptor(mydes.Key, mydes.IV);
            FileStream filein = new FileStream("text.txt", FileMode.Open, FileAccess.Read);
            FileStream fileout = new FileStream("enc.txt", FileMode.Open, FileAccess.Write);
            CryptoStream cs = new CryptoStream(fileout, enc, CryptoStreamMode.Write);
            byte[] crypttext = new byte[filein.Length];
            filein.Read(crypttext, 0, crypttext.Length);
            cs.Write(crypttext, 0, crypttext.Length);
            cs.Close();
            filein.Close();
            fileout.Close();

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
