using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using FontAwesome.Sharp;            //import icon lib

namespace Client_side
{
    public partial class FormMainMenu: Form
    {
        //Fields
        private IconButton currentBtn;
        private Panel leftBorderBtn;
        private Form currentChildForm;

        // Constructor 
        public FormMainMenu()
        {
            InitializeComponent();
            leftBorderBtn = new Panel();
            leftBorderBtn.Size = new Size(7, 60);
            panelMenu.Controls.Add(leftBorderBtn);
            this.DoubleBuffered = true;                 //voorkomt flikkeren
            
        }
        
       //structs
       private struct RGBColors
        {
            public static Color color1 = Color.FromArgb(172, 126, 241);
            public static Color color2 = Color.FromArgb(249, 118, 176);
            public static Color color3 = Color.FromArgb(253, 138, 114);
            public static Color color4 = Color.FromArgb(95, 77, 221);
            public static Color color5 = Color.FromArgb(249, 88, 155);
            public static Color color6 = Color.FromArgb(24, 161, 251);
        }
        
        //Methods
        private void ActivateButton(object senderBtn, Color color)
        {
            if(senderBtn != null)
            {
                DisableButton();
                //btn
                currentBtn = (IconButton)senderBtn;
                currentBtn.BackColor = Color.FromArgb(37, 36, 81);
                currentBtn.ForeColor = color;
                currentBtn.TextAlign = ContentAlignment.MiddleCenter;
                currentBtn.IconColor = color;
                currentBtn.TextImageRelation = TextImageRelation.TextBeforeImage;
                currentBtn.ImageAlign = ContentAlignment.MiddleRight;
                //left border btn
                leftBorderBtn.BackColor = color;
                leftBorderBtn.Location = new Point(0, currentBtn.Location.Y);
                leftBorderBtn.Visible = true;
                leftBorderBtn.BringToFront();
            }

        }
        private void DisableButton()
        {
            if(currentBtn !=null)
            {
                currentBtn.BackColor = Color.FromArgb(31, 30, 68); //orignal color
                currentBtn.ForeColor = Color.Gainsboro;
                currentBtn.TextAlign = ContentAlignment.MiddleLeft;
                currentBtn.IconColor = Color.Gainsboro;
                currentBtn.TextImageRelation = TextImageRelation.ImageBeforeText;
                currentBtn.ImageAlign = ContentAlignment.MiddleLeft;
            }
        }

        private void OpenChildForm(Form childform)
        {
        if (currentChildForm != null)
            {
                //open only form
                currentChildForm.Close();
            }
            currentChildForm = childform;
            childform.TopLevel = false;
            childform.FormBorderStyle = FormBorderStyle.None;
            childform.Dock = DockStyle.Fill;
            panelDesktop.Controls.Add(childform);
            panelDesktop.Tag = childform;
            childform.BringToFront();
            childform.Show();
        }

        //Drag Form
        [DllImport("user32.DLL", EntryPoint = "ReleaseCapture")]
        private extern static void Releasecapture();
        [DllImport("user32.DLL", EntryPoint = "SendMessage")]
        private extern static void SendMessage(System.IntPtr hWnd, int wMsg, int wParam, int lParam);


        private void BtnRobot_Click(object sender, EventArgs e)
        {
            ActivateButton(sender, RGBColors.color1);               //pakt kleur uit kleuren tabel
            OpenChildForm(new FormRobot());                         //Roept nieuwe form aan

        }

        private void BtnSettings_Click(object sender, EventArgs e)
        {
            ActivateButton(sender, RGBColors.color2);               //pakt kleur uit kleuren tabel
            OpenChildForm(new FormSettings());                      ///Roept nieuwe form aan
        }

        private void IconPictureBox_Exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void IconPictureBox_Help_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Shortcuts:\nForward: 'W'\nBackward: 'S'\nLeft: 'A'\nRight: 'D'");
        }

        //Drag
        private void PanelTitleBar_MouseDown(object sender, MouseEventArgs e)
        {
            Releasecapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }
    }
}
