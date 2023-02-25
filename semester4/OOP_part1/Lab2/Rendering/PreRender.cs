namespace NM1
{
    class PreRender
    {
        private protected const int windowWidth  = 120, windowHeight = 40;
        private protected const float charAspect = 7.0f / 16.0f, windowAspect = (float)windowWidth / windowHeight;

        public delegate bool IsFigure(float coordX, float coordY);

        /*public void ConsolePreparing()
        {
            Console.BufferWidth = windowWidth * 2;
            Console.BufferHeight = windowHeight * 10;
            Console.WindowWidth = windowWidth; //Max - 213
            Console.WindowHeight = windowHeight; //Max - 49
            //Console.SetWindowSize(windowWidth, windowHeight);
        }*/
    }
}