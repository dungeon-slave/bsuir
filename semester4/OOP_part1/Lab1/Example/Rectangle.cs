class Rectangle: Dot
{
    public Rectangle(float coordX0, float coordY0) : base(coordX0, coordY0)
    {
        this.coordX0 = coordX0;
        this.coordY0 = coordY0;
    }
    public override bool IsFigure(float coordX, float coordY)
    {
        return Math.Abs(coordX + coordX0) + Math.Abs(coordY + coordY0) <= 0.8; //Math.Abs(coordX) + Math.Abs(coordY) <= D/2
    }
}