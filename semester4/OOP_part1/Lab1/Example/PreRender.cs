class PreRender
{
    public const int windowWidth  = 120,
                     windowHeight = 30;

    public const float charAspect   = 7.0f / 16.0f,
                       windowAspect = (float)windowWidth / windowHeight;

    public delegate bool TypeFigure(float coordX, float coordY);

    //static private void ConsolePreparing()
    //{
    //    Console.SetWindowSize(windowWidth, windowHeight);
    //}
}