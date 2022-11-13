package Task1;
import java.util.Scanner;

public class ExpressionSolver
{
    private double x;
    private double y;

    private void GetData()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input x: ");
        x = scanner.nextDouble();
        System.out.print("Input y: ");
        y = scanner.nextDouble();
        scanner.close();
    }
    private double Compute(double x, double y)
    {
        return (1 + Math.pow(Math.sin(x + y), 2)) / (2 + Math.abs(x - (2 * x / (1 + Math.pow(x, 2) * Math.pow(y, 2))))) + x;
    }
    public static void main(String[] args)
    {
        ExpressionSolver A1 = new ExpressionSolver();
        A1.GetData();
        System.out.println(A1.Compute(A1.x, A1.y));
    }
}