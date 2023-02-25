namespace Лаба1
{
    partial class FmMain
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FmMain));
            this.TextBoxPlain = new System.Windows.Forms.TextBox();
            this.TextBoxCipher = new System.Windows.Forms.TextBox();
            this.TextBoxKey = new System.Windows.Forms.TextBox();
            this.LblKey = new System.Windows.Forms.Label();
            this.BtnCipher = new System.Windows.Forms.Button();
            this.BtnDecipher = new System.Windows.Forms.Button();
            this.CmbCipherAlgoritm = new System.Windows.Forms.ComboBox();
            this.ToolStripMenu = new System.Windows.Forms.ToolStrip();
            this.MenuBtnOpen = new System.Windows.Forms.ToolStripDropDownButton();
            this.MenuSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.MenuBtnSave = new System.Windows.Forms.ToolStripButton();
            this.OpnFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.SvFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.ToolStripMenu.SuspendLayout();
            this.SuspendLayout();
            // 
            // TextBoxPlain
            // 
            this.TextBoxPlain.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.TextBoxPlain.Location = new System.Drawing.Point(12, 30);
            this.TextBoxPlain.Multiline = true;
            this.TextBoxPlain.Name = "TextBoxPlain";
            this.TextBoxPlain.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.TextBoxPlain.Size = new System.Drawing.Size(557, 462);
            this.TextBoxPlain.TabIndex = 0;
            // 
            // TextBoxCipher
            // 
            this.TextBoxCipher.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.TextBoxCipher.Location = new System.Drawing.Point(580, 30);
            this.TextBoxCipher.Multiline = true;
            this.TextBoxCipher.Name = "TextBoxCipher";
            this.TextBoxCipher.ReadOnly = true;
            this.TextBoxCipher.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.TextBoxCipher.Size = new System.Drawing.Size(557, 462);
            this.TextBoxCipher.TabIndex = 1;
            // 
            // TextBoxKey
            // 
            this.TextBoxKey.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.TextBoxKey.Location = new System.Drawing.Point(124, 510);
            this.TextBoxKey.Name = "TextBoxKey";
            this.TextBoxKey.Size = new System.Drawing.Size(445, 30);
            this.TextBoxKey.TabIndex = 2;
            // 
            // LblKey
            // 
            this.LblKey.AutoSize = true;
            this.LblKey.Font = new System.Drawing.Font("Microsoft Sans Serif", 12.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LblKey.Location = new System.Drawing.Point(12, 510);
            this.LblKey.Name = "LblKey";
            this.LblKey.Size = new System.Drawing.Size(106, 26);
            this.LblKey.TabIndex = 3;
            this.LblKey.Text = "Input key:";
            // 
            // BtnCipher
            // 
            this.BtnCipher.Cursor = System.Windows.Forms.Cursors.Hand;
            this.BtnCipher.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.BtnCipher.Location = new System.Drawing.Point(12, 555);
            this.BtnCipher.Name = "BtnCipher";
            this.BtnCipher.Size = new System.Drawing.Size(557, 34);
            this.BtnCipher.TabIndex = 4;
            this.BtnCipher.Text = "CIPHER";
            this.BtnCipher.UseVisualStyleBackColor = true;
            this.BtnCipher.Click += new System.EventHandler(this.BtnCipher_Click);
            // 
            // BtnDecipher
            // 
            this.BtnDecipher.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.BtnDecipher.Location = new System.Drawing.Point(580, 555);
            this.BtnDecipher.Name = "BtnDecipher";
            this.BtnDecipher.Size = new System.Drawing.Size(557, 34);
            this.BtnDecipher.TabIndex = 5;
            this.BtnDecipher.Text = "DECIPHER";
            this.BtnDecipher.UseVisualStyleBackColor = true;
            this.BtnDecipher.Click += new System.EventHandler(this.BtnDecipher_Click);
            // 
            // CmbCipherAlgoritm
            // 
            this.CmbCipherAlgoritm.AutoCompleteCustomSource.AddRange(new string[] {
            "Столбцовый метод",
            "Алгоритм Виженера, самогенерирующийся ключ",
            "Шифр Плейфейра"});
            this.CmbCipherAlgoritm.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.CustomSource;
            this.CmbCipherAlgoritm.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CmbCipherAlgoritm.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.CmbCipherAlgoritm.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CmbCipherAlgoritm.FormattingEnabled = true;
            this.CmbCipherAlgoritm.Items.AddRange(new object[] {
            "Алгоритм Виженера, самогенерирующийся ключ",
            "Столбцовый метод",
            "Шифр Плейфейра"});
            this.CmbCipherAlgoritm.Location = new System.Drawing.Point(580, 510);
            this.CmbCipherAlgoritm.Name = "CmbCipherAlgoritm";
            this.CmbCipherAlgoritm.Size = new System.Drawing.Size(557, 30);
            this.CmbCipherAlgoritm.TabIndex = 3;
            // 
            // ToolStripMenu
            // 
            this.ToolStripMenu.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.ToolStripMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuBtnOpen,
            this.MenuSeparator,
            this.MenuBtnSave});
            this.ToolStripMenu.Location = new System.Drawing.Point(0, 0);
            this.ToolStripMenu.Name = "ToolStripMenu";
            this.ToolStripMenu.Size = new System.Drawing.Size(1149, 27);
            this.ToolStripMenu.TabIndex = 6;
            this.ToolStripMenu.Text = "File";
            // 
            // MenuBtnOpen
            // 
            this.MenuBtnOpen.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.MenuBtnOpen.Image = ((System.Drawing.Image)(resources.GetObject("MenuBtnOpen.Image")));
            this.MenuBtnOpen.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.MenuBtnOpen.Name = "MenuBtnOpen";
            this.MenuBtnOpen.ShowDropDownArrow = false;
            this.MenuBtnOpen.Size = new System.Drawing.Size(81, 24);
            this.MenuBtnOpen.Text = "OPEN FILE";
            this.MenuBtnOpen.ToolTipText = "Open text file";
            this.MenuBtnOpen.Click += new System.EventHandler(this.MenuBtnOpen_Click);
            // 
            // MenuSeparator
            // 
            this.MenuSeparator.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.MenuSeparator.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.MenuSeparator.Name = "MenuSeparator";
            this.MenuSeparator.Size = new System.Drawing.Size(6, 27);
            // 
            // MenuBtnSave
            // 
            this.MenuBtnSave.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.MenuBtnSave.Image = ((System.Drawing.Image)(resources.GetObject("MenuBtnSave.Image")));
            this.MenuBtnSave.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.MenuBtnSave.Name = "MenuBtnSave";
            this.MenuBtnSave.Size = new System.Drawing.Size(77, 24);
            this.MenuBtnSave.Text = "SAVE FILE";
            this.MenuBtnSave.ToolTipText = "Save changes to file";
            this.MenuBtnSave.Click += new System.EventHandler(this.MenuBtnSave_Click);
            // 
            // OpnFileDialog
            // 
            this.OpnFileDialog.FileName = "PlainText.txt";
            this.OpnFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.OpenFileDialog_FileOk);
            // 
            // SvFileDialog
            // 
            this.SvFileDialog.FileName = "CipherText.txt";
            this.SvFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.SvFileDialog_FileOk);
            // 
            // FmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1149, 606);
            this.Controls.Add(this.ToolStripMenu);
            this.Controls.Add(this.CmbCipherAlgoritm);
            this.Controls.Add(this.BtnDecipher);
            this.Controls.Add(this.BtnCipher);
            this.Controls.Add(this.LblKey);
            this.Controls.Add(this.TextBoxKey);
            this.Controls.Add(this.TextBoxCipher);
            this.Controls.Add(this.TextBoxPlain);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.MaximizeBox = false;
            this.Name = "FmMain";
            this.ShowIcon = false;
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Encryptor";
            this.ToolStripMenu.ResumeLayout(false);
            this.ToolStripMenu.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox TextBoxCipher;
        private System.Windows.Forms.TextBox TextBoxKey;
        private System.Windows.Forms.Label LblKey;
        private System.Windows.Forms.Button BtnCipher;
        private System.Windows.Forms.Button BtnDecipher;
        private System.Windows.Forms.ComboBox CmbCipherAlgoritm;
        private System.Windows.Forms.ToolStrip ToolStripMenu;
        private System.Windows.Forms.ToolStripDropDownButton MenuBtnOpen;
        private System.Windows.Forms.ToolStripButton MenuBtnSave;
        private System.Windows.Forms.ToolStripSeparator MenuSeparator;
        private System.Windows.Forms.OpenFileDialog OpnFileDialog;
        private System.Windows.Forms.SaveFileDialog SvFileDialog;
        public System.Windows.Forms.TextBox TextBoxPlain;
    }
}

