#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h>
#include<sys/time.h>
#include<windows.h>
#pragma pack(1);

#define CHARPRTLEN 50
#define PRTN putchar('\n');
#define PRTF(chs) printf("[%s:%s]\n",__func__,chs);

static int CirCount=0;
int prtchs(char ch)
{
	char* chs=(char*)calloc(CHARPRTLEN,sizeof(char));
	int i=CHARPRTLEN;
	while(i)
	*(chs+--i)=ch;
	printf("%s",chs);
	return 0;
}

int tmrand()
{
	static int sametag;
//	printf("[sametag:%d]",sametag);
	struct timespec timestamp;
	clock_gettime(CLOCK_REALTIME, &timestamp);
	if(sametag==timestamp.tv_nsec)
		return rand();
	srand(timestamp.tv_nsec);
	sametag=timestamp.tv_nsec;
	return rand();
}

int prtintstr(int *str,int len)
{
int sum=0;
	PRTN
	prtchs('=');
	PRTN
	int i;
	for(i=0;i<len;i++){
	printf("[%d]",*(str+i));
	sum +=*(str+i);
	}
	PRTN
	prtchs('=');
	PRTN
	return sum;
}

int *randlist(int *list,int len)
{
	int i=0;
	for(i=0;i<len;i++)
		*(list+i)=tmrand()%16+1;
	return list;
}

int sortlist(int *list,int len)
{

	//PRTCT
	if(len==0)
	return printf("\nsortlist len=0, error\n");
	if(len==1)
		return 1;
	if(len==2)
	{
		if(*list>*(list+1))
		{
			*(list+1)+=*list;
			*list=*(list+1)-*list;
			*(list+1)=*(list+1)-*list;
		}
		return 2;
	}
	sortlist(&(*list),len/2);
//	printf("\nsortlist len=%d, finish left half-list \n",len);
	sortlist(&(*(list+len/2)),len-len/2);
//	printf("\nsortlist len=%d, finish right half-list \n",len);
	int lp=0;
	int rp=len/2;
	int *tmplist=(int *)calloc(len,sizeof(int));
	int tag=0;
	int i=0;
	for(i=0;i<len;i++)
	{
//		printf("i=%d tag=%d lp=%d rp=%d\n",i,tag,lp,rp);
		if(!tag){
		if(*(list+lp)>*(list+rp))
			*(tmplist+i)=*(list+rp++);
		else *(tmplist+i)=*(list+lp++);
		if(lp==len/2)
			tag=1;
		if(rp==len)
			tag=2;
		}
		else {
			if(tag==1)
				*(tmplist+i)=*(list+rp++);
			else *(tmplist+i)=*(list+lp++);
		}
	}
	for(i=0;i<len;i++) *(list+i)=*(tmplist+i);
	free(tmplist);
	//prtintstr(list,len);
	return 0;
}


int *getFactor(int a)
{
//	PRTF("start")
	int *stack;
	if(a==1)
	{
		stack=(int*)calloc(2,sizeof(int));
		*stack=*(stack+1)=1;
		return stack;
	}
	int len=(int)(log(a)*1.0/log(2))+1;
	stack=(int*)calloc(len,sizeof(int));
	*stack=1;
	
	int tmp=a;
	int tfac=2;
	while(1)
	{
		
		CirCount++;
		if(tmp%tfac==0)
		{
//			PRTF("find factor")
			*(stack+*stack)=tfac;
			(*stack)++;
			tmp=tmp/tfac;
			
		}
		else{
//			PRTF("not find factor")
			if(tfac!=2)
				tfac+=2;
			else tfac++;
		}
//		printf("tfac=%d tmp=%d len=%d CirCount=%d",tfac,tmp,len,CirCount);
//		prtintstr(stack,len);
		if(tmp==1||tfac>tmp||*stack>len)
		break;
	}
//	prtintstr(stack,len);
	return stack;

}

int getCommonFactor(int a,int b)
{
int *stacka=getFactor(a);
int *stackb=getFactor(b);
int cfactor=1;
int ia=1,ib=1;
for(;(ia<*stacka)&&(ib<*stackb);)
{
	CirCount++;
	if(*(stacka+ia)>*(stackb+ib))
	{
		ib++;
	}
	else if(*(stacka+ia)<*(stackb+ib))
	{
		ia++;
	}
	else {
		cfactor*=*(stacka+ia);
		ia++;ib++;
	}
}
	free(stacka);
	free(stackb);
	return cfactor;
}

int getCommonMultiple(int a,int b)
{
	return a*b/getCommonFactor(a,b);
}

int main()
{
	int i=0;
	int a,b;
	int *stack;
	int len;
	for(i=0;i<10;i++)
	{
		a=1+tmrand();
		b=1+tmrand();
		printf("[%d][%d]\n",a,b);
		printf("getCommonFactor(a,b)=[%d]\n",getCommonFactor(a,b));
		printf("getCommonMultiple(a,b)=[%d]\n",getCommonMultiple(a,b));
		printf("CirCount=[%d]\n",CirCount);
		
		CirCount=0;
	}
	getchar();
	return 0;
}