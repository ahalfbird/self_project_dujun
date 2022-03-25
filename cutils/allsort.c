#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>

void swapint(int*a,int*b)
{
	int c=*a;
	*a=*b;
	*b=c;
}

int prtintstr(int *str,int len)
{
int sum=0;
	int i;
	for(i=0;i<len;i++){
	printf("[%4d]",*(str+i));
	sum +=*(str+i);
	}
	return sum;
}

int ann(int n)
{
	int i=n;
	int sum=1;
	while(i>1)
		sum*=i--;
	return sum;
}

int stepone(int*list,int len)
{
	int i=0;
	static int counter=0;
	int *p=list+len-1;
	while(p>list&&*p<*(p-1))
		p--;
	if(p==list)
	{
		counter=0;
		printf("\nfinish to ergodic list\n");
		return 0;
	}
	int forwardp=*(p-1);
	int pos=p-list;
	int *tmpp;
	if(forwardp<(len-1)/2)
	{
		tmpp=list+len-1;
		while(tmpp-list>pos-1&&*tmpp<forwardp)
			tmpp--;
		
	}
	else {
		tmpp=list+pos;
		while(tmpp-list<len-1&&*(tmpp+1)>forwardp)
			tmpp++;
	}
	swapint(tmpp,p-1);
	
	tmpp=list+len-1;
	int times=(len-pos)/2;
	for(i=0;i<times;i++)
		swapint(tmpp--,p++);
	
	counter++;
	return counter;
}

int alsort(int len, char *argv[])
{
	int counter=0;
	int *list=(int*)calloc(len,sizeof(int));
	int i=0,j=0;
	for(i=0;i<len;i++)
		*(list+i)=i;
//		j=0;
//		while(j<len)
//			printf("[%s]",*(argv+j++));

	printf("\n   0:");
	j=0;
	while(j<len)
		printf("[%s]",*(argv+*(list+j++)));
	
	for(i=0;i<ann(len);i++)
	{
		counter=stepone(list,len);
		if(counter){
			printf("\n%4d:",counter);
			j=0;
			while(j<len)
				printf("[%s]",*(argv+*(list+j++)));
		}
	}
	
	return 0;
}

int main(int argc, char *argv[])
{

int len=argc-1;
alsort(len, argv+1);

putchar('\n');
	return 0;
}
