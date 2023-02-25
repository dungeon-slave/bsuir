using LB3.Figures;
using System.Reflection;

namespace LB3
{
    class ClassHierarchy
    {
        List<Type> ClassList = new(Assembly.GetExecutingAssembly().GetTypes().Where(x => 
                                    x.IsAssignableTo(typeof(AbstractFigure)) && x != typeof(AbstractFigure)).ToList());

        List<AbstractFigure> FigureList = new();

        void CreateInput()
        {
            for (int i = 0, count = ClassList.Count; i < count; i++)
            {
                Console.WriteLine($"{ClassList[i]}");
            }
        }

        AbstractFigure? ChooseFigure()
        {   
            string? strType = null;
            Type? currType = null; 
            
            while (currType == null)
            {
                CreateInput();
                strType = Console.ReadLine();
                currType = Type.GetType(strType);
            }
            
            if (currType.IsAssignableTo(typeof(AbstractFigure)))
            {
                return (AbstractFigure)Activator.CreateInstance(currType);
            }
            
            return null;
        }
        
        public void AddToFL(FigureList FL)
        {
            short act = 0;
            AbstractFigure? CurrFig;
            
            while (act != 1)
            {
                CurrFig = ChooseFigure();
                if (CurrFig != null)
                {
                    FL.AddToList(CurrFig);
                }
                else
                {
                    Console.WriteLine("FIGURE NOT ADDED!");
                }
                Console.WriteLine("Add figure? 0 - yes, 1 - no");
                act = Convert.ToInt16(Console.ReadLine());
            }
        }
    }
}