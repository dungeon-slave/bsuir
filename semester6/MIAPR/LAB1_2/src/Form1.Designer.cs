
namespace MIAPR_LAB1
{
    partial class fmMain
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
            this.txtBoxImagesNumber = new System.Windows.Forms.TextBox();
            this.txtBoxClassesNumber = new System.Windows.Forms.TextBox();
            this.btnPrepareAlgorithm = new System.Windows.Forms.Button();
            this.btnRunAlgorithm = new System.Windows.Forms.Button();
            this.pnlDraw = new System.Windows.Forms.Panel();
            this.lblImagesCount = new System.Windows.Forms.Label();
            this.lblClassesCount = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtBoxImagesNumber
            // 
            this.txtBoxImagesNumber.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.txtBoxImagesNumber.Location = new System.Drawing.Point(6, 27);
            this.txtBoxImagesNumber.Name = "txtBoxImagesNumber";
            this.txtBoxImagesNumber.Size = new System.Drawing.Size(178, 23);
            this.txtBoxImagesNumber.TabIndex = 0;
            // 
            // txtBoxClassesNumber
            // 
            this.txtBoxClassesNumber.Enabled = false;
            this.txtBoxClassesNumber.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.txtBoxClassesNumber.Location = new System.Drawing.Point(6, 78);
            this.txtBoxClassesNumber.Name = "txtBoxClassesNumber";
            this.txtBoxClassesNumber.Size = new System.Drawing.Size(178, 23);
            this.txtBoxClassesNumber.TabIndex = 1;
            // 
            // btnPrepareAlgorithm
            // 
            this.btnPrepareAlgorithm.Enabled = false;
            this.btnPrepareAlgorithm.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnPrepareAlgorithm.Location = new System.Drawing.Point(6, 141);
            this.btnPrepareAlgorithm.Name = "btnPrepareAlgorithm";
            this.btnPrepareAlgorithm.Size = new System.Drawing.Size(178, 35);
            this.btnPrepareAlgorithm.TabIndex = 2;
            this.btnPrepareAlgorithm.Text = "Подготовить";
            this.btnPrepareAlgorithm.UseVisualStyleBackColor = true;
            this.btnPrepareAlgorithm.Visible = false;
            this.btnPrepareAlgorithm.Click += new System.EventHandler(this.btnPrepareAlghorithm_Click);
            // 
            // btnRunAlgorithm
            // 
            this.btnRunAlgorithm.Location = new System.Drawing.Point(6, 182);
            this.btnRunAlgorithm.Name = "btnRunAlgorithm";
            this.btnRunAlgorithm.Size = new System.Drawing.Size(178, 35);
            this.btnRunAlgorithm.TabIndex = 3;
            this.btnRunAlgorithm.Text = "Запустить алгоритм";
            this.btnRunAlgorithm.UseVisualStyleBackColor = true;
            this.btnRunAlgorithm.Click += new System.EventHandler(this.btnRunAlghorithm_Click);
            // 
            // pnlDraw
            // 
            this.pnlDraw.BackColor = System.Drawing.Color.Black;
            this.pnlDraw.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlDraw.Location = new System.Drawing.Point(-1, 0);
            this.pnlDraw.Name = "pnlDraw";
            this.pnlDraw.Size = new System.Drawing.Size(517, 410);
            this.pnlDraw.TabIndex = 4;
            // 
            // lblImagesCount
            // 
            this.lblImagesCount.AutoSize = true;
            this.lblImagesCount.Location = new System.Drawing.Point(3, 11);
            this.lblImagesCount.Name = "lblImagesCount";
            this.lblImagesCount.Size = new System.Drawing.Size(89, 13);
            this.lblImagesCount.TabIndex = 0;
            this.lblImagesCount.Text = "Кол-во образов:";
            // 
            // lblClassesCount
            // 
            this.lblClassesCount.AutoSize = true;
            this.lblClassesCount.Location = new System.Drawing.Point(3, 62);
            this.lblClassesCount.Name = "lblClassesCount";
            this.lblClassesCount.Size = new System.Drawing.Size(89, 13);
            this.lblClassesCount.TabIndex = 5;
            this.lblClassesCount.Text = "Кол-во классов:";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.WindowFrame;
            this.panel1.Controls.Add(this.btnRunAlgorithm);
            this.panel1.Controls.Add(this.lblImagesCount);
            this.panel1.Controls.Add(this.btnPrepareAlgorithm);
            this.panel1.Controls.Add(this.lblClassesCount);
            this.panel1.Controls.Add(this.txtBoxClassesNumber);
            this.panel1.Controls.Add(this.txtBoxImagesNumber);
            this.panel1.Location = new System.Drawing.Point(516, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(196, 409);
            this.panel1.TabIndex = 6;
            // 
            // fmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(712, 409);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.pnlDraw);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.MaximizeBox = false;
            this.Name = "fmMain";
            this.ShowIcon = false;
            this.Text = "Алгоритмы К-средних и Максимина";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox txtBoxImagesNumber;
        private System.Windows.Forms.TextBox txtBoxClassesNumber;
        private System.Windows.Forms.Button btnPrepareAlgorithm;
        private System.Windows.Forms.Button btnRunAlgorithm;
        private System.Windows.Forms.Panel pnlDraw;
        private System.Windows.Forms.Label lblImagesCount;
        private System.Windows.Forms.Label lblClassesCount;
        private System.Windows.Forms.Panel panel1;
    }
}

