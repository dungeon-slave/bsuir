/*
	���� ������ �������� S, ��������� �� ��������� ����. 
	������ ��������, ����������� ��������� � �� ���������� �������� ������ ����, ����� �������� �������. 

		������������� �������� ������ � ������ S1 � S2 � ������������ � �������� 1 � 2 �������, 
	��������� ��������������. 
		���� �����-���� �� �������� ����� �������� ������, �������� ��������������� ���������. 
		���� � �������� ������ ���������� ����� �������� ��� ��������� ��������� �� ������������ �������� 
	����� ����� (�����) ���� ��������� � �������� �� �������, ���������� �� ���������� ��������. +++
	
	�.1. � ���������� �����, �������� �� ���������� �����, ���� ��� ������������� ���������� �������:
		����� ��������� � ��������� �������� ���������� �������� (a, ab, abc � �.�.);
		������, ��� � ��������� 'a' .. 'z' ����� ���� ������, �������� �� ��������� ����.

	�.2. - ���������� �����, �������� �� ���������� �����, �������� ��������� ����� � ������ �����.
*/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 128

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void CorrectSymb(char S[]);
void LastWord(char S[]);
void Sorting(char S[], char S1[], char S2[]);

int sch = 0;

main()
{
	char S[SIZE] = "", S1[SIZE] = "", S2[SIZE] = "";

	printf("  Default  string: ");
	gets_s(S, SIZE);
	for (unsigned i = 0; i <= strlen(S); i++)
	{
		S[i] = tolower(S[i]);
	}
	CorrectSymb(S);
	LastWord(S);

	printf("  Modified string: %s\n", S);

	Sorting(S, S1, S2);

	if (S1[0] == '\0')
	{
		printf("\n  S1 is empty!\n");
	}
	else
	{
		printf("\n  S1: %s %d\n", S1, sch);
	}

	if (S2[0] == '\0')
	{
		printf("\n  S2 is empty!\n");
	}
	else
	{
		printf("\n  S2: %s\n", S2);
	}
}

void CorrectSymb(char S[])
{
	char Stemp[SIZE] = {'\0'};
	char* word;

	word = strtok(S," ");

	while (word != NULL)
	{
		for (unsigned i = 0; i < strlen(word); i++)
		{
			if ( (int)word[i] < 97 || (int)word[i] > 122 )
			{
				word = "";
				break;
			}
		}

		strcat(Stemp, word);
		strcat(Stemp, " ");
		word = strtok(NULL, " ");
	}

	strcpy(S, Stemp);
}

void LastWord(char S[])
{
	char Stemp[SIZE] = ""; 
	char* word; char Lword[SIZE/2] = "";

	strcat(Stemp, S);
	word = strtok(Stemp, " ");

	while (word != NULL)
	{
		strcpy(Lword,word);
		word = strtok(NULL, " ");
	} 

	word = strtok(S, " ");
	strcpy(Stemp, "");

	while (word != NULL)
	{
		if (strcmp(word,Lword) != 0)
		{
			strcat(Stemp, word);
			strcat(Stemp, " ");
		}
		word = strtok(NULL, " ");
	}

	strcpy(S, Stemp);
}

void Sorting(char S[], char S1[], char S2[])
{
	const char Sabc[27] = "abcdefghijklmnopqrstuvwxyz";
	char* word; char tmp[2] = "";
	
	word = strtok(S, " ");
	while (word != NULL)
	{
		tmp[0] = word[strlen(word) - 1];
		strcat(S2, tmp);
		if (strlen(word) > 1)
		{
			for (unsigned i = 0; i <= strlen(word) - 2; i++)
			{
				tmp[0] = word[i];
				strcat(S2, tmp);
			}			
		}
		strcat(S2, " ");

		for (unsigned i = 0; i <= strlen(word) - 1; i++)
		{
			if (word[i] != Sabc[i])
			{
				word = "";
 				break;
			}
		}
		strcat(S1, word);
		if (word != "")
		{
			strcat(S1, " ");
			sch++;
		}

		word = strtok(NULL, " ");
	}
}