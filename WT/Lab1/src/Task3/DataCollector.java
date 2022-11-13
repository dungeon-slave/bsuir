package Task3;
import java.util.Scanner;

public class DataCollector 
{
    static public double a;
    static public double b;
    static public double h;

    public static void GetData()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input a: ");
        a = scanner.nextDouble();
        System.out.print("Input b: ");
        b = scanner.nextDouble();
        System.out.print("Input h: ");
        h = scanner.nextDouble();
        scanner.close();
    }
}