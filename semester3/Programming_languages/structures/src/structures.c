/*
	В магазине составлен список людей, которым выдана карта постоянного покупателя. 
	Каждая запись этого списка содержит номер карточки, ФИО, предоставляемую скидку. 
	Вывести информацию о покупателях, имеющих 10 %-ную скидку в магазине.
*/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#define FIOSIZE 50

#include <stdio.h>
#include <string.h>

struct TList
{
	unsigned int Num;
	char Flname[FIOSIZE];
	unsigned int dsc;
} List[SIZE];

void Actions();
void ShowList(TList);
void AddElement(TList);
void DelElement(TList);
void Task(TList);

main()
{
	unsigned int act;

	do
	{
		Actions();
		scanf_s("%u", &act); printf("\n");

		switch (act)
		{
			case 1:
				ShowList(List);
				break;
			case 2:
				while (getchar() != '\n');
				AddElement(List);
				break;
			case 3:
				DelElement(List);
				break;
			case 4:
				Task(List);
				break;
			default:
				printf("Invalid action!\n");
				break;
		}

		printf("Continue? 1 - yes, 0 - no\n");
		scanf_s("%d", &act); printf("\n");
	} while (act != 0);
}

void Actions()
{
	printf(" 1. Show list\n"
		   " 2. Add customer\n"
		   " 3. Delete customer\n" 
		   " 4. Show customers with 10%% discount\n\n Choose action: ");
}

void ShowList(TList)
{
	int bool = 0;

	printf("                           LIST OF CUSTOMERS\n");
	printf("-------------------------------------------------------------------------\n");

	for (unsigned int i = 0; i < SIZE; i++)
	{
		if (List[i].dsc != 0) 
		{
			bool++;
			printf("Full name  : %s\nDiscount   : %d\nCard number: %d\n", List[i].Flname, List[i].dsc, List[i].Num);
			printf("-------------------------------------------------------------------------\n");	
		}
	}
	printf("\n");
	
	if (bool == 0)
	{
		printf("The list is empty!\n");
	}
}

void AddElement(TList)
{
	unsigned int pos = -1;

	for (unsigned int i = 0; i < SIZE; i++)
	{
		if (List[i].dsc == 0) 
		{ 
			pos = i;
			break;
		}
	}

	if (pos == -1)
	{
		printf("WARNING, THE LIST IS FULL!\n");
	}
	else
	{
		printf("Input full name: ");
		gets_s(List[pos].Flname, FIOSIZE); 
		
		printf("Input discount(in %%): ");
		scanf_s("%d", &List[pos].dsc);
		while (getchar() != '\n');
		//List[pos].Num = pos;
		
		printf("Input card number: ");
		scanf_s("%d", &List[pos].Num); 
		printf("\nCustomer is added.\n\n");
	}
}

void DelElement(TList)
{
	unsigned int num;

	printf("Input number of customer: ");
	scanf_s("%u", &num); printf("\n");

	if (List[num-1].dsc == 0)
	{
		printf("THERE IS NO SUCH CUSTOMER IN THE LIST!\n");
	}
	else
	{
		strcpy(List[num-1].Flname, "");
		List[num-1].dsc = 0;
		List[num-1].Num = 0;
	}
	
}

void Task(TList)
{
	int bool = 0;

	printf("                    LIST OF CUSTOMERS WITH 10%% DISCOUNT\n");
	printf("-------------------------------------------------------------------------\n");

	for (unsigned int i = 0; i < SIZE; i++)
	{
		if (List[i].dsc == 10)
		{
			bool++;
			printf("Full name  : %s\nDiscount   : %d\nCard number: %d\n", List[i].Flname, List[i].dsc, List[i].Num);
			printf("-------------------------------------------------------------------------\n");
		}
	}
	printf("\n");

	if (bool == 0)
	{
		printf("The list is empty!\n");
	}
	else
	{
		printf("Number of customers: %d\n", bool);
	}
}