/*
Найти в заданном каталоге (аргумент 1 командной строки) и всех его подкаталогах 
заданный файл (аргумент 2 командной строки).
Вывести на консоль полный путь к файлу, 
размер, 
дату создания, 
права доступа, 
номер индексного дескриптора,
общее количество просмотренных каталогов и файлов.
*/
//DEFINE PART
#define _GNU_SOURCE
//INCLUDE PART
#include <stdio.h>
#include <time.h>//Для форматированного вывода времени
#include <errno.h>//Макросы для идентификации ошибок
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>//Описания типов, хранящих инф о файлах
#include <sys/stat.h>//Сожержит описание структуры stat
#include <dirent.h>//Библиотека для функций и типов работы с каталогами

int   count = 0;
char* Dest  = NULL;

char* Concatenate(const char* FilePath, const char* File)
{
	char* FilePathNew = malloc(strlen(FilePath) + strlen(File) + 2);
	strcpy(FilePathNew, FilePath);
	strcat(FilePathNew, "/");
	return strcat(FilePathNew, File);
}

void SearchFile(char* dir, const char* File)
{
	DIR*           DirStream;
	struct dirent* CurrDirent;
	char*          FilePath = malloc(strlen(dir) + 1);

	errno = 0;
	if (!(DirStream = opendir(dir)))
	{
		fprintf(stderr, "%s: %s: %s\n", basename(Dest), dir, strerror(errno));
		return;
	}
	strcpy(FilePath, dir);

	do
	{
		errno = 0;
		CurrDirent = readdir(DirStream);
		if	(CurrDirent) { count++; }
		else
		{ 
			if (errno != 0) { fprintf(stderr, "%s: %s\n", basename(Dest), strerror(errno)); }
			break;
		}

		if (CurrDirent->d_type == DT_DIR && strcmp(CurrDirent->d_name, ".") && strcmp(CurrDirent->d_name, ".."))
		{
			SearchFile(Concatenate(FilePath, CurrDirent->d_name), File);
		}
		else if	(!strcmp(CurrDirent->d_name, File) && CurrDirent->d_type == DT_REG)
		{
			struct stat FileStat;
			char*       CreatingTime = malloc(20);
			char*       Str = Concatenate(FilePath, CurrDirent->d_name);
			
			stat(Str, &FileStat);
			strftime(CreatingTime, 20, "%d.%m.%Y", localtime(&FileStat.st_ctim.tv_sec));
			printf("%s %i %s %o %u %d\n", Str, FileStat.st_size, CreatingTime, FileStat.st_mode, FileStat.st_ino, count);
		}
	} while (CurrDirent);

	errno = 0;
	if (closedir(DirStream) != 0)
	{
		fprintf(stderr, "%s: %s: %s\n", basename(Dest), dir, strerror(errno));
	}
}

int main(int argc, char** argv)
{
	Dest = argv[0];
	SearchFile(argv[1], argv[2]);
	printf("%d\n", count);
	return 0;
}