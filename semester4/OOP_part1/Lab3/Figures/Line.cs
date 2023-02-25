namespace LB3
{
    class Line: AbstractFigure
    {
        public override bool IsFigure(float coordX, float coordY)
        {
            return Math.Abs(coordY + coordY0) == 0.00; //Math.Abs(coordX) == X0/Math.Abs(coordY) == Y0 - Линия
        }
    }
}