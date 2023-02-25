namespace NM1
{
    class Dot: AbstractFigure 
    {
        public override bool IsFigure(float coordX, float coordY)
        {
            return (coordX == coordX0) && (coordY == coordY0); //(coordX == X0) && (coordY == Y0)
        }
    }
}