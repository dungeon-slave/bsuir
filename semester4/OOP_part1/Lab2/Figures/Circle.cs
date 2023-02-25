namespace NM1
{
    class Circle: AbstractFigure
    {
        public override bool IsFigure(float coordX, float coordY)
        {
            coordX += coordX0;
            coordY += coordY0;
            return (coordX * coordX) + (coordY * coordY) <= 0.5; //(coordX * coordX) + (coordY * coordY) <= R^2
        }
    }
}