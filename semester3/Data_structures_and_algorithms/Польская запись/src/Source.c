/*
������������� ��������� � �������� �������� ������ ��������� ����. 
������������ �������� � ������������� � �������� �����������. 
�������� ��������� �������� ��������� ������ � ������� ������� (�^� �^z) � ������� ����
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
