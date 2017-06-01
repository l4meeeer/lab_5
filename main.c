#include <stdio.h>

#include "strings.h"

void convert(char * to, char * from);

int main (int argc, char **argv)
{
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
				printf("%s\n",tmp);
				for(int i = 0; i<slen(tmp); i++)
				{
					output[outL] = tmp[i];
					outL++;
				}
				output[outL] = delim[0];
				outL++;
			}while(lec[0] != '\0');
			output[outL]='\0';
			printf("new path: %s",output);
		}	
	}
	return 0;
}

void convert(char * to, char * from)
{
	if(slen(from) > 260) {
		return;
	}
	if(sspn(from,"\\") == 0){
		return;
	}
	
	if(from[0]=='\\' && from[1]=='\\')
	{
		char tmp[260] = "";
		scpy(tmp,"http://"); 
		int l = 7;
		for(int i = 2; i < slen(from); i++)
		{
			tmp[l]=from[i];
			if(tmp[l]=='\\') tmp[l] = '/';
			l++;
		}
		scpy(to,tmp);
	}
}