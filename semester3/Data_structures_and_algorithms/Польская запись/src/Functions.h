#pragma once

#include <string.h>
#include <stdlib.h>

struct Stack
{
	char data;
	int prior;
	struct Stack* nextPtr;
};

typedef struct Stack TStack;
typedef TStack* TPStack;

const char operations[7] = { '(', ')', '+', '-', '*', '/', '^'};
char Reverse[SIZE] = "";

void Pop(TPStack*);
void Push(TPStack*, char, int);
void scanStr(TPStack*, char[]);
void cmpPriority(TPStack*, int, char);
int  setPriority(char);
void calcRank(char[]);

void Pop(TPStack* Ptr)
{
	TPStack tmpPtr;

	if ((*Ptr) != NULL)
	{
		tmpPtr = *Ptr;
		*Ptr = (*Ptr)->nextPtr;
		free(tmpPtr);
	}
	else
	{
		printf("DELETE ERROR!\n");
	}
}

void Push(TPStack* Ptr, char symb, int value)
{
	TPStack newPtr;

	newPtr = malloc(sizeof(TStack));
	if (newPtr != NULL)
	{
		newPtr->data = symb;
		newPtr->prior = value;
		newPtr->nextPtr = *Ptr;
		*Ptr = newPtr;
	}
	else
	{
		printf("INSERT ERROR!");
	}
}

void scanStr(TPStack *Ptr, char Str[])
{
	int val;
	char symb[2] = "";

	for (size_t i = 0; i <= strlen(Str); i++)
	{
		symb[0] = Str[i];

		val = setPriority(symb[0]);
		if (val == 7)
		{
			strcat(Reverse, symb);
		}
		else
		{
			cmpPriority(&(*Ptr), val, symb[0]);
		}
	}
	while (*Ptr != NULL)
	{
		symb[0] = (*Ptr)->data;
		strcat(Reverse, symb);
		Pop(&(*Ptr));
	}
}

int  setPriority(char symb)
{
	for (size_t i = 0; i <= 6; i++)
	{
		if (symb == operations[i])
		{
			return i;
		}
	}
	return 7;
}

void cmpPriority(TPStack *Ptr, int value, char symb)
{
	char tmp[2] = "";

	switch (value)
	{
	case 1:
		do
		{
			tmp[0] = (*Ptr)->data;
			strcat(Reverse, tmp);
			Pop(&(*Ptr));
		} while ((*Ptr)->prior != 0);
		Pop(&(*Ptr));

		break;

	default:
		if ((*Ptr == NULL) || (value == 0) || (value > (*Ptr)->prior))
		{
			Push(&(*Ptr), symb, value);
		}
		else
		{
			while ((*Ptr) != NULL && (*Ptr)->prior >= value)
			{
				tmp[0] = (*Ptr)->data;
				strcat(Reverse, tmp);
				Pop(&(*Ptr));
			} 
			Push(&(*Ptr), symb, value);
		}

		break;
	}
}

void calcRank(char Str[])
{
	int val, rank = 0;

	for (size_t i = 0; i < strlen(Str); i++)
	{
		val = setPriority(Str[i]);

		if (val > 6)
		{
			rank++;
		}
		else
		{
			rank--;
		}
	}

	printf("Rank            : %d\n\n", rank);
}