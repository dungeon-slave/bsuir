namespace NM1
{
    class Render: PreRender
    {
        public char[] RenderFrame(IsFigure Figure)
        {
            float coordX, coordY;
            char[] Screen = new char[windowWidth * windowHeight + 1];

            for (int i = 0; i < windowWidth; i++)
            {
                for (int j = 0; j < windowHeight; j++)
                {
                    coordX = (float)i / windowWidth * 2.0f - 1.0f;
                    coordY = (float)j / windowHeight * 2.0f - 1.0f;
                    coordX *= charAspect * windowAspect;

                    if (Figure(coordX, coordY))
                    {
                        Screen[i + j * windowWidth] = '@';
                    }
                    else
                    {
                        Screen[i + j * windowWidth] = ' ';
                    }
                }
            }
            return Screen;
        }
    }
}