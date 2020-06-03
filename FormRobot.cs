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
		// ToDo: button pressed function
        private void BtnForward_Click(object sender, EventArgs e)
        {
			Client.GetInstance().Send("MF", "10");
		}

		private void BtnBackwards_Click(object sender, EventArgs e)
		{
			Client.GetInstance().Send("MB", "10");
		}

		private void BtnLeft_Click(object sender, EventArgs e)
		{
			Client.GetInstance().Send("RO", "5");
		}

		private void BtnRight_Click(object sender, EventArgs e)
		{
			Client.GetInstance().Send("RO", "-5");
		}

		private void BtnSingle_Click(object sender, EventArgs e)
		{
			if (btnSingle.BackColor == Color.Transparent)
			{
				Client.GetInstance().Send("SD", "1");
				btnSingle.BackColor = Color.YellowGreen;
			}
			else if (btnSingle.BackColor == Color.YellowGreen)
			{
				Client.GetInstance().Send("SD", "0");
				btnSingle.BackColor = Color.Transparent;
			}
		}

		private void BtnLine_Click(object sender, EventArgs e)
		{
			if (btnLine.BackColor == Color.Transparent)
			{
				Client.GetInstance().Send("LD", "1");
				btnLine.BackColor = Color.YellowGreen;

			}
			else if (btnLine.BackColor == Color.YellowGreen)
			{
				Client.GetInstance().Send("LD", "0");
				btnLine.BackColor = Color.Transparent;
			}
		}

		private void BtnMaze_Click(object sender, EventArgs e)
		{
			if (btnMaze.BackColor == Color.Transparent)
			{
				Client.GetInstance().Send("MM", "1");
				btnMaze.BackColor = Color.YellowGreen;

			}
			else if (btnMaze.BackColor == Color.YellowGreen)
			{
				Client.GetInstance().Send("MM", "0");
				btnMaze.BackColor = Color.Transparent;
			}
		}

		private void BtnSpeak_Click(object sender, EventArgs e)
		{

		}
	}
}
