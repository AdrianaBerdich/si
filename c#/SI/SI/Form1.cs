using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;
using System.Security.Cryptography;
using System.Security;


namespace SI
{
    public partial class Form1 : Form
    {
        SymmetricAlgorithm mySymmetricAlg ;
        ConversionHandler myConverter = new ConversionHandler();
        public Form1()
        {
            InitializeComponent();

            serialPort1.PortName = "COM3";
            serialPort1.BaudRate = 9600;
            serialPort1.Open();
            serialPort1.DataReceived += new SerialDataReceivedEventHandler(serialPort1_DataReceived);

           

        }
        public void Generate()
        {
            mySymmetricAlg = Rijndael.Create();
            mySymmetricAlg.GenerateIV();


        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string data = sp.ReadLine();
           // string[] date = data.Split(' ');
            if (data != String.Empty)
            {
                 Invoke(new Action(() =>textDataEnc.Clear()));
                 Invoke(new Action(() => textDataEnc.AppendText(data)));
                //Invoke(new Action(() => Decrypt_Received_Data())); 
  
            }
        }

     public byte[] Decrypt(byte[] mess, byte[] key, byte[] iv)
        {
            byte[] plaintext = new byte[mess.Length];
            mySymmetricAlg.Key = key;
            mySymmetricAlg.IV = iv;
            mySymmetricAlg.Padding = PaddingMode.None;
            MemoryStream ms = new MemoryStream(mess);
            CryptoStream cs = new CryptoStream(ms,
            mySymmetricAlg.CreateDecryptor(),
            CryptoStreamMode.Read);
            cs.Read(plaintext, 0, mess.Length);
            cs.Close();
            return plaintext;
        }
     void Decrypt_cbc()
     {
         Generate();
         textBox4.Text = myConverter.ByteArrayToHexString(mySymmetricAlg.Key);
         textBox1.Text = myConverter.ByteArrayToHexString(mySymmetricAlg.IV);
         mySymmetricAlg.Key = new byte[] {
                0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
            };
         mySymmetricAlg.IV = new byte[] {
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            };

        // byte[] plaintext = Decrypt(myConverter.HexStringToByteArray(textDataEnc.Text), myConverter.HexStringToByteArray(textBox4.Text), myConverter.HexStringToByteArray(textBox1.Text));
         byte[] plaintext = Decrypt(myConverter.HexStringToByteArray(textDataEnc.Text), myConverter.HexStringToByteArray("000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F"), myConverter.HexStringToByteArray("101112131415161718191A1B1C1D1E1F"));
         //textBoxDec.Text = plaintext;
         textBoxDec.Text = myConverter.ByteArrayToString(plaintext);
         // textBoxPlainHex.Text = myConverter.ByteArrayToHexString(plaintext);
     }

        void Decrypt_Received_Data_ECB()
        {
            Aes aes = Aes.Create();
            aes.Key = new byte[] {
                0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
            };
            // aes.GenerateIV();
            //aes.IV = new byte[] {
            //    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            //};
            aes.Mode = CipherMode.ECB;
            aes.Padding = PaddingMode.None;
            ICryptoTransform decrypter = aes.CreateDecryptor();

            byte[] buffer = myConverter.HexStringToByteArray(textDataEnc.Text);


            buffer = decrypter.TransformFinalBlock(buffer, 0, buffer.Length);
            textBoxDec.Text = ASCIIEncoding.ASCII.GetString(buffer);
        }

        void Decrypt_counter_mode()
        {
            Aes256CounterMode myaes;
            ICryptoTransform ict;
            myaes = new Aes256CounterMode(myConverter.HexStringToByteArray("00000000000000000000000000000000"));
            ict = myaes.CreateDecryptor(myConverter.HexStringToByteArray("000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F"), null);
            // byte[] input = myConverter.HexStringToByteArray ( "ana are mere");
            // byte[] result;
            //// ict.TransformBlock(input, 0, input.Length, 0);
            // input = ict.TransformFinalBlock(input, 0, input.Length);
            // textBox1.Text = myConverter.ByteArrayToHexString(input);

            byte[] buffer = myConverter.HexStringToByteArray(textDataEnc.Text);


            buffer = ict.TransformFinalBlock(buffer, 0, buffer.Length);
            textBoxDec.Text = ASCIIEncoding.ASCII.GetString(buffer);

           // Chilkat.Crypt2 crypt = new Chilkat.Crypt2();

           // bool success = crypt.UnlockComponent("Anything for 30-day trial");
           // if (success != true)
           // {
           //     textKey.Text = crypt.LastErrorText;
           //     return;
           // }

           // //  AES is also known as Rijndael.
           // crypt.CryptAlgorithm = "aes";

           // //  CipherMode may be "ctr", "cfb", "ecb" or "cbc"
           // crypt.CipherMode = "ctr";

           // //  KeyLength may be 128, 192, 256
           // crypt.KeyLength = 256;

           // //  Counter mode emits the exact number of bytes input, and therefore
           // //  padding is not used.  The PaddingScheme property does not apply with CTR mode.

           // //  EncodingMode specifies the encoding of the output for
           // //  encryption, and the input for decryption.
           // //  It may be "hex", "url", "base64", "quoted-printable", or many other choices.
           // crypt.EncodingMode = "hex";

           // //  An initialization vector (nonce) is required if using CTR mode.
           // //  The length of the IV is equal to the algorithm's block size.
           // //  It is NOT equal to the length of the key.
           // string ivHex = "00000000000000000000000000000000";
           // crypt.SetEncodedIV(ivHex, "hex");

           // //  The secret key must equal the size of the key.  For
           // //  256-bit encryption, the binary secret key is 32 bytes.
           // //  For 128-bit encryption, the binary secret key is 16 bytes.
           // string keyHex = "000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F";
           // crypt.SetEncodedKey(keyHex, "hex");

           // //  Encrypt a string...
           // //  The input string is 44 ANSI characters (i.e. 44 bytes), so
           // //  the output should be 48 bytes (a multiple of 16).
           // //  Because the output is a hex string, it should
           // //  be 96 characters long (2 chars per byte).
           //// string encStr = crypt.EncryptStringENC(textDataEnc.Text);
           //// Console.WriteLine(encStr);
           // //textBox1.Text = encStr;

           // Chilkat.Crypt2 decrypt = new Chilkat.Crypt2();

           // decrypt.CryptAlgorithm = "aes";
           // decrypt.CipherMode = "ctr";
           // decrypt.KeyLength = 256;
           // decrypt.EncodingMode = "hex";
           // decrypt.SetEncodedIV(ivHex, "hex");
           // decrypt.SetEncodedKey(keyHex, "hex");

           // //  Now decrypt:
           // string decStr = decrypt.DecryptStringENC(textDataEnc.Text);
           //// Console.WriteLine(decStr);
           // textBoxDec.Text = decStr;
           // //Chilkat.Crypt2
           //// Aes aes = Aes.Create();
           //// aes.Key = new byte[] {
           ////     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
           ////     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
           ////     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
           ////     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
           //// };
           //// // aes.GenerateIV();
           //// aes.IV = new byte[] {
           ////     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           ////     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
           //// };
           //// aes.Mode = CipherMode.ECB;//http://nciphers.com/aes/  https://gist.github.com/andrewthecoder/db41b9b73a1c8cea7709
           //// IBufferedCipher cipher = CipherUtilities.GetCipher("AES/CTR/NoPadding");
           //// aes.Padding = PaddingMode.None;
           //// ICryptoTransform decrypter = aes.CreateDecryptor();

           //// byte[] buffer = myConverter.HexStringToByteArray(textDataEnc.Text);


           //// buffer = decrypter.TransformFinalBlock(buffer, 0, buffer.Length);
           //// textBoxDec.Text = ASCIIEncoding.ASCII.GetString(buffer);
        }
        private void button1_Click(object sender, EventArgs e)
        {

            Decrypt_Received_Data_ECB();
        }

        private void dec_cbc_Click(object sender, EventArgs e)
        {
            Decrypt_cbc();
           // Decrypt_Received_Data_CBC();
            
        }

        private void ctr_enc_Click(object sender, EventArgs e)
        {
            Decrypt_counter_mode();
        }

        ////////////////////////////////
        void Decrypt_Received_Data_CBC()
        {
            Aes aes = Aes.Create();
            aes.Key = new byte[] {
                0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
            };
            // aes.GenerateIV();
            aes.IV = new byte[] {
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            };
            aes.Mode = CipherMode.CBC;
            aes.Padding = PaddingMode.None;
            ICryptoTransform decrypter = aes.CreateDecryptor();

            byte[] buffer = myConverter.HexStringToByteArray(textDataEnc.Text);


            buffer = decrypter.TransformFinalBlock(buffer, 0, buffer.Length);
            textBoxDec.Text = ASCIIEncoding.ASCII.GetString(buffer);
        }
        
        /////////////////////Encrypt Data

        public byte[] Encrypt(byte[] mess, byte[] key, byte[] iv)
        {
            mySymmetricAlg.Key = key;
            mySymmetricAlg.IV = iv;
          //  mySymmetricAlg.Padding = PaddingMode.None;
            MemoryStream ms = new MemoryStream();
            CryptoStream cs = new CryptoStream(ms,
            mySymmetricAlg.CreateEncryptor(), CryptoStreamMode.Write);
            cs.Write(mess, 0, mess.Length);
            cs.Close();
            return ms.ToArray();
        }

        private void CBC_Encrypt_Click(object sender, EventArgs e)
        {
            Generate();
            byte[] ciphertext = Encrypt(myConverter.StringToByteArray(textBoxDataToEnc.Text), myConverter.HexStringToByteArray("000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F"), myConverter.HexStringToByteArray("101112131415161718191A1B1C1D1E1F"));
           // textBoxCipher.Text = myConverter.ByteArrayToString(ciphertext);
            textBoxDataEnc.Text = myConverter.ByteArrayToHexString(ciphertext);
            //textBoxPlainHex.Text = myConverter.ByteArrayToHexString(myConverter.StringToByteArray(textBoxPlain.Text));
        }

        private void ECB_Encrypt_Click(object sender, EventArgs e)
        {
            Aes aes = Aes.Create();
            aes.Key = new byte[] {
                0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
            };
            // aes.GenerateIV();
            aes.IV = new byte[] {
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            };
            aes.Mode = CipherMode.ECB;
           // aes.Padding = PaddingMode.Zeros;
            ICryptoTransform encrypter = aes.CreateEncryptor(myConverter.HexStringToByteArray("000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F"), myConverter.HexStringToByteArray("00000000000000000000000000000000"));

            byte[] buffer = myConverter.HexStringToByteArray(textBoxDataToEnc.Text);


            buffer = encrypter.TransformFinalBlock(buffer, 0, buffer.Length);
            textBoxDataEnc.Text = myConverter.ByteArrayToHexString(buffer);
        }

        private void Send_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine(textBoxDataEnc.Text);
        }
        
    }
}
