package Task2;
import java.util.Scanner;

public class Point 
{
    public double x;
    public double y;

    public void GetCoordinates()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input x: ");
        x = scanner.nextDouble();
        System.out.print("Input y: ");
        y = scanner.nextDouble();
        scanner.close();
    }
}