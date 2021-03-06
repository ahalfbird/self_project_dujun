/*
This prog is used to generate the random input for other prog.
*/

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h>
#include<sys/time.h>
#include<windows.h>
#include "bmp.h"
#pragma pack(1);
#define RAND_TAG -256


int *genIntList(int *list,len,int init)
{
	if(len<=0)
		return NULL;
	list=(int *)calloc(len,sizeof(int));
	if(init == RAND_TAG)
		for(int i=0;i<len;i++)
			*(list+i)=tmrand();
	else for(int i=0;i<len;i++)
			*(list+i)=init;
	return list;
}

int *genCharList(char*list,len,char init)
{
		if(len<=0)
		return NULL;
	list=(int *)calloc(len,sizeof(char));
	if(init == RAND_TAG)
		for(int i=0;i<len;i++)
			*(list+i)=tmrand();
	else for(int i=0;i<len;i++)
			*(list+i)=init;
	return list;
}

int *genIntListList(int **list,int collen,int rawlen,int init)
{
	return NULL;
}

int genDataIntList(int *list,int len,int min,int max)
{
		for(int i=0;i<len;i++)
			*(list+i)=tmrand()%(max-min+1)+min;
		return 0;
}