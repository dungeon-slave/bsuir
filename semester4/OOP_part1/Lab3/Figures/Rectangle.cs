namespace LB3
{
    class Rectangle: AbstractFigure
    {
        public override bool IsFigure(float coordX, float coordY)
        {
            return Math.Abs(coordX + coordX0) + Math.Abs(coordY + coordY0) <= 0.8; //Math.Abs(coordX) + Math.Abs(coordY) <= D/2
        }
    }
}