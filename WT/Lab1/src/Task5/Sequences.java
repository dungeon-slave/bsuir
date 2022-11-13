package Task5;
import java.util.Scanner;

public class Sequences 
{
    private static int N;
    private static int[] NumbersArray;

    public static void main(String[] args) 
    {
        GetNumbers();
    }
    private static void GetNumbers()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input size of array: ");
        N = scanner.nextInt();

        NumbersArray = new int[N];
        for (int i = 0; i < NumbersArray.length; i++) 
        {
            System.out.printf("NumbersArray[%d] = ", i);
            NumbersArray[i] = scanner.nextInt();
        }

        scanner.close();
    }
    private static void DropNumbers()
    {
        
    }
}