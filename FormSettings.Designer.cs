namespace Client_side
{
    partial class FormSettings
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
            this.iconPictureBox2 = new FontAwesome.Sharp.IconPictureBox();
            this.btnLogin = new FontAwesome.Sharp.IconButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.PictureBox_Connected = new FontAwesome.Sharp.IconPictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.iconPictureBox2)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox_Connected)).BeginInit();
            this.SuspendLayout();
            // 
            // iconPictureBox2
            // 
            this.iconPictureBox2.BackColor = System.Drawing.Color.DarkSlateGray;
            this.iconPictureBox2.IconChar = FontAwesome.Sharp.IconChar.User;
            this.iconPictureBox2.IconColor = System.Drawing.Color.White;
            this.iconPictureBox2.IconSize = 43;
            this.iconPictureBox2.Location = new System.Drawing.Point(7, 21);
            this.iconPictureBox2.Name = "iconPictureBox2";
            this.iconPictureBox2.Size = new System.Drawing.Size(43, 48);
            this.iconPictureBox2.TabIndex = 8;
            this.iconPictureBox2.TabStop = false;
            // 
            // btnLogin
            // 
            this.btnLogin.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnLogin.IconChar = FontAwesome.Sharp.IconChar.Link;
            this.btnLogin.IconColor = System.Drawing.Color.Black;
            this.btnLogin.IconSize = 30;
            this.btnLogin.Location = new System.Drawing.Point(65, 21);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Padding = new System.Windows.Forms.Padding(20, 0, 20, 0);
            this.btnLogin.Rotation = 0D;
            this.btnLogin.Size = new System.Drawing.Size(138, 47);
            this.btnLogin.TabIndex = 9;
            this.btnLogin.Text = "Connect";
            this.btnLogin.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.BtnLogin_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.PictureBox_Connected);
            this.groupBox1.Controls.Add(this.btnLogin);
            this.groupBox1.Controls.Add(this.iconPictureBox2);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(273, 233);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            // 
            // PictureBox_Connected
            // 
            this.PictureBox_Connected.BackColor = System.Drawing.Color.DarkSlateGray;
            this.PictureBox_Connected.ForeColor = System.Drawing.Color.LawnGreen;
            this.PictureBox_Connected.IconChar = FontAwesome.Sharp.IconChar.Wifi;
            this.PictureBox_Connected.IconColor = System.Drawing.Color.LawnGreen;
            this.PictureBox_Connected.IconSize = 49;
            this.PictureBox_Connected.Location = new System.Drawing.Point(209, 22);
            this.PictureBox_Connected.Name = "PictureBox_Connected";
            this.PictureBox_Connected.Size = new System.Drawing.Size(50, 49);
            this.PictureBox_Connected.TabIndex = 14;
            this.PictureBox_Connected.TabStop = false;
            // 
            // FormSettings
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkSlateGray;
            this.ClientSize = new System.Drawing.Size(726, 448);
            this.Controls.Add(this.groupBox1);
            this.Name = "FormSettings";
            this.Text = "FromSettings";
            ((System.ComponentModel.ISupportInitialize)(this.iconPictureBox2)).EndInit();
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox_Connected)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private FontAwesome.Sharp.IconPictureBox iconPictureBox2;
        private FontAwesome.Sharp.IconButton btnLogin;
        private System.Windows.Forms.GroupBox groupBox1;
        private FontAwesome.Sharp.IconPictureBox PictureBox_Connected;
    }
}