/*
	6. Разработать программу перекодировки текстового файла, заменив в нем заглавные буквы строчными.
*/
#define SIZE 128
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void selectFile(char Str[]);
void recodeStr(char Str[]);
void readFile(char Str1[], char Str2[]);
void writeFile(char Str1[], char Str2[]);

int count = 0;

main()
{
	char FileName[SIZE/2] = "", Text[SIZE] = ""; 
	int act = 0;
	
	do
	{
		selectFile(FileName);
		readFile(FileName, Text);
		recodeStr(Text);
		writeFile(FileName, Text);

		printf("File recoded.\n\n");
		do
		{
			printf("Continue? 1 - yes, 0 - no\n"
			   " Choose action: ");
			scanf_s("%d", &act); printf("\n");
			if (!(act == 0 || act == 1))
			{
				printf("Invalid action!\n");
			}
		} while (!(act == 0 || act == 1));
		
	} while (act != 0);
}

void selectFile(char FileName[])
{
	unsigned int act1 = 0;
	char Stmp[SIZE/2] = "";

	do
	{
		printf("1 - select new file, 0 - use default \n"
			   " Choose action: ");
		scanf_s("%d", &act1); printf("\n");
		if (!(act1 == 0 || act1 == 1))
		{
			printf("Invalid action!\n");
		}
	} while (!(act1 == 0 || act1 == 1));

	if (act1 == 1)
	{
		printf("Enter file path: ");
		scanf_s("%s", (Stmp), sizeof(Stmp));
		printf("\n");
	}
	else
	{
		strcpy(Stmp,"Перекодировка.txt");
	}

	strcpy(FileName, Stmp);
}

void readFile(char FileName[], char Text[])
{
	char Stmp[SIZE] = ""; FILE* f;
	
	if ( (f = fopen(FileName, "r")) == NULL)
	{
		printf("OPEN ERROR! Maybe this file does not exist.");
	}
	else
	{
		while (!feof(f))
		{
			fgets(Stmp, SIZE, f);
			strcat(Text, Stmp);
		}
		fclose(f);
	}
}

void recodeStr(char Text[])
{
	char Stmp[SIZE] = "";

	strcpy(Stmp, Text);
	for (size_t i = 0; i <= SIZE - 1; i++)
	{
		if ((int)Stmp[i] >= 'A' && (int)Stmp[i] <= 'Z')
		{
			count++;
		}
		Stmp[i] = tolower(Stmp[i]);
	}
	strcpy(Text, Stmp);
}

void writeFile(char FileName[], char Text[])
{
	FILE* f;

	f = fopen(FileName, "w");
	//fputs(Text, f);
	fprintf(f, "%s \n %d", Text, count);
	fclose(f);
}