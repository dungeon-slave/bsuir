package Task91011;
import java.util.ArrayList;

public class Basket 
{
    private ArrayList<Ball> BallsList = new ArrayList<Ball>(); 
    private int wholeWeight = 0;
    private int blueCount = 0;
    
    public static void main(String[] args) 
    {
        Basket basket = new Basket();   

        basket.FillBasket(); 
        basket.CalcParameters();
        basket.PrintParameters();
    }
    private void FillBasket()
    {
        int count = (int)(Math.random() * 10);
        int color;
        
        for (int i = 0; i < count; i++) 
        {
            color = (int)(1 + Math.random() * 2);
            BallsList.add(new Ball(color));
        }
    }
    private void CalcParameters()
    {
        for (Ball currBall : BallsList) 
        {
            wholeWeight += currBall.GetWeight();
            if (currBall.GetColor() == "BLUE") { blueCount += 1; }    
        }
    }
    private void PrintParameters()
    {
        System.out.printf("The weight of all balls is %d\nCount of blue balls is %d\n", wholeWeight, blueCount);
    }
}