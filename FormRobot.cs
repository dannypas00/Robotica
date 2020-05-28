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
    public partial class FormRobot : Form
    {
        public FormRobot()
        {
            InitializeComponent();
        }

 
        private void FormRobot_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                btnForward.PerformClick();
            }

            if (e.KeyCode == Keys.S)
            {
                btnBackwards.PerformClick();
            }

            if (e.KeyCode == Keys.A)
            {
                btnLeft.PerformClick();
            }

            if (e.KeyCode == Keys.D)
            {
                btnRight.PerformClick();
            }
        }

        private void BtnForward_Click(object sender, EventArgs e)
        {
            progressBar1.Increment(1);
            
        }
    }
}
