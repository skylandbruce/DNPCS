namespace DNPCSformtest
{
    partial class FormView
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            buttonStart = new Button();
            buttonStop = new Button();
            SuspendLayout();
            // 
            // buttonStart
            // 
            buttonStart.Location = new Point(83, 730);
            buttonStart.Name = "buttonStart";
            buttonStart.Size = new Size(188, 58);
            buttonStart.TabIndex = 0;
            buttonStart.Text = "시작";
            buttonStart.UseVisualStyleBackColor = true;
            buttonStart.Click += ButtonStart_Click;
            // 
            // buttonStop
            // 
            buttonStop.Location = new Point(347, 730);
            buttonStop.Name = "buttonStop";
            buttonStop.Size = new Size(188, 58);
            buttonStop.TabIndex = 1;
            buttonStop.Text = "정지";
            buttonStop.UseVisualStyleBackColor = true;
            buttonStop.Click += ButtonStop_Click;
            // 
            // FormView
            // 
            AutoScaleDimensions = new SizeF(17F, 41F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ControlLight;
            ClientSize = new Size(591, 800);
            Controls.Add(buttonStop);
            Controls.Add(buttonStart);
            DoubleBuffered = true;
            FormBorderStyle = FormBorderStyle.FixedDialog;
            MaximizeBox = false;
            MaximumSize = new Size(623, 888);
            MinimumSize = new Size(623, 888);
            Name = "FormView";
            Text = "DNPCSformtest";
            Shown += MainView_Shown;
            Paint += FormView_Paint;
            ResumeLayout(false);
        }

        #endregion

        private Button buttonStart;
        private Button buttonStop;
    }
}
