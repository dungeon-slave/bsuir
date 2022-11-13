package Task7;
import java.util.Scanner;

public class ShellSorting
{
    private static int N;
    private static double[] DoubleArray;

    public static void main(String[] args) 
    {
        GetData();
        Sort();   
        PrintArray(); 
    }
    private static void GetData()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input array size: ");
        N = scanner.nextInt();

        DoubleArray = new double[N];
        for (int i = 0; i < DoubleArray.length; i++) 
        {
            System.out.printf("DoubleArray[%d] = ", i);
            DoubleArray[i] = scanner.nextDouble();
        }

        scanner.close();
    }
    private static void Sort()
    {
        double key;
        int j;

        for (int gap = DoubleArray.length / 2; gap > 0; gap /= 2) 
        {
            for (int i = gap; i < DoubleArray.length; i++) 
            {
                key = DoubleArray[i];
                j = i;
                while (j >= gap && DoubleArray[j - gap] > key) 
                {
                    DoubleArray[j] = DoubleArray[j - gap];
                    j -= gap;
                }
                DoubleArray[j] = key;
            }
        }
    }
    private static void PrintArray()
    {
        System.out.println("\n\n");
        for (int i = 0; i < DoubleArray.length; i++) 
        {
            System.out.printf("DoubleArray[%d] = %.1f\n", i, DoubleArray[i]);
        }
    }
}