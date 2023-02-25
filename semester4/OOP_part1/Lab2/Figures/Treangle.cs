namespace NM1
{
    class Treangle: AbstractFigure
    {
        public override bool IsFigure(float coordX, float coordY)
        {
            return (Math.Abs(coordX + coordX0) + Math.Abs(coordY + coordY0) <= 1.0) && (coordY + coordY0 < 0); //
        }
    }
}