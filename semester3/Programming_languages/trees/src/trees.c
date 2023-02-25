/*
8. Разработать программу удаления узла из заданного бинарного дерева. 
   Ключ удаляемого узла необходимо ввести.
*/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 9
#include <stdio.h>
#include <stdlib.h>

struct Tree
{
	struct Tree* leftPtr;
	int    data;
	struct Tree* rightPtr;
};

typedef struct Tree TTree;
typedef TTree* TPTree;

void Actions	    ();
void isEmpty		(TPTree);
void fillTree		(TPTree*);
void insertNode		(TPTree*, int);
void deleteNode		(TPTree*, const int);
void searchRightNode(TPTree*, TPTree);
int _print_t		(TPTree, int, int, int, char[20][255]);
void print_t		(TPTree);

int size = 0;
int k = 0;
main()
{
	unsigned int act;
	TPTree rootPtr = NULL;
	int key;

	do
	{
		Actions();
		scanf_s("%u", &act); printf("\n");
		switch (act)
		{
		case 1:
			fillTree(&rootPtr);
			break;
		case 2:
			isEmpty(rootPtr);
			print_t(rootPtr);
			printf("\n");
			break;
		case 3:
			printf("Input key: ");
			scanf_s("%d", &key); printf("\n");
			deleteNode(&rootPtr, key);
			if (k == 0)
			{
				printf("There is no such element!\n");
			}
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
		printf("Continue? 1 - yes, 0 - no\n");
		scanf_s("%u", &act); printf("\n");
	} while (act != 0);
}



void Actions()
{
	printf("1. Fill tree\n"
		   "2. Print tree\n"
		   "3. Delete node\n"
		   " Choose action: ");
}

void isEmpty(TPTree treePtr)
{
	if (treePtr == NULL)
	{
		printf("The tree is empty.\n");
	}
}

void fillTree(TPTree* treePtr)
{
	int value;

	printf("Input nodes: \n");
	for (size_t i = 0; i < SIZE; i++)
	{
		scanf_s("%d", &value);
		insertNode(&(*treePtr), value);
	}
	printf("The tree is filled!\n");
}

void insertNode(TPTree* treePtr, const int value)
{
	if (*treePtr == NULL)
	{
		*treePtr = malloc(sizeof(TTree));

		if (*treePtr != NULL)
		{
			(*treePtr)->data     = value;
			(*treePtr)->leftPtr  = NULL;
			(*treePtr)->rightPtr = NULL;
		}
	}
	else
	{
		if (value < (*treePtr)->data)
		{
			insertNode(&((*treePtr)->leftPtr), value);
		}
		else
		{
			if (value > (*treePtr)->data)
			{
				insertNode(&((*treePtr)->rightPtr), value);
			}
			else
			{
				printf("Insert error. Invalid value! \n");
			}
		}
	}
}

void deleteNode(TPTree* treePtr, const int key)
{	
	k = 0;
	if ((*treePtr)->data == key)
	{
		TPTree tmp;

		tmp = *treePtr;

		if ((*treePtr)->leftPtr != NULL)
		{
			*treePtr = (*treePtr)->leftPtr;
			//if ((*treePtr)->rightPtr != NULL)
			{
				searchRightNode(&(*treePtr)->rightPtr, tmp->rightPtr);
			}
		}
		else
		{
			*treePtr = (*treePtr)->rightPtr;
		}

		free(tmp);
		k++;
	}
	else
	{
		if (treePtr != NULL)
		{
			if ((*treePtr)->leftPtr  != NULL)
			{
				deleteNode(&(*treePtr)->leftPtr,  key);
			}
			if ((*treePtr)->rightPtr != NULL)
			{
				deleteNode(&(*treePtr)->rightPtr, key);
			}
		}
	}
}

void searchRightNode(TPTree* tmp, TPTree rightPtr)
{
	if (*tmp != NULL)
	{
		if ((*tmp)->rightPtr != NULL)
		{
			searchRightNode(&(*tmp)->rightPtr, rightPtr);
		}
		else
		{
			(*tmp)->rightPtr = rightPtr;
		}
	}
	else
	{
		*tmp = rightPtr;
	}
}

int _print_t(TPTree root, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!root) { return 0; };

	if (sprintf(b, "(%03d)", root->data) > 0)
	{
		size++;
	}

	int left  = _print_t(root->leftPtr, 1, offset, depth + 1, s);
	int right = _print_t(root->rightPtr, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
		

	if (depth && is_left) 
	{
		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';
	}
	else 
		if (depth && !is_left) 
		{

		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2]  = '.';
		}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];
		
	if (depth && is_left) 
	{

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i]         = '-';

		s[2 * depth - 1][offset + left + width / 2]                 = '|';
		s[2 * depth - 1][offset + left + width + right + width / 2] = '|';

	}
	else 
		if (depth && !is_left) 
		{
			for (int i = 0; i < left + width; i++)
				s[2 * depth - 1][offset - width / 2 + i] = '-';

			s[2 * depth - 1][offset + left + width / 2]  = '|';
			s[2 * depth - 1][offset - width / 2 - 1]     = '|';
		}
#endif
	return left + width + right;
}

void print_t(TPTree root)
{
	size = 0;
	char s[20][255];

	for (int i = 0; i < 20; i++)
	{
		sprintf(s[i], "%80s", " ");
	}
	_print_t(root, 0, 0, 0, s);

	for (int i = 0; i < size; i++)
	{
		printf("%s\n", s[i]);
	}
}

