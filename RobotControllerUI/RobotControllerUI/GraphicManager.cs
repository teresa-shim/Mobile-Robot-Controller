using System;
using System.Drawing;
using System.Windows.Forms;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;

namespace RobotControllerUI
{
    /// <summary>
    /// DirectX Device를 가지고 있는 그리기 전용 클래스
    /// 싱글톤 클래스
    /// </summary>
    public class GraphicManager
    {
        private Device dx_Device = null;
        private static GraphicManager Instance = null;

        /// <summary>
        /// 싱글톤 클래스 접근자
        /// </summary>
        /// <returns>인스턴스 반환</returns>
        public static GraphicManager GetManager()
        {
            if (Instance == null)
            {
                Instance = new GraphicManager();
            }
            return Instance;
        }

        private GraphicManager() { }


        /// <summary>
        /// 다이렉트 X 초기화 함수
        /// </summary>
        /// <param name="hViewControl"> DirectX를 이용해서 Draw할 Control</param>
        public bool InitDX(Control hViewControl)
        {
            try
            {
                PresentParameters pp = new PresentParameters();
                pp.Windowed = true;
                pp.SwapEffect = SwapEffect.Discard;
                dx_Device = new Device(0, DeviceType.Hardware, hViewControl,
                                        CreateFlags.SoftwareVertexProcessing, pp);
                return true;
            }
            catch (DirectXException e)
            {
                return false;
            } 
        }
        /// <summary>
        /// Object들을 그리는 Render함수 등록된 Object들을 그리게 할것
        /// </summary>
        private void ObjectsRender()
        { }
        /// <summary>
        /// Object들의 동작처리
        /// </summary>
        private void ObjectAction()
        { }
        public void Render()
        {
            //배경 클리어
            dx_Device.Clear(ClearFlags.Target,
                            System.Drawing.Color.FromArgb(0,0, 255).ToArgb(),
                            1.0f,
                            0);
            dx_Device.BeginScene();
            //Object 동작 처리
            // Object들 그리기
            dx_Device.EndScene();
            dx_Device.Present();
        }
    }
}