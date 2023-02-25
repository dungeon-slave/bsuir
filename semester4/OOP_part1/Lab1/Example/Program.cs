class Program
{
    static void Main()
    {
        FiguresList List = new();

        List.AddToList(new Dot(0, 0));
        List.AddToList(new Line(0f, 0f));
        List.AddToList(new Circle(0f, 0f));
        List.AddToList(new Rectangle(0f, 0f));
        List.AddToList(new Treangle(0f, 0f));
        List.AddToList(new Rhombus(0f, 0f));    

        List.PrintList(new Render());

        System.Console.ReadLine();
    }
}