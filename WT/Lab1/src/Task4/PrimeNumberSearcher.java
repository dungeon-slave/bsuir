package Task4;
import java.math.BigInteger;
import java.util.Scanner;

public class PrimeNumberSearcher 
{
    static int N;
    static int[] NumbersArray;

    public static void main(String[] args) 
    {
        GetNumbers();
        FindPrimeNumbers();
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
    private static void FindPrimeNumbers()
    {
        for (int i = 0; i < NumbersArray.length; i++) 
        {
            if (BigInteger.valueOf(NumbersArray[i]).isProbablePrime(NumbersArray[i])) 
            {
                System.out.println(i);
            }
        }
    }
}