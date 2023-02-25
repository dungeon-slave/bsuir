/*
	������� ���������������� ������� � ������� � ��������� �� �50 �� +50. 
	����� �������� ������� ��������� �������������� �������. 
	� ����� ������ ��� ������� ������ ���� �������.

	25.	 �������� ������� ������ � ��������� �������� �������.
*/
#define SIZE 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Queue
{
	int num;
	struct Queue* nextPtr;
};

typedef struct Queue TQueue;
typedef TQueue* TPQueue;

void addElement(TPQueue*, TPQueue*, int);
void delElement(TPQueue*, TPQueue*);
void printQueue(TPQueue);
void fillQueue(TPQueue*, TPQueue*);
void clearQueue(TPQueue*, TPQueue*);
void Swap(TPQueue*, TPQueue*);
void Actions();

main()
{
	TPQueue headPtr = NULL, tailPtr = NULL;
	unsigned int act;

	do
	{
		Actions();
		scanf_s("%d", &act); printf("\n");
		switch (act)
		{
		case 1:
			fillQueue(&headPtr, &tailPtr);
			break;
		case 2:
			printQueue(headPtr);
			break;
		case 3:
			Swap(&headPtr,&tailPtr);
			break;
		case 4:
			clearQueue(&headPtr, &tailPtr);
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
		printf("Continue? 1 - yes, 0 - no\n");
		scanf_s("%d", &act); printf("\n");
	} while (act != 0);
}

void addElement(TPQueue* headPtr, TPQueue* tailPtr, int numb)
{
	TPQueue newPtr;

	newPtr = malloc(sizeof(TQueue));

	if (newPtr != NULL)
	{
		newPtr->num = numb;

		if (*headPtr == NULL)
		{
			*headPtr = newPtr;
		}
		else
		{
			(*tailPtr)->nextPtr = newPtr;
		}
		*tailPtr = newPtr;
		(*tailPtr)->nextPtr = NULL;
	}
	else
	{
		printf("%d not inserted.\n", numb);
	}
}

void delElement(TPQueue* headPtr, TPQueue* tailPtr)
{
	TPQueue tmpPtr;

	tmpPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
	{
		*tailPtr = NULL;
	}

	free(tmpPtr);
}

void printQueue(TPQueue headPtr)
{
	int count = 0;

	if (headPtr == NULL)
	{
		printf("The queue is empty!\n\n");
	}
	else
	{
		printf("The queue is: \n");

		while (headPtr != NULL)
		{
			printf(" %d ", headPtr->num);
			headPtr = headPtr->nextPtr;
			count++;
			if (headPtr == NULL)
			{
				count--;
			}
		}
		count--;
		printf("\n");
		printf("count: %d\n", count);
		//printf(" NULL\n\n");
	}
}

void fillQueue(TPQueue* headPtr, TPQueue* tailPtr)
{
	int numb;

	srand((unsigned int)time(NULL));
	for (size_t i = 0; i <= SIZE; i++)
	{
		numb = -50 + rand() % (101); //x = a + rand() % (b - a + 1)
		addElement(&(*headPtr), &(*tailPtr), numb);
	}

	printf("Queue is filled.\n");
}

void clearQueue(TPQueue* headPtr, TPQueue* tailPtr)
{
	while (*headPtr != NULL)
	{
		delElement(&(*headPtr), &(*tailPtr));
	}
	printf("Queue cleared.\n");
}

void Swap(TPQueue* headPtr, TPQueue* tailPtr)
{
	int tmpNum;

	tmpNum = (*headPtr)->num;
	(*headPtr)->num = (*tailPtr)->num;
	(*tailPtr)->num = tmpNum;

	printf("Elements swaped.\n");
}

void Actions()
{
	printf("1. Fill queue \n"
		   "2. Print queue \n"
		   "3. Swap first and last \n"
		   "4. Clear queue\n"
		   " Choose action: ");
}