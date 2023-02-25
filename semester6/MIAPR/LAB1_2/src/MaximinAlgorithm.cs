using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows;

namespace MIAPR_LAB1
{
    class MaximinAlgorithm
    {
        private List<Vector> images = new List<Vector>();
        private List<Vector> cores = new List<Vector>();
        private List<List<Vector>> colorClasses = new List<List<Vector>>();
        private Graphics graphics;
        public MaximinAlgorithm(string imagesCount, Graphics graphics)
        {
            setImages(Int32.Parse(imagesCount));
            this.graphics = graphics;
        }
        public void runAlgorithm()
        {
            cores.Add(images[new Random().Next(images.Count - 1)]);
            colorClasses.Add(new List<Vector>());
            draw();
        }
        private void setImages(int imagesCount)
        {
            Random random = new Random();
            for (int i = 0; i < imagesCount; i++)
            {
                images.Add(new Vector(random.Next(0 + 1, 517 - 1), random.Next(0 + 1, 410 - 1)));
            }
        }
        private void draw()
        {
            graphics.Clear(Color.Black);

            SolidBrush brush = new SolidBrush(Color.Yellow);
            while (!setCores())
            {
                for (int i = 0; i < images.Count; i++)
                {
                    brush.Color = checkDistance(i);
                    graphics.FillRectangle(brush, (float)images[i].X, (float)images[i].Y, 1, 1);
                }
                for (int i = 0; i < cores.Count; i++)
                {
                    brush.Color = Color.FromKnownColor(KnownColor.SpringGreen + i);
                    graphics.FillRectangle(brush, (float)cores[i].X, (float)cores[i].Y, 6, 6);
                }
            }
        }
        private bool setCores()
        {
            if (cores.Count < 2)
            {
                cores.Add(findFurtherImage(images, cores[0]));
                colorClasses.Add(new List<Vector>());
                return false;
            }
            else
            {
                Vector furtherImage = findFurtherImage(colorClasses[0], cores[0]);
                for (int i = 0; i < colorClasses.Count; i++)
                {
                    Vector currImage = findFurtherImage(colorClasses[i], cores[i]);
                    furtherImage = furtherImage.Length > currImage.Length ? currImage : furtherImage;
                }
                if (furtherImage.Length > calcCoresAverage().Length / 2)
                {
                    cores.Add(furtherImage);
                    colorClasses.Add(new List<Vector>());
                    return false;
                }
            }
            return true;
        }
        private Vector calcCoresAverage()
        {
            Vector average = new Vector(0, 0);
            foreach (Vector core in cores)
            {
                average += core;
            }

            return average / cores.Count;
        }
        private Vector findFurtherImage(List<Vector> images, Vector core)
        {
            if (images.Count != 0)
            {
                Vector furtherImage = images[0];
                for (int i = 0; i < images.Count; i++)
                {
                    furtherImage = (furtherImage - core).Length < (images[i] - core).Length ? images[i] : furtherImage;
                }
                return furtherImage;
            }
            return new Vector(0, 0); 
        }
        private Color checkDistance(int imageNumber)
        {
            Vector imgVector = images[imageNumber] - cores[0];
            Vector currVector;
            int colorbias = 0;

            for (int j = 0; j < cores.Count; j++)
            {
                currVector = images[imageNumber] - cores[j];
                if (currVector.Length < imgVector.Length)
                {
                    imgVector = currVector;
                    colorbias = j;
                }
            }
            colorClasses[colorbias].Add(images[imageNumber]);

            return Color.FromKnownColor(KnownColor.SpringGreen + colorbias);
        }
    }
}