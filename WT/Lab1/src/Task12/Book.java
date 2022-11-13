package Task12;

public class Book 
{
    private String title;
    private String author;
    private int price;
    private static int edition;

    @Override
    public boolean equals(Object arg0) { return true; }
    @Override
    public int hashCode() { return 1; }
    @Override 
    public String toString() { return ""; }
}