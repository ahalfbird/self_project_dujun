#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <windows.h> 
#include<time.h>
#include<sys/time.h>
#include<conio.h>

#define CLS system("cls");
//#define PTN printf("\n");
#define PTN /**/

int prttime(int mode)
{
	time_t ptm;
	struct tm *lt;
	time(&ptm);
	lt=localtime(&ptm);
	printf("\n%d/%d/%d %d:%d:%d\n",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	
//	struct timespec timestamp;
//	clock_gettime(CLOCK_REALTIME, &timestamp);
//	printf("time:%d  s,%d  ns", timestamp.tv_sec, timestamp.tv_nsec);
	
	return 0;
}

int tmrand()
{
	struct timespec timestamp;
	clock_gettime(CLOCK_REALTIME, &timestamp);
	srand(timestamp.tv_nsec);
//	printf("[%d]ns==>",timestamp.tv_nsec);
	int sss=0;
	PTN
	for(int i=0;i<10;i++)
	{
		sss=rand();
//		printf("=%d=",sss);
	}
	PTN
	return sss;
}


int main()
{
	struct timespec tim;
   tim.tv_sec = 1;
   tim.tv_nsec = 1;
	for(int i=0;i<1000;i++)
	{
		
		tim.tv_sec=tmrand()%3+1;
//		printf("%d",tim.tv_sec);
		nanosleep(&tim,NULL);
		CLS
		prttime(0);
		//if(getch()!='q')
			
		if(i==999)
			i=0;
	}
	
	getchar();
	return 0;
}