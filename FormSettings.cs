using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client_side
{
    public partial class FormSettings : Form
    {
        public FormSettings()
        {
            InitializeComponent();
            PictureBox_Connected.Visible = false;

        }

        private void BtnLogin_Click(object sender, EventArgs e)
        {
			Client.GetInstance().Connect("127.0.0.1", 5000);
			PictureBox_Connected.Visible = true;
		}

  
    }
}
