namespace Client_side
{
    partial class FormMainMenu
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

        #region Component Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panelMenu = new System.Windows.Forms.Panel();
            this.BtnSettings = new FontAwesome.Sharp.IconButton();
            this.BtnRobot = new FontAwesome.Sharp.IconButton();
            this.panelLogo = new System.Windows.Forms.Panel();
            this.btnHome = new System.Windows.Forms.PictureBox();
            this.panelDesktop = new System.Windows.Forms.Panel();
            this.iconPictureBox_WindowMinimize = new FontAwesome.Sharp.IconPictureBox();
            this.iconPictureBox_WindowMaximize = new FontAwesome.Sharp.IconPictureBox();
            this.iconPictureBox_Exit = new FontAwesome.Sharp.IconPictureBox();
            this.panelTitleBar = new System.Windows.Forms.Panel();
            this.panelMenu.SuspendLayout();
            this.panelLogo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.btnHome)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconPictureBox_WindowMinimize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconPictureBox_WindowMaximize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconPictureBox_Exit)).BeginInit();
            this.panelTitleBar.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelMenu
            // 
            this.panelMenu.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(31)))), ((int)(((byte)(30)))), ((int)(((byte)(68)))));
            this.panelMenu.Controls.Add(this.BtnSettings);
            this.panelMenu.Controls.Add(this.BtnRobot);
            this.panelMenu.Controls.Add(this.panelLogo);
            this.panelMenu.Dock = System.Windows.Forms.DockStyle.Left;
            this.panelMenu.Location = new System.Drawing.Point(0, 0);
            this.panelMenu.Name = "panelMenu";
            this.panelMenu.Size = new System.Drawing.Size(220, 533);
            this.panelMenu.TabIndex = 0;
            // 
            // BtnSettings
            // 
            this.BtnSettings.Dock = System.Windows.Forms.DockStyle.Top;
            this.BtnSettings.FlatAppearance.BorderSize = 0;
            this.BtnSettings.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.BtnSettings.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.BtnSettings.ForeColor = System.Drawing.Color.Gainsboro;
            this.BtnSettings.IconChar = FontAwesome.Sharp.IconChar.Cog;
            this.BtnSettings.IconColor = System.Drawing.Color.DodgerBlue;
            this.BtnSettings.IconSize = 40;
            this.BtnSettings.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.BtnSettings.Location = new System.Drawing.Point(0, 200);
            this.BtnSettings.Name = "BtnSettings";
            this.BtnSettings.Padding = new System.Windows.Forms.Padding(10, 0, 20, 0);
            this.BtnSettings.Rotation = 0D;
            this.BtnSettings.Size = new System.Drawing.Size(220, 60);
            this.BtnSettings.TabIndex = 2;
            this.BtnSettings.Text = "Settings";
            this.BtnSettings.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.BtnSettings.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.BtnSettings.UseVisualStyleBackColor = true;
            this.BtnSettings.Click += new System.EventHandler(this.BtnSettings_Click);
            // 
            // BtnRobot
            // 
            this.BtnRobot.Dock = System.Windows.Forms.DockStyle.Top;
            this.BtnRobot.FlatAppearance.BorderSize = 0;
            this.BtnRobot.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.BtnRobot.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.BtnRobot.ForeColor = System.Drawing.Color.Gainsboro;
            this.BtnRobot.IconChar = FontAwesome.Sharp.IconChar.Robot;
            this.BtnRobot.IconColor = System.Drawing.Color.DodgerBlue;
            this.BtnRobot.IconSize = 40;
            this.BtnRobot.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.BtnRobot.Location = new System.Drawing.Point(0, 140);
            this.BtnRobot.Name = "BtnRobot";
            this.BtnRobot.Padding = new System.Windows.Forms.Padding(10, 0, 20, 0);
            this.BtnRobot.Rotation = 0D;
            this.BtnRobot.Size = new System.Drawing.Size(220, 60);
            this.BtnRobot.TabIndex = 1;
            this.BtnRobot.Text = "Robot";
            this.BtnRobot.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.BtnRobot.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.BtnRobot.UseVisualStyleBackColor = true;
            this.BtnRobot.Click += new System.EventHandler(this.BtnRobot_Click);
            // 
            // panelLogo
            // 
            this.panelLogo.Controls.Add(this.btnHome);
            this.panelLogo.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelLogo.Location = new System.Drawing.Point(0, 0);
            this.panelLogo.Name = "panelLogo";
            this.panelLogo.Size = new System.Drawing.Size(220, 140);
            this.panelLogo.TabIndex = 0;
            // 
            // btnHome
            // 
            this.btnHome.Image = global::Client_side.Properties.Resources.NHL_Stenden_Hogeschool;
            this.btnHome.Location = new System.Drawing.Point(-15, -33);
            this.btnHome.Name = "btnHome";
            this.btnHome.Size = new System.Drawing.Size(235, 173);
            this.btnHome.TabIndex = 0;
            this.btnHome.TabStop = false;
            // 
            // panelDesktop
            // 
            this.panelDesktop.BackColor = System.Drawing.Color.DarkSlateGray;
            this.panelDesktop.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelDesktop.Location = new System.Drawing.Point(220, 0);
            this.panelDesktop.Name = "panelDesktop";
            this.panelDesktop.Size = new System.Drawing.Size(750, 533);
            this.panelDesktop.TabIndex = 1;
            // 
            // iconPictureBox_WindowMinimize
            // 
            this.iconPictureBox_WindowMinimize.BackColor = System.Drawing.Color.ForestGreen;
            this.iconPictureBox_WindowMinimize.Cursor = System.Windows.Forms.Cursors.Hand;
            this.iconPictureBox_WindowMinimize.ForeColor = System.Drawing.SystemColors.ControlText;
            this.iconPictureBox_WindowMinimize.IconChar = FontAwesome.Sharp.IconChar.WindowMinimize;
            this.iconPictureBox_WindowMinimize.IconColor = System.Drawing.SystemColors.ControlText;
            this.iconPictureBox_WindowMinimize.Location = new System.Drawing.Point(645, 0);
            this.iconPictureBox_WindowMinimize.Name = "iconPictureBox_WindowMinimize";
            this.iconPictureBox_WindowMinimize.Size = new System.Drawing.Size(32, 32);
            this.iconPictureBox_WindowMinimize.TabIndex = 2;
            this.iconPictureBox_WindowMinimize.TabStop = false;
            this.iconPictureBox_WindowMinimize.Click += new System.EventHandler(this.IconPictureBox_WindowMinimize_Click);
            // 
            // iconPictureBox_WindowMaximize
            // 
            this.iconPictureBox_WindowMaximize.BackColor = System.Drawing.Color.ForestGreen;
            this.iconPictureBox_WindowMaximize.Cursor = System.Windows.Forms.Cursors.SizeAll;
            this.iconPictureBox_WindowMaximize.ForeColor = System.Drawing.SystemColors.ControlText;
            this.iconPictureBox_WindowMaximize.IconChar = FontAwesome.Sharp.IconChar.WindowMaximize;
            this.iconPictureBox_WindowMaximize.IconColor = System.Drawing.SystemColors.ControlText;
            this.iconPictureBox_WindowMaximize.Location = new System.Drawing.Point(684, 0);
            this.iconPictureBox_WindowMaximize.Name = "iconPictureBox_WindowMaximize";
            this.iconPictureBox_WindowMaximize.Size = new System.Drawing.Size(32, 32);
            this.iconPictureBox_WindowMaximize.TabIndex = 1;
            this.iconPictureBox_WindowMaximize.TabStop = false;
            this.iconPictureBox_WindowMaximize.Click += new System.EventHandler(this.IconPictureBox_WindowMaximize_Click);
            // 
            // iconPictureBox_Exit
            // 
            this.iconPictureBox_Exit.BackColor = System.Drawing.Color.ForestGreen;
            this.iconPictureBox_Exit.Cursor = System.Windows.Forms.Cursors.Hand;
            this.iconPictureBox_Exit.ForeColor = System.Drawing.SystemColors.ControlText;
            this.iconPictureBox_Exit.IconChar = FontAwesome.Sharp.IconChar.Times;
            this.iconPictureBox_Exit.IconColor = System.Drawing.SystemColors.ControlText;
            this.iconPictureBox_Exit.Location = new System.Drawing.Point(719, 0);
            this.iconPictureBox_Exit.Name = "iconPictureBox_Exit";
            this.iconPictureBox_Exit.Size = new System.Drawing.Size(32, 32);
            this.iconPictureBox_Exit.TabIndex = 0;
            this.iconPictureBox_Exit.TabStop = false;
            this.iconPictureBox_Exit.Click += new System.EventHandler(this.IconPictureBox_Exit_Click);
            // 
            // panelTitleBar
            // 
            this.panelTitleBar.Controls.Add(this.iconPictureBox_WindowMinimize);
            this.panelTitleBar.Controls.Add(this.iconPictureBox_WindowMaximize);
            this.panelTitleBar.Controls.Add(this.iconPictureBox_Exit);
            this.panelTitleBar.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelTitleBar.Location = new System.Drawing.Point(220, 0);
            this.panelTitleBar.Name = "panelTitleBar";
            this.panelTitleBar.Size = new System.Drawing.Size(750, 32);
            this.panelTitleBar.TabIndex = 2;
            this.panelTitleBar.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PanelTitleBar_MouseDown);
            // 
            // FormMainMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.ForestGreen;
            this.ClientSize = new System.Drawing.Size(970, 533);
            this.ControlBox = false;
            this.Controls.Add(this.panelTitleBar);
            this.Controls.Add(this.panelDesktop);
            this.Controls.Add(this.panelMenu);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormMainMenu";
            this.ShowIcon = false;
            this.panelMenu.ResumeLayout(false);
            this.panelLogo.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.btnHome)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconPictureBox_WindowMinimize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconPictureBox_WindowMaximize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconPictureBox_Exit)).EndInit();
            this.panelTitleBar.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelMenu;
        private FontAwesome.Sharp.IconButton BtnSettings;
        private FontAwesome.Sharp.IconButton BtnRobot;
        private System.Windows.Forms.Panel panelLogo;
        private System.Windows.Forms.PictureBox btnHome;
        private System.Windows.Forms.Panel panelDesktop;
        private FontAwesome.Sharp.IconPictureBox iconPictureBox_Exit;
        private FontAwesome.Sharp.IconPictureBox iconPictureBox_WindowMinimize;
        private FontAwesome.Sharp.IconPictureBox iconPictureBox_WindowMaximize;
        private System.Windows.Forms.Panel panelTitleBar;
    }
}
