using System;
using System.Windows.Forms;

namespace MIAPR_LAB1
{
    public partial class fmMain : Form
    {
        private MaximinAlgorithm runner;
        public fmMain()
        {
            InitializeComponent();
        }
        private void btnPrepareAlghorithm_Click(object sender, EventArgs e)
        {
            /*runner = new KMeansAlgorithm
                (
                    txtBoxImagesNumber.Text, 
                    txtBoxClassesNumber.Text,
                    pnlDraw.CreateGraphics()
                );
            runner.prepareAlgorithm();*/
        }
        private void btnRunAlghorithm_Click(object sender, EventArgs e)
        {
            runner = new MaximinAlgorithm(txtBoxImagesNumber.Text, pnlDraw.CreateGraphics());
            runner.runAlgorithm();
        }
    }
}
