/*
	—оздать стек с числами в диапазоне от Ц50 до +50.
	Ќайти максимальное и минимальное значени€ стека.
	¬ конце работы все стеки должны быть удалены.
*/
#define SIZE 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Stack
{
	int number;
	struct Stack* nextPtr;	
}; 

typedef struct Stack TStack;
typedef TStack* TPStack;

void Push(TPStack*, int);
void Pop(TPStack*);
void fillStack(TPStack*);
void clearStack(TPStack*);
void Search(TPStack);
void printStack(TPStack);
void Actions();

main()
{
	TPStack stackPtr = NULL;
	unsigned int act;

	do
	{
		Actions();
		scanf_s("%d", &act); printf("\n");
		switch (act)
		{
			case 1:
				fillStack(&stackPtr);
				break;
			case 2:
				printStack(stackPtr);
				break;
			case 3:
				Search(stackPtr);
				break;
			case 4:
				clearStack(&stackPtr);
				break;
			default:
				printf("Invalid choice.\n");
				break;
		}
		printf("Continue? 1 - yes, 0 - no\n");
		scanf_s("%d", &act); printf("\n");
	} while (act != 0);
}

void Push(TPStack *Ptr, int Num)
{
	TPStack newPtr;

	newPtr = malloc(sizeof(TStack));
	if (newPtr != NULL)
	{
		newPtr->number = Num;
		newPtr->nextPtr = *Ptr;
		*Ptr = newPtr;
	}
	else
	{
		printf("INSERT ERROR!");
	}
}

void Pop(TPStack *Ptr)
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

void fillStack(TPStack* stackPtr)
{
	int numb, count = 0;

	srand((unsigned int)time(NULL));
	for (size_t i = 0; i <= SIZE; i++)
	{
		numb = -50 + rand() % (101); //x = a + rand() % (b - a + 1)
		//numb = 10;
		Push(&(*stackPtr), numb);
		count++;
	}
	//printf("Stack is filled.\n"
		//	"%d\n",count);
}

void clearStack(TPStack* stackPtr)
{
	while ((*stackPtr) != NULL)
	{
		Pop(&(*stackPtr));
	}
	printf("Stack cleared.\n");
}

void printStack(TPStack stackPtr)
{
	int count = 0;

	if (stackPtr == NULL)
	{
		printf("The stack is empty! \n");
	}
	else
	{
		printf("The stack: \n");
		while (stackPtr != NULL)
		{
			printf("%3d \n", stackPtr->number);
			stackPtr = stackPtr->nextPtr;
			count++;
		}
		printf("NULL \n");
	}
	printf("%d\n", count);
}

void Search(TPStack stackPtr)
{
	int min, max;

	if (stackPtr != NULL)
	{
		min = max = stackPtr->number;
		while (stackPtr != NULL)
		{
			if (stackPtr->number > max)
			{
				max = stackPtr->number;
			}

			if (stackPtr->number < min)
			{
				min = stackPtr->number;
			}

			stackPtr = stackPtr->nextPtr;
		}
		printf("min = %d, max = %d \n", min,max);
	}
	else
	{
		printf("There are no max and min elements.\n");
	}

}

void Actions()
{
	printf("1. Fill the stack \n"
		   "2. Print stack \n"
		   "3. Show min and max \n"
		   "4. Clear stack\n" 
			 "Choose action: ");
}