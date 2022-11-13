package Task91011;

public class Ball 
{
    private static String[] colors = {"RED", "GREEN", "BLUE"};
    private final int weight = 15;
    private String color;

    public String GetColor()  { return this.color; }
    public int    GetWeight() { return this.weight; }

    public Ball(int colornumb)
    {
        this.color = colors[colornumb];
    }
}