#include <stdio.h>
//#include <stdbool.h>
#include "strings.h"

void check(const char * str);
void convert(char * to, char * from);

int main (int argc, char **argv)
{
	int i;
	if(argc == 1) //если аргументов нет, выводит ошибку
	{
		printf("Sintax error!!!\n");
		return 0;
	}
	char delim[1];

	while(true)
	{
		char input[1024];
		char output[1024];
		scanf("%s",input);
		
		char lec[1024] = "";
		stok(input,":",lec);
		
		if(scmp(lec,"exit"))break;
		if(scmp(lec,"delim"))
		{
			stok(NULL," ",lec);					
			delim[0] = lec[0];
			printf("delim = %c\n",delim[0]);		
		}
		if(scmp(lec,"path"))
		{
			int outL = 0;
			do{
				stok(NULL,delim,lec);
				char tmp[1024] = "";
				convert(tmp,lec);
				for(i = 0; i<slen(tmp); i++)
				{
					output[outL] = tmp[i];
					outL++;
				}
				output[outL] = delim[0];
				outL++;
			}while(lec[0] != '\0');
			printf("new path: %s",output);
		}	
	}	
	return 0;
}

void convert(char * to, char * from)
{
	int i;
	if(slen(from) > 260) {
		return;
	}
	if(sspn(from,"\\") == 0){
		return;
	}
	
	if(from[0]=='\\' && from[1]=='\\')
	{
		char tmp[260] = "";
		scpy(tmp,"http:"); 
		int l = 5;
		char lec[260];
		from[0]='/'; from[1]='/';
		stok(from,"\\",lec);
		do{			
			if( sspn(lec,"1234567890") > 0 && sspn(lec,".") > 0) //Если IP адрес
			{		printf("IP");
				for(i = 0; i < 15; i++){
					tmp[l]=lec[i];
					l++;
				}
				tmp[l] = '/';
				l++;
			}
			else { //Если Доменное имя
				for(i=0; lec[i] != '\0'; i++)
				{
					tmp[l]=lec[i];
					l++;		
				}
				tmp[l] = '/';
				l++;
			}
			stok(NULL,"\\",lec);
		}while(lec[0] != '\0');
		scpy(to,tmp);
	}
	
	//scpy(to,from);
}

void check(const char * str)
{
	
}
