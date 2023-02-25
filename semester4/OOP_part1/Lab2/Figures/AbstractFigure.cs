namespace NM1
{
    abstract class AbstractFigure
    {
        protected float coordX0;
        protected float coordY0;
        public AbstractFigure()
        {
            this.coordX0 = 0.0f;
            this.coordY0 = 0.0f;
        }
        public AbstractFigure(float coordX, float coordY)
        {
            this.coordX0 = coordX;
            this.coordY0 = coordY;
        }
        public float CoordX0
        {
            set
            {
                coordX0 = value;
            }
        }
        public float CoordY0
        {
            set
            {
                coordY0 = value;
            }
        }
        public abstract bool IsFigure(float coordX, float coordY);
        }
}