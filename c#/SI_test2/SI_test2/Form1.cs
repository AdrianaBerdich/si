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
using System.Xml;

namespace SI_test2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

           // RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(4096);
          //  var publickey = "<RSAKeyValue><Modulus>21wEnTU+mcD2w0Lfo1Gv4rtcSWsQJQTNa6gio05AOkV/Er9w3Y13Ddo5wGtjJ19402S71HUeN0vbKILLJdRSES5MHSdJPSVrOqdrll/vLXxDxWs/U0UT1c8u6k/Ogx9hTtZxYwoeYqdhDblof3E75d9n2F0Zvf6iTb4cI7j6fMs=</Modulus><Exponent>AQAB</Exponent><P>/aULPE6jd5IkwtWXmReyMUhmI/nfwfkQSyl7tsg2PKdpcxk4mpPZUdEQhHQLvE84w2DhTyYkPHCtq/mMKE3MHw==</P><Q>3WV46X9Arg2l9cxb67KVlNVXyCqc/w+LWt/tbhLJvV2xCF/0rWKPsBJ9MC6cquaqNPxWWEav8RAVbmmGrJt51Q==</Q><DP>8TuZFgBMpBoQcGUoS2goB4st6aVq1FcG0hVgHhUI0GMAfYFNPmbDV3cY2IBt8Oj/uYJYhyhlaj5YTqmGTYbATQ==</DP><DQ>FIoVbZQgrAUYIHWVEYi/187zFd7eMct/Yi7kGBImJStMATrluDAspGkStCWe4zwDDmdam1XzfKnBUzz3AYxrAQ==</DQ><InverseQ>QPU3Tmt8nznSgYZ+5jUo9E0SfjiTu435ihANiHqqjasaUNvOHKumqzuBZ8NRtkUhS6dsOEb8A2ODvy7KswUxyA==</InverseQ><D>cgoRoAUpSVfHMdYXW9nA3dfX75dIamZnwPtFHq80ttagbIe4ToYYCcyUz5NElhiNQSESgS5uCgNWqWXt5PnPu4XmCXx6utco1UVH8HGLahzbAnSy6Cj3iUIQ7Gj+9gQ7PkC434HTtHazmxVgIR5l56ZjoQ8yGNCPZnsdYEmhJWk=</D></RSAKeyValue>";
            //myRSA.FromXmlString(true);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
      

        private void button1_Click(object sender, EventArgs e)
        {
            RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(4096);
            AesManaged myAES = new AesManaged();
            RSAParameters myRSAp = new RSAParameters();

           

            byte[] RSAciphertext;
            byte[] plaintext;
            string key;
            int count = 100;
            long time_start = DateTime.Now.Ticks;
            //generate an AES key
            for (int i = 0; i < count; i++)
            {
                File.WriteAllText(@"D:\\Facultate\\si.xml", myRSA.ToXmlString(true));
                File.WriteAllText(@"D:\\Facultate\\si1.xml", myRSA.ToXmlString(false)); 
                 
            }
            long opp_time = DateTime.Now.Ticks - time_start;
            opp_time = opp_time / (count * 10);
            textBox1.Text = opp_time.ToString() + "ms";

            //string publicPrivateKeyXML = myRSA.ToXmlString(true);
            //string publicOnlyKeyXML = myRSA.ToXmlString(false);
          //  FileStream fs = new FileStream("C:/Users/User/Documents/Visual Studio 2013/Projects/SI_test2/SI_test2/key.xml", FileMode.Create, FileAccess.Write);
           // StreamWriter sw = new StreamWriter("D:\\Facultate\\si.xml");
            //sw.Write(myRSA.ToXmlString(true));
            //textBox1.Text = Convert.ToBase64String(myRSAp.Modulus);
         //   string xml = myRSA.FromXmlString(true);
           

            }

        private void button2_Click(object sender, EventArgs e)
        {
            CspParameters cp = new CspParameters();
            RSACryptoServiceProvider rsa = new RSACryptoServiceProvider(4096, cp);

            File.WriteAllText(@"D:\\Facultate\\si.xml", rsa.ToXmlString(true));
            File.WriteAllText(@"D:\\Facultate\\si1.xml", rsa.ToXmlString(false));

            XmlDocument xmlDoc = new XmlDocument();
            //true is for retrieve both the public and private RSA key
            xmlDoc.InnerXml = rsa.ToXmlString(true);
            xmlDoc.InnerXml = rsa.ToXmlString(false);

            XmlNodeList xmlPublicModulus = xmlDoc.GetElementsByTagName("Modulus");
            XmlNodeList xmlPublicExp = xmlDoc.GetElementsByTagName("Exponent");
        }
    }
}
