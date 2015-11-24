namespace RobotControllerUI
{
    partial class InteractiveUI
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.GraphicView = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // GraphicView
            // 
            this.GraphicView.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.GraphicView.Location = new System.Drawing.Point(2, 3);
            this.GraphicView.Name = "GraphicView";
            this.GraphicView.Size = new System.Drawing.Size(654, 535);
            this.GraphicView.TabIndex = 0;
            this.GraphicView.Paint += new System.Windows.Forms.PaintEventHandler(this.GraphicView_Paint);
            // 
            // InteractiveUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(943, 646);
            this.Controls.Add(this.GraphicView);
            this.Name = "InteractiveUI";
            this.Text = "AddON";
            this.Load += new System.EventHandler(this.InteractiveUI_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel GraphicView;
    }
}

