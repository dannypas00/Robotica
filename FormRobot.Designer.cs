namespace Client_side
{
    partial class FormRobot
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
			this.btnRight = new FontAwesome.Sharp.IconButton();
			this.btnBackwards = new FontAwesome.Sharp.IconButton();
			this.btnLeft = new FontAwesome.Sharp.IconButton();
			this.btnForward = new FontAwesome.Sharp.IconButton();
			this.groupControlls = new System.Windows.Forms.GroupBox();
			this.groupVideofeed = new System.Windows.Forms.GroupBox();
			this.btnSingle = new FontAwesome.Sharp.IconButton();
			this.btnMaze = new FontAwesome.Sharp.IconButton();
			this.btnLine = new FontAwesome.Sharp.IconButton();
			this.btnSpeak = new FontAwesome.Sharp.IconButton();
			this.groupCommands = new System.Windows.Forms.GroupBox();
			this.progressBar1 = new System.Windows.Forms.ProgressBar();
			this.groupControlls.SuspendLayout();
			this.groupCommands.SuspendLayout();
			this.SuspendLayout();
			// 
			// btnRight
			// 
			this.btnRight.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
			this.btnRight.IconChar = FontAwesome.Sharp.IconChar.ArrowAltCircleRight;
			this.btnRight.IconColor = System.Drawing.Color.CadetBlue;
			this.btnRight.IconSize = 60;
			this.btnRight.Location = new System.Drawing.Point(157, 101);
			this.btnRight.Name = "btnRight";
			this.btnRight.Rotation = 0D;
			this.btnRight.Size = new System.Drawing.Size(58, 67);
			this.btnRight.TabIndex = 1;
			this.btnRight.UseVisualStyleBackColor = true;
			this.btnRight.Click += new System.EventHandler(this.BtnRight_Click);
			// 
			// btnBackwards
			// 
			this.btnBackwards.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
			this.btnBackwards.IconChar = FontAwesome.Sharp.IconChar.ArrowAltCircleDown;
			this.btnBackwards.IconColor = System.Drawing.Color.CadetBlue;
			this.btnBackwards.IconSize = 60;
			this.btnBackwards.Location = new System.Drawing.Point(93, 101);
			this.btnBackwards.Name = "btnBackwards";
			this.btnBackwards.Rotation = 0D;
			this.btnBackwards.Size = new System.Drawing.Size(58, 67);
			this.btnBackwards.TabIndex = 2;
			this.btnBackwards.UseVisualStyleBackColor = true;
			this.btnBackwards.Click += new System.EventHandler(this.BtnBackwards_Click);
			// 
			// btnLeft
			// 
			this.btnLeft.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
			this.btnLeft.IconChar = FontAwesome.Sharp.IconChar.ArrowAltCircleLeft;
			this.btnLeft.IconColor = System.Drawing.Color.CadetBlue;
			this.btnLeft.IconSize = 60;
			this.btnLeft.Location = new System.Drawing.Point(29, 101);
			this.btnLeft.Name = "btnLeft";
			this.btnLeft.Rotation = 0D;
			this.btnLeft.Size = new System.Drawing.Size(58, 67);
			this.btnLeft.TabIndex = 3;
			this.btnLeft.UseVisualStyleBackColor = true;
			this.btnLeft.Click += new System.EventHandler(this.BtnLeft_Click);
			// 
			// btnForward
			// 
			this.btnForward.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
			this.btnForward.IconChar = FontAwesome.Sharp.IconChar.ArrowAltCircleUp;
			this.btnForward.IconColor = System.Drawing.Color.CadetBlue;
			this.btnForward.IconSize = 60;
			this.btnForward.Location = new System.Drawing.Point(93, 28);
			this.btnForward.Name = "btnForward";
			this.btnForward.Rotation = 0D;
			this.btnForward.Size = new System.Drawing.Size(58, 67);
			this.btnForward.TabIndex = 4;
			this.btnForward.UseVisualStyleBackColor = true;
			this.btnForward.Click += new System.EventHandler(this.BtnForward_Click);
			// 
			// groupControlls
			// 
			this.groupControlls.Controls.Add(this.btnForward);
			this.groupControlls.Controls.Add(this.btnLeft);
			this.groupControlls.Controls.Add(this.btnBackwards);
			this.groupControlls.Controls.Add(this.btnRight);
			this.groupControlls.Location = new System.Drawing.Point(17, 9);
			this.groupControlls.Name = "groupControlls";
			this.groupControlls.Size = new System.Drawing.Size(230, 202);
			this.groupControlls.TabIndex = 5;
			this.groupControlls.TabStop = false;
			this.groupControlls.Text = "Controlls";
			// 
			// groupVideofeed
			// 
			this.groupVideofeed.Location = new System.Drawing.Point(426, 9);
			this.groupVideofeed.Name = "groupVideofeed";
			this.groupVideofeed.Size = new System.Drawing.Size(288, 294);
			this.groupVideofeed.TabIndex = 6;
			this.groupVideofeed.TabStop = false;
			this.groupVideofeed.Text = "Videofeed";
			// 
			// btnSingle
			// 
			this.btnSingle.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
			this.btnSingle.IconChar = FontAwesome.Sharp.IconChar.Play;
			this.btnSingle.IconColor = System.Drawing.Color.CadetBlue;
			this.btnSingle.IconSize = 50;
			this.btnSingle.Location = new System.Drawing.Point(37, 39);
			this.btnSingle.Name = "btnSingle";
			this.btnSingle.Rotation = 0D;
			this.btnSingle.Size = new System.Drawing.Size(58, 67);
			this.btnSingle.TabIndex = 5;
			this.btnSingle.Text = "Single";
			this.btnSingle.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
			this.btnSingle.UseVisualStyleBackColor = true;
			this.btnSingle.Click += new System.EventHandler(this.BtnSingle_Click);
			// 
			// btnMaze
			// 
			this.btnMaze.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
			this.btnMaze.IconChar = FontAwesome.Sharp.IconChar.Question;
			this.btnMaze.IconColor = System.Drawing.Color.CadetBlue;
			this.btnMaze.IconSize = 50;
			this.btnMaze.Location = new System.Drawing.Point(165, 39);
			this.btnMaze.Name = "btnMaze";
			this.btnMaze.Rotation = 0D;
			this.btnMaze.Size = new System.Drawing.Size(58, 67);
			this.btnMaze.TabIndex = 7;
			this.btnMaze.Text = "Maze";
			this.btnMaze.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
			this.btnMaze.UseVisualStyleBackColor = true;
			// 
			// btnLine
			// 
			this.btnLine.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
			this.btnLine.IconChar = FontAwesome.Sharp.IconChar.Play;
			this.btnLine.IconColor = System.Drawing.Color.CadetBlue;
			this.btnLine.IconSize = 50;
			this.btnLine.Location = new System.Drawing.Point(101, 39);
			this.btnLine.Name = "btnLine";
			this.btnLine.Rotation = 0D;
			this.btnLine.Size = new System.Drawing.Size(58, 67);
			this.btnLine.TabIndex = 8;
			this.btnLine.Text = "Line";
			this.btnLine.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
			this.btnLine.UseVisualStyleBackColor = true;
			this.btnLine.Click += new System.EventHandler(this.BtnLine_Click);
			// 
			// btnSpeak
			// 
			this.btnSpeak.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
			this.btnSpeak.IconChar = FontAwesome.Sharp.IconChar.Microphone;
			this.btnSpeak.IconColor = System.Drawing.Color.CadetBlue;
			this.btnSpeak.IconSize = 50;
			this.btnSpeak.Location = new System.Drawing.Point(229, 39);
			this.btnSpeak.Name = "btnSpeak";
			this.btnSpeak.Rotation = 0D;
			this.btnSpeak.Size = new System.Drawing.Size(58, 67);
			this.btnSpeak.TabIndex = 9;
			this.btnSpeak.Text = "Speak";
			this.btnSpeak.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
			this.btnSpeak.UseVisualStyleBackColor = true;
			this.btnSpeak.Click += new System.EventHandler(this.btnSpeak_Click);
			// 
			// groupCommands
			// 
			this.groupCommands.Controls.Add(this.btnSingle);
			this.groupCommands.Controls.Add(this.btnSpeak);
			this.groupCommands.Controls.Add(this.btnMaze);
			this.groupCommands.Controls.Add(this.btnLine);
			this.groupCommands.Location = new System.Drawing.Point(9, 282);
			this.groupCommands.Name = "groupCommands";
			this.groupCommands.Size = new System.Drawing.Size(295, 131);
			this.groupCommands.TabIndex = 10;
			this.groupCommands.TabStop = false;
			this.groupCommands.Text = "Commands";
			// 
			// progressBar1
			// 
			this.progressBar1.Location = new System.Drawing.Point(310, 310);
			this.progressBar1.Name = "progressBar1";
			this.progressBar1.Size = new System.Drawing.Size(100, 23);
			this.progressBar1.TabIndex = 11;
			// 
			// FormRobot
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.DarkSlateGray;
			this.ClientSize = new System.Drawing.Size(726, 448);
			this.Controls.Add(this.progressBar1);
			this.Controls.Add(this.groupVideofeed);
			this.Controls.Add(this.groupControlls);
			this.Controls.Add(this.groupCommands);
			this.KeyPreview = true;
			this.Name = "FormRobot";
			this.Text = "FormRobot";
			this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.FormRobot_KeyDown);
			this.groupControlls.ResumeLayout(false);
			this.groupCommands.ResumeLayout(false);
			this.ResumeLayout(false);

        }

        #endregion

        private FontAwesome.Sharp.IconButton btnRight;
        private FontAwesome.Sharp.IconButton btnBackwards;
        private FontAwesome.Sharp.IconButton btnLeft;
        private FontAwesome.Sharp.IconButton btnForward;
        private System.Windows.Forms.GroupBox groupControlls;
        private System.Windows.Forms.GroupBox groupVideofeed;
        private FontAwesome.Sharp.IconButton btnSingle;
        private FontAwesome.Sharp.IconButton btnMaze;
        private FontAwesome.Sharp.IconButton btnLine;
        private FontAwesome.Sharp.IconButton btnSpeak;
        private System.Windows.Forms.GroupBox groupCommands;
        private System.Windows.Forms.ProgressBar progressBar1;
    }
}