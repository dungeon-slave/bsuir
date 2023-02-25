/*
В данной действительной матрице размером 6*6 поменять местами строку, 
содержащую элемент с наибольшим значением, со строкой, содержащей элемент с наименьшим значением. 
Предполагается, что эти элементы единственны.
*/
#define SIZE 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	double arr[SIZE][SIZE] = { 0 }, max, min, temp = 0;

	srand((unsigned int)time(0));
	for (size_t i = 0; i <= SIZE-1; i++)
	{
		printf("\n \n");
		for (size_t j = 0; j <= SIZE-1; j++)
		{
			arr[i][j] = (rand() - 0.5) / rand() + 10.0; //min + rand(max - min + 1)
			printf("%.2f  ",arr[i][j]);
		}
	}
	printf("\n \n");

	min = max = arr[0][0];
	for (size_t i = 0; i <= SIZE-1; i++)
	{
		for (size_t j = 0; j <= SIZE-1; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}

			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	printf("Min = %.2f \n", min);
	printf("Max = %.2f \n", max);

	for (size_t i = 0; i <= SIZE-1; i++)
	{
		for (size_t j = 0; j <= SIZE-1; j++)
		{
			if (arr[i][j] == min)
			{
				min = i;
			}

			if (arr[i][j] == max)
			{
				max = i;
			}
		}
	}

	for (size_t j = 0; j <= SIZE-1; j++)
	{
		temp = arr[(int)min][j];
		arr[(int)min][j] = arr[(int)max][j];
		arr[(int)max][j] = temp;
	}
	
	for (size_t i = 0; i <= SIZE-1; i++)
	{
		printf("\n \n");
		for (size_t j = 0; j <= SIZE-1; j++)
		{
			printf("%.2f  ",arr[i][j]);
		}
	}
	printf("\n");
}