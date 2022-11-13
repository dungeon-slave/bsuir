package Task6;
import java.util.Scanner;

public class SquareMatrixBuilder 
{
    static int N;
    static int[][] Matrix;

    public static void main(String[] args) 
    {
        GetElements();
        PrintMAtrix();    
    }
    static void GetElements()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input size of matrix: ");
        N = scanner.nextInt();

        Matrix = new int[N][N];
        int pos;
        for (int i = 0, len = Matrix.length - 1; i <= len; i++) 
        {
            System.out.printf("a[%d] = ", i);
            Matrix[0][i] = scanner.nextInt();     
            for (int j = 1; j <= len; j++) 
            {
                pos = i - j;
                if(pos < 0) { pos = Matrix.length + pos; }
                Matrix[j][pos] = Matrix[0][i];
            }
        }

        scanner.close();
    }
    static void PrintMAtrix()
    {
        for (int i = 0; i < Matrix.length; i++) 
        {
            System.out.print("\n");
            for (int j = 0; j < Matrix.length; j++) 
            {
                System.out.print(" " + Matrix[i][j] + " ");
            }
        }
    } 
}