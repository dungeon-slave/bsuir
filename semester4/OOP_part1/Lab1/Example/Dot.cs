class Dot
{
    public float coordX0, coordY0;
    public Dot(float coordX, float coordY)
    {
        this.coordX0 = coordX;
        this.coordY0 = coordY;
    }
    public virtual bool IsFigure(float coordX, float coordY)
    {
        return (coordX == coordX0) && (coordY == coordY0); //(coordX == X0) && (coordY == Y0)
    }
}