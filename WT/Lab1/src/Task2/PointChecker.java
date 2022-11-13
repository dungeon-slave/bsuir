package Task2;

public class PointChecker
{    
    private void CheckPoint(Point PointToCheck)
    {
        if ((PointToCheck.y >= 0 && PointToCheck.y <= 5) && (PointToCheck.x >= -4 && PointToCheck.x <= 4) || 
            (PointToCheck.y <= 0 && PointToCheck.y >= -3) && (PointToCheck.x >= -6 && PointToCheck.x <= 6)) 
        {
            System.out.println("true");
        }
        else
        {
            System.out.println("false");
        }
    }
    public static void main(String[] args)
    {
        PointChecker pointChecker1 = new PointChecker();
        Point point1 = new Point();
        
        point1.GetCoordinates();
        pointChecker1.CheckPoint(point1);
    }
}