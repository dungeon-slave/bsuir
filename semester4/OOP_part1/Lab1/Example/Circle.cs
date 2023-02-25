class Circle: Dot
{
    public Circle(float coordX0, float coordY0) : base(coordX0, coordY0)
    {
        this.coordX0 = coordX0;
        this.coordY0 = coordY0;
    }
    public override bool IsFigure(float coordX, float coordY)
    {
        coordX += coordX0;
        coordY += coordY0;
        return (coordX * coordX) + (coordY * coordY) <= 0.5; //(coordX * coordX) + (coordY * coordY) <= R^2
    }
}