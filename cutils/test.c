#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<conio.h>

#define null NULL
#define PRTN putchar('\n');

int tmrand()
{
	static int sametag=0;
//	printf("[sametag:%d]",sametag);
	struct timespec timestamp;
	clock_gettime(CLOCK_REALTIME, &timestamp);
	if(sametag==timestamp.tv_sec)
		return rand();
	srand(timestamp.tv_sec);
	sametag=timestamp.tv_sec;
	return rand();
}

int prtP(char **p)
{
	if(p==null)
		printf("p==null");
		if(*p==null)
		printf("*p==null");
	printf("**p[%c] \n *p[%s] p[%d]",**p,*p,p);
	return 0;
}

int initP(char**p)
{
	p=(char**)calloc(16,sizeof(char*));
	int count=0;

	for(int i=0;i<16;i++)
	{
		printf("\nstep in main : %d\n",i);
		*(p+i)=(char*)calloc(8,sizeof(char));
		*(*(p+i)+0)='S';
		*(*(p+i)+6)='E';
		*(*(p+i)+7)='\n';
		
		for(int j=1;j<6;j++)
			*(*(p+i)+j)='0'+rand()%10;
	}
	prtP(p);
}

/*
*
*pointer test
*
*/

int main()
{
char **p;
initP(p);


getchar();
return 0;
}
