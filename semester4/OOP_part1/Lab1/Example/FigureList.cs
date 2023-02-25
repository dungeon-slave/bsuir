class FiguresList
{
    private List<Dot> FigList = new List<Dot>();

    public void AddToList(Dot Figure)
    {
        FigList.Add(Figure);
    }

    public void PrintList(Render Rn)
    {
        for(int i = 0, len = FigList.Count; i < len; i++)
        {
            System.Console.WriteLine(Rn.FrameRendering(FigList[i].IsFigure));
        }
    }
}