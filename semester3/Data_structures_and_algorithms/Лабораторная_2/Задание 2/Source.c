/*
	Построить однонаправленный линейный список абонентов телефонной станции, 
	содержащий ФИО и семизначный номер телефона.
		Составить процедуры определения:
		- по номеру телефона фамилии;
		- по фамилии списка номеров телефонов.
*/
#define SIZE 32
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List
{
	char num[SIZE];
	char name[SIZE];
	char surname[SIZE];
	struct List* nextPtr;
};

typedef struct List TList;
typedef TList* TPList;

void createList(TPList*);
//void sortList(TPList*);
void nameSearch(TPList);
void numberSearch(TPList);
void showList(TPList);
void Actions();

main()
{
	TPList headPtr = NULL;
	int act = 0;

	do
	{
		Actions();
		scanf_s("%d", &act);

		switch (act)
		{
			case 1:
				printf("\n");
				createList(&headPtr);
				break;
			case 2:
				printf("\n");
				showList(headPtr);
				break;
			case 3:
				printf("\n");
				numberSearch(headPtr);
				break;
			case 4:
				printf("\n");
				nameSearch(headPtr);
				break;
			default:
				printf("\n");
				printf("Invalid choice\n");
				break;
		}

		printf("Continue? 1 - yes, 0 - no\n"); scanf_s("%d", &act);
		printf("\n");
	} while (act != 0);
}

void createList(TPList* headPtr)
{
	TPList newPtr;

	newPtr = malloc(sizeof(TList));
	*headPtr = newPtr;
	if (*headPtr != NULL)
	{	
		int act1 = 0;

		do
		{	
			newPtr->nextPtr = malloc(sizeof(TList));
			newPtr = newPtr->nextPtr;

			printf("Input number : "); scanf_s("%s", newPtr->num, SIZE); 
			printf("\n");
			printf("Input name   : "); scanf_s("%s", newPtr->name, SIZE); 
			printf("Input surname: "); scanf_s("%s", newPtr->surname, SIZE);
			printf("\n");
			newPtr->nextPtr = NULL;

			printf("Add one more user? 1 - yes, 0 - no \n");
			printf(" Choose action: "); scanf_s("%d", &act1);
			printf("\n\n");
		} while (act1 != 0);
		printf("List created!\n");
	}
	else
	{
		printf("List already created!\n");
	}
}

/*void sortList(TPList* headPtr)
{
	TList arr[SIZE];
	TPList Pt = (*headPtr)->nextPtr, currPt, nextPt, headPt, tmpPt;
	char nm1[SIZE], nm2[SIZE], snm1[SIZE], snm2[SIZE], nametmp[SIZE], snametmp[SIZE];
	




	do
	{
		currPt = headPt = (*headPtr)->nextPtr;

		while (headPt != NULL)
		{
			nextPt = currPt->nextPtr;
			strcpy_s(nm2,  SIZE, currPt->name);
			strcpy_s(nm1,  SIZE, nextPt->name);
			strcpy_s(snm2, SIZE, currPt->surname);
			strcpy_s(snm1, SIZE, nextPt->surname);

			if ((int)nm1[0] < (int)nm2[0])
			{
			//	strcpy_s(nametmp,  SIZE, nm1);
			//	strcpy_s(snametmp, SIZE, snm1);
				if (nextPt->nextPtr != NULL)
				{
					tmpPt = nextPt->nextPtr;
					nextPt->nextPtr = currPt;
					currPt->nextPtr = tmpPt;
					tmpPt = nextPt;
					nextPt = currPt;
					currPt = tmpPt;
				}
				else
				{
					tmpPt = currPt;
					currPt = nextPt;
					currPt->nextPtr = tmpPt;
					tmpPt->nextPtr = NULL;
				}
				

			//	strcpy_s(nextPt->name, SIZE, currPt->name);
			//	strcpy_s(currPt->name, SIZE, nametmp);

			//	strcpy_s(nextPt->surname, SIZE, currPt->surname);
			//	strcpy_s(currPt->surname, SIZE, snametmp);
			}
			else
			{
				if ((int)nm1[0] == (int)nm2[0])
				{
					if ((int)snm1[0] < (int)snm2[0])
					{
						strcpy_s(nametmp,  SIZE, nm1);
						strcpy_s(snametmp, SIZE, snm1);

						strcpy_s(nextPt->name, SIZE, currPt->name);
						strcpy_s(currPt->name, SIZE, nametmp);

						strcpy_s(nextPt->surname, SIZE, currPt->surname);
						strcpy_s(currPt->surname, SIZE, snametmp);
					}
				}
				
			}
			//currPt = currPt->nextPtr;
			headPt = headPt->nextPtr;
		}

		Pt = Pt->nextPtr;
	} while (Pt != NULL);
}*/

void nameSearch(TPList headPtr)
{
	char sname[SIZE];
	headPtr = headPtr->nextPtr;

	printf("Input surname: ");
	scanf_s("%s", sname, SIZE);
	printf("\n");
	while (headPtr != NULL)
	{
		if (strcmp(sname,headPtr->surname) == 0)
		{
			printf("Number  : %s\n", headPtr->num);
			printf("Name    : %s\n", headPtr->name);
			printf("Surname : %s\n\n", headPtr->surname);
		}
		headPtr = headPtr->nextPtr;
	}
}

void numberSearch(TPList headPtr)
{
	char numb[SIZE];
	headPtr = headPtr->nextPtr;

	printf("Input number: ");
	scanf_s("%s", numb, SIZE);
	printf("\n");
	while (headPtr != NULL)
	{
		if (strcmp(numb,headPtr->num) == 0)
		{
			printf("Number  : %s\n", headPtr->num);
			printf("Name    : %s\n", headPtr->name);
			printf("Surname : %s\n\n", headPtr->surname);
		}
		headPtr = headPtr->nextPtr;
	}
}

void showList(TPList headptr)
{
	if (headptr != NULL)
	{
		headptr = headptr->nextPtr;
		while (headptr != NULL)
		{
			printf("Fullname: %s %s\n",headptr->name, headptr->surname);
			printf("Number  : %s\n\n", headptr->num);
			headptr = headptr->nextPtr;
		}
	}
	else
	{
		printf("The list is empty!\n");
	}
}

void Actions()
{
	printf(
		   "1. Create list\n"
		   "2. Show list\n"
		   "3. Search by number\n"
		   "4. Search by surname\n"
		   " Choose action: "
		  );
}