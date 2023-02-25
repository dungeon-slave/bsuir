/*
	Корректный идентификатор: начинается с буквы или нижнего подчёркивания, 
	затем — произвольное количество букв, цифр и/или нижних подчёркиваний.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "Header.h"

int count = 0;

main()
{
	unsigned int act = 1;

	do
	{
		char S[SIZE] = "";

		switch (act)
		{
		case 1:
		{
			inputString(S);
			isCorrect(S);
			printf("Count: %d", count);
			break;
		}
		default:
			printf("Invalid choice.\n");
			break;
		}
		printf("\nContinue? 1 - yes, 0 - no\n");
		scanf_s("%u", &act); getchar();
		printf("\n");
	} while (act != 0);
}



void inputString(char S[])
{
	printf("Input string: "); 
	gets_s(S, SIZE); printf("\n");
}

void isCorrect(char S[])
{
	if (!searchSubStrs(S))
	{
		printf("STRING IS NOT CORRECT!");
	}
}

TBool searchSubStrs(char S[])
{
	char* SubS; 
	TBool bool = FALSE;

	SubS = strtok(S, " ");

	while (SubS != NULL)
	{
		if (checkString(SubS))
		{
			printf(" Substring: %s\n", SubS);
			bool = TRUE;
			count++;
		}
		SubS = strtok(NULL, " ");
	}

	return bool;
}

TBool checkString(const char S[])
{
	int State = 1;

	for (size_t i = 0; i < strlen(S); i++) 
	{ 
		State = Transitions[State][getCharType(S[i])];
	}

	return IsFinalState[State];
}

int getCharType(const char C)
{
	if (C == '_')
	{
		return ctSpecSymb;
	}

	if (C >= '0' && C <= '9')
	{
		return ctDigit;
	}

	if ((C >= 'A' && C <= 'Z') || (C >= 'a' && C <= 'z'))
	{
		return ctLetter;
	}

	return ctUnknown;
}