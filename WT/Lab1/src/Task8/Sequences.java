package Task8;
import java.util.Scanner;

public class Sequences 
{
    private static int[] SequenceA;
    private static int[] SequenceB;

    public static void main(String[] args) 
    {
        FillSequence(SequenceA);
        FillSequence(SequenceB);
    }
    private static void FillSequence(int[] Sequence)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input size of Sequence: ");
        int size = scanner.nextInt();

        Sequence = new int[size];
        for (int i = 0; i < Sequence.length; i++) 
        {
            System.out.printf("Sequence[%d] = ", i);
            Sequence[i] = scanner.nextInt();
        }

        scanner.close();
    }
}
