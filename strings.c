#include "strings.h"

//Функция вычисления длины строки
int slen(const char *str)
{
	int lenght = 0;
    for(int i= 0; str[i] != '\0'; i++){
		lenght++;
	}
    return lenght;  
}

//Функция разбиения строки на элементы-токены (stok), разделенные заданным символом
void stok(char *str, const char *delim, char *lecsemma)
{		
	if(str != NULL)
	{
		scpy(tempTok,str);  //куда, откуда
		pos = 0;
	}else pos++;	
	int tmp_i=0;
	char tmp[256]="";
	for(int i= pos; tempTok[i] != '\0'; i++,pos++)
	{
		if(tempTok[i] == *delim) break;
		tmp[tmp_i] = tempTok[i];
		tmp_i++;
	}
	scpy(lecsemma,tmp);
}

//функция сравнения строк
bool scmp(const char *a, const char *b)
{
	while ( *a && *b && *a == *b )
        ++a, ++b;
    if((*a - *b) == 0) return true;
	else return false;
}

//функция копирования строк
void scpy(char * to, const char * from)
{	
	while(*from) *to++ = *from++;
	*to = '\0';	
}

//функция проверки символа на принадлежность заданному множеству символов (sspn), 
//необходимая для проверки допустимости используемых символов.
int sspn(const char *str, const char *simbStr)
{
	int num = 0;
	bool found = false;
	bool next = false;
	for(int i = 0; str[i] != '\0'; i++)	
	{
		next = false;
		for(int j = 0; simbStr[j] != '\0'; j++)	
		{			
			if(str[i] == simbStr[j]){
				found = true;
				next = true;
				num++;
				break;
			}		
		}
		if(found &&!next){
			 break;
		}
	}
	return num;
}