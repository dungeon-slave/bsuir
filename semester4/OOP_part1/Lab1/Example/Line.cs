class Line: Dot
{
    public Line(float coordX0, float coordY0): base(coordX0, coordY0)
    {
        this.coordX0 = coordX0;
        this.coordY0 = coordY0;
    }
    public override bool IsFigure(float coordX, float coordY)
    {
        return Math.Abs(coordY + coordY0) == 0.00; //Math.Abs(coordX) == X0/Math.Abs(coordY) == Y0 - Линия
    }
}