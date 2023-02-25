using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows;

namespace MIAPR_LAB1
{
    class KMeansAlgorithm
    {
        private Vector[] images;
        private Vector[] classes;
        private List<List<Vector>> colorClasses = new List<List<Vector>>();
        private Graphics graphics;
        
        public KMeansAlgorithm(string imagesCount, string classesCount, Graphics panelGraphics)
        {   
            images = new Vector[Int32.Parse(imagesCount)];
            classes = new Vector[Int32.Parse(classesCount)];
            graphics = panelGraphics;
        }
        public void prepareAlgorithm()
        {
            setValues();
            draw();
        }
        public void runAlgorithm()
        {
            Vector old = new Vector(-10, -10);
            while (Math.Abs(old.X - classes[0].X + old.Y - classes[0].Y) > 0.1)
            {
                old = classes[0];
                for (int i = 0; i < classes.Length; i++)
                {
                    classes[i] = moveClass(i);
                }
                draw();
            }
        }
        private void draw()
        {
            SolidBrush brush = new SolidBrush(Color.Black);

            graphics.Clear(Color.Black);
            for (int i = 0; i < classes.Length; i++)
            {
                brush.Color = Color.FromKnownColor(KnownColor.SpringGreen + i);
                graphics.FillRectangle(brush, (float)classes[i].X, (float)classes[i].Y, 6, 6);
            }
            for (int i = 0; i < images.Length; i++)
            {
                brush.Color = checkDistance(i);
                graphics.FillRectangle(brush, (float)images[i].X, (float)images[i].Y, 1, 1);
            }
        }
        private void setValues()
        {
            Random random = new Random();
            for (int i = 0; i < images.Length; i++)
            {
                images[i].X = random.Next(0 + 1, 517 - 1);
                images[i].Y = random.Next(0 + 1, 410 - 1);
            }
            for (int i = 0; i < classes.Length; i++)
            {
                classes[i].X = random.Next(0 + 6, 517 - 6);
                classes[i].Y = random.Next(0 + 6, 410 - 6);
                colorClasses.Add(new List<Vector>());
            }
        }
        private Vector moveClass(int classIndex)
        {
            Vector newPos = new Vector(0, 0);

            foreach (var dot in colorClasses[classIndex])
            {
                newPos += dot;
            }

            return newPos / colorClasses[classIndex].Count;
        }
        private Color checkDistance(int imageNumber)
        {
            Vector imgVector = images[imageNumber] - classes[0];
            Vector currVector;
            int colorbias = 0;

            for (int j = 0; j < classes.Length; j++)
            {
                currVector = images[imageNumber] - classes[j];
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