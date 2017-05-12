#include "stddef.h"
#include <stdbool.h>
#include <stdio.h>

//Функция вычисления длины строки
int slen(const char *str);

//Функция разбиения строки на элементы-токены (stok), разделенные заданным символом
void stok(char *str, const char *delim, char *lecsemma);
char tempTok[256];
int pos;
//функция проверки символа на принадлежность заданному множеству символов (sspn), 
//необходимая для проверки допустимости используемых символов.
int sspn(const char *a, const char *b);

//функция сравнения строк
bool scmp(const char *a, const char *b);

//функция копирования строк
void scpy(char *to, const char *from);
