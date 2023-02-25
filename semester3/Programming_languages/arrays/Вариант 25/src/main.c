/*
25. Дана матрица размером 6*6. Найти сумму элементов, расположенных на главной и побочной диагоналях 
и их среднее арифметическое.
*/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void main()
{
	int arr[6][6] = { 0 }, Sd1 = 0, Sd2 = 0, z = 5;
	float Sa = 0.0;

	srand((unsigned int)time(0));
	for (short i = 0; i <= 5; i++)
	{
		//printf("\n");
		for (short j = 0; j <= 5; j++)
		{
			printf("arr = ");
			scanf_s("%d", &arr[i][j]); //x = a + rand() % (b - a + 1)
			printf("\n");
			//printf("%d ", arr[i][j]);
		}
	}
	printf("\n");

	for (short i = 0; i <= 5; i++)
	{
		for (short j = 0; j <= 5; j++)
		{
			if (i == j)
			{
				Sd1 = Sd1 + arr[i][j];
			}
		}

		Sd2 = Sd2 + arr[i][z];
		z--;
	}

	for (short i = 0; i <= 5; i++)
	{
		for (short j = 0; j <= 5; j++)
		{
			printf("%1d ", arr[i][j]);
		}
		printf("\n");
	}
	Sa = (float)(Sd1 + Sd2) / 2;
	printf("\nMain diagonal sum: %d\n", Sd1);
	printf("Side diagonal sum: %d\n", Sd2);
	printf("Average sum: %3.1f\n", Sa);
}