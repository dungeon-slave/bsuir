/*
Преобразовать выражение в обратную польскую запись используя стек. 
Использовать алгоритм с относительным и стековым приоритетом. 
Введённое выражение содержит вложенные скобки и двойные степени (х^у у^z) и считаем ранг
*/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 64

#include <stdio.h>
#include "Functions.h"

main()
{
	unsigned int act;
	char exprsn[SIZE] = "";
	TPStack stackPtr = NULL;

	do
	{
		printf("Input expression: ");
		scanf_s("%s", exprsn, SIZE);
		scanStr(&stackPtr, exprsn);
		printf("Reverse         : %s\n", Reverse);
		calcRank(Reverse);
		strcpy(Reverse, "");

		printf("Continue? 1 - yes, 0 - no\n");
		scanf_s("%d", &act); printf("\n");
	} while (act != 0);
}
