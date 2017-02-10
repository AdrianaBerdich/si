namespace SI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.textKey = new System.Windows.Forms.TextBox();
            this.textDataEnc = new System.Windows.Forms.TextBox();
            this.textBoxDec = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.data = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.dec_cbc = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.ctr_enc = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxDataToEnc = new System.Windows.Forms.TextBox();
            this.textBoxDataEnc = new System.Windows.Forms.TextBox();
            this.ECB_Encrypt = new System.Windows.Forms.Button();
            this.CBC_Encrypt = new System.Windows.Forms.Button();
            this.CTR_Encrypt = new System.Windows.Forms.Button();
            this.Send = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // textKey
            // 
            this.textKey.Location = new System.Drawing.Point(523, 41);
            this.textKey.Name = "textKey";
            this.textKey.Size = new System.Drawing.Size(158, 20);
            this.textKey.TabIndex = 0;
            // 
            // textDataEnc
            // 
            this.textDataEnc.Location = new System.Drawing.Point(129, 99);
            this.textDataEnc.Name = "textDataEnc";
            this.textDataEnc.Size = new System.Drawing.Size(265, 20);
            this.textDataEnc.TabIndex = 1;
            // 
            // textBoxDec
            // 
            this.textBoxDec.Location = new System.Drawing.Point(95, 146);
            this.textBoxDec.Name = "textBoxDec";
            this.textBoxDec.Size = new System.Drawing.Size(100, 20);
            this.textBoxDec.TabIndex = 2;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(523, 185);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 20);
            this.textBox4.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(468, 48);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(25, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Key";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(8, 106);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(118, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Data Received Encrypt";
            // 
            // data
            // 
            this.data.AutoSize = true;
            this.data.Location = new System.Drawing.Point(16, 152);
            this.data.Name = "data";
            this.data.Size = new System.Drawing.Size(70, 13);
            this.data.TabIndex = 6;
            this.data.Text = "Decrypt Data";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(441, 191);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "label4";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(716, 152);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(106, 96);
            this.richTextBox1.TabIndex = 8;
            this.richTextBox1.Text = "";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(19, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(85, 23);
            this.button1.TabIndex = 9;
            this.button1.Text = "ECB Decrypt";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // dec_cbc
            // 
            this.dec_cbc.Location = new System.Drawing.Point(120, 12);
            this.dec_cbc.Name = "dec_cbc";
            this.dec_cbc.Size = new System.Drawing.Size(87, 23);
            this.dec_cbc.TabIndex = 10;
            this.dec_cbc.Text = "CBC Decrypt";
            this.dec_cbc.UseVisualStyleBackColor = true;
            this.dec_cbc.Click += new System.EventHandler(this.dec_cbc_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(523, 212);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 11;
            // 
            // ctr_enc
            // 
            this.ctr_enc.Location = new System.Drawing.Point(228, 12);
            this.ctr_enc.Name = "ctr_enc";
            this.ctr_enc.Size = new System.Drawing.Size(86, 23);
            this.ctr_enc.TabIndex = 12;
            this.ctr_enc.Text = "CTR Decrypt";
            this.ctr_enc.UseVisualStyleBackColor = true;
            this.ctr_enc.Click += new System.EventHandler(this.ctr_enc_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(465, 94);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 13);
            this.label3.TabIndex = 13;
            this.label3.Text = "Data";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(468, 121);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(81, 13);
            this.label5.TabIndex = 14;
            this.label5.Text = "Data Encrypted";
            // 
            // textBoxDataToEnc
            // 
            this.textBoxDataToEnc.Location = new System.Drawing.Point(568, 87);
            this.textBoxDataToEnc.Name = "textBoxDataToEnc";
            this.textBoxDataToEnc.Size = new System.Drawing.Size(100, 20);
            this.textBoxDataToEnc.TabIndex = 15;
            // 
            // textBoxDataEnc
            // 
            this.textBoxDataEnc.Location = new System.Drawing.Point(568, 113);
            this.textBoxDataEnc.Name = "textBoxDataEnc";
            this.textBoxDataEnc.Size = new System.Drawing.Size(248, 20);
            this.textBoxDataEnc.TabIndex = 16;
            // 
            // ECB_Encrypt
            // 
            this.ECB_Encrypt.Location = new System.Drawing.Point(454, 11);
            this.ECB_Encrypt.Name = "ECB_Encrypt";
            this.ECB_Encrypt.Size = new System.Drawing.Size(75, 23);
            this.ECB_Encrypt.TabIndex = 17;
            this.ECB_Encrypt.Text = "ECB Encrypt";
            this.ECB_Encrypt.UseVisualStyleBackColor = true;
            this.ECB_Encrypt.Click += new System.EventHandler(this.ECB_Encrypt_Click);
            // 
            // CBC_Encrypt
            // 
            this.CBC_Encrypt.Location = new System.Drawing.Point(558, 12);
            this.CBC_Encrypt.Name = "CBC_Encrypt";
            this.CBC_Encrypt.Size = new System.Drawing.Size(75, 23);
            this.CBC_Encrypt.TabIndex = 18;
            this.CBC_Encrypt.Text = "CBC Encrypt";
            this.CBC_Encrypt.UseVisualStyleBackColor = true;
            this.CBC_Encrypt.Click += new System.EventHandler(this.CBC_Encrypt_Click);
            // 
            // CTR_Encrypt
            // 
            this.CTR_Encrypt.Location = new System.Drawing.Point(668, 12);
            this.CTR_Encrypt.Name = "CTR_Encrypt";
            this.CTR_Encrypt.Size = new System.Drawing.Size(85, 23);
            this.CTR_Encrypt.TabIndex = 19;
            this.CTR_Encrypt.Text = "CTR Encrypt";
            this.CTR_Encrypt.UseVisualStyleBackColor = true;
            // 
            // Send
            // 
            this.Send.Location = new System.Drawing.Point(722, 57);
            this.Send.Name = "Send";
            this.Send.Size = new System.Drawing.Size(75, 23);
            this.Send.TabIndex = 20;
            this.Send.Text = "Send";
            this.Send.UseVisualStyleBackColor = true;
            this.Send.Click += new System.EventHandler(this.Send_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(414, 261);
            this.Controls.Add(this.Send);
            this.Controls.Add(this.CTR_Encrypt);
            this.Controls.Add(this.CBC_Encrypt);
            this.Controls.Add(this.ECB_Encrypt);
            this.Controls.Add(this.textBoxDataEnc);
            this.Controls.Add(this.textBoxDataToEnc);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.ctr_enc);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.dec_cbc);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.data);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBoxDec);
            this.Controls.Add(this.textDataEnc);
            this.Controls.Add(this.textKey);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.TextBox textKey;
        private System.Windows.Forms.TextBox textDataEnc;
        private System.Windows.Forms.TextBox textBoxDec;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label data;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button dec_cbc;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button ctr_enc;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxDataToEnc;
        private System.Windows.Forms.TextBox textBoxDataEnc;
        private System.Windows.Forms.Button ECB_Encrypt;
        private System.Windows.Forms.Button CBC_Encrypt;
        private System.Windows.Forms.Button CTR_Encrypt;
        private System.Windows.Forms.Button Send;
    }
}

