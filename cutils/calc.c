#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <windows.h> 
#include<time.h>
#include<sys/time.h>
#include<conio.h>
#include <direct.h>

#define PRT(str) printf("\n[%s]\n",str);
#define PTRN	printf("\n");

char dir_name[16][20];


int dir_name_create(){
	char*dirp=dir_name[0];
	for(char i=0;i<16;i++)
	{
		dirp=dirname[i];
		*dirp='d';
		*(dirp+1)='i';
		*(dirp+2)='r';
		*(dirp+3)=(i&1)+32;
		*(dirp+4)=(i&2)+32;
		*(dirp+5)=(i&4)+32;
		*(dirp+6)=(i&8)+32;
		*(dirp+7)='\0';
		PRT(dirname[i]);
	}
	return 0;
};

int mkdir(int node,char*name);
{
	
}

int main()
{
	
	getchar();
	return 0;
}
