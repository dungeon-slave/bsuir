package Task3;

public class FuncExpressionSolver 
{
    public static void main(String[] args) 
    {
        DataCollector.GetData();
        FuncExpressionSolver.CalcFunction(DataCollector.a, DataCollector.b, DataCollector.h);
    }
    private static void CalcFunction(double a, double b, double h)
    {
        double x = a;
        double func;

        do 
        {
            func = Math.tan(x);
            FuncExpressionSolver.PrintTableLine(x, func);
            x += h;
        } while (x <= b);
    }
    private static void PrintTableLine(double x, double func)
    {
        System.out.printf("|  x = %.2f  |  F(x)  = %6.2f  |\n", x, func);
    }
}