namespace NM1
{
    class FigureList
    {
        private List<AbstractFigure> figureList = new();
        public void AddToList(AbstractFigure Figure)
        {
            figureList.Add(Figure);
        }
        public void PrintFigures(Render Rn)
        {
            for(int i = 0, len = figureList.Count; i < len; i++)
            {
                System.Console.WriteLine(Rn.RenderFrame(figureList[i].IsFigure));
            }
        }
    }
}