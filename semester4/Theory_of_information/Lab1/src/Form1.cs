using System;
/*using System.Collections.Generic;*/
using System.ComponentModel;
/*using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;*/
using System.Windows.Forms;

namespace Лаба1
{
    public partial class FmMain : Form
    {
        public FmMain()
        {
            InitializeComponent();
        }

        private void MenuBtnOpen_Click(object sender, EventArgs e)
        {
            OpnFileDialog.ShowDialog();
        }

        private void OpenFileDialog_FileOk(object sender, CancelEventArgs e)
        {
            TextBoxPlain.Text = System.IO.File.ReadAllText(OpnFileDialog.FileName);
        }

        private void MenuBtnSave_Click(object sender, EventArgs e)
        {
            SvFileDialog.ShowDialog();
        }

        private void SvFileDialog_FileOk(object sender, CancelEventArgs e)
        {
            System.IO.File.WriteAllText(SvFileDialog.FileName, TextBoxPlain.Text);
        }

        private void BtnCipher_Click(object sender, EventArgs e)
        {
            switch(CmbCipherAlgoritm.SelectedIndex)
            {
                case 0:
                {
                    VigenereCipher VC = new VigenereCipher(TextBoxPlain.Text, TextBoxKey.Text);
                    SvFileDialog.ShowDialog();
                    System.IO.File.WriteAllText(SvFileDialog.FileName, TextBoxCipher.Text = VC.Encryption(1));
                    break;
                }
                case 1:
                {
                    ColumnCipher CC = new ColumnCipher(TextBoxPlain.Text, TextBoxKey.Text);
                    SvFileDialog.ShowDialog();
                    System.IO.File.WriteAllText(SvFileDialog.FileName, TextBoxCipher.Text = CC.Encryption(1));
                    break;
                }
                case 2:
                {
                    PlayfairCipher PC = new PlayfairCipher(TextBoxPlain.Text, TextBoxKey.Text);
                    break;
                }
            }
        }

        private void BtnDecipher_Click(object sender, EventArgs e)
        {
            switch (CmbCipherAlgoritm.SelectedIndex)
            {
                case 0:
                    {
                        VigenereCipher VC = new VigenereCipher(TextBoxPlain.Text, TextBoxKey.Text);
                        SvFileDialog.ShowDialog();
                        System.IO.File.WriteAllText(SvFileDialog.FileName, TextBoxCipher.Text = VC.Encryption(-1));
                        break;
                    }
                case 1:
                    {
                        ColumnCipher CC = new ColumnCipher(TextBoxPlain.Text, TextBoxKey.Text);
                        SvFileDialog.ShowDialog();
                        System.IO.File.WriteAllText(SvFileDialog.FileName, TextBoxCipher.Text = CC.Encryption(-1));
                        break;
                    }
                case 2:
                    {

                        break;
                    }
            }
        }
    }
}