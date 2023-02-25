namespace NM1
{
    class Program
    {
        static void Main()
        {
            FigureCreator FC = new();
            FigureList FL = new();

            FC.EditList(FL);
            FL.PrintFigures(new Render());

            System.Console.ReadLine();
        }
    }
}
