/*856. 括号的分数
给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串
*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<conio.h>

#define PRTN putchar('\n');
int tmrand()
{
	struct timespec timestamp;
//	static int srandtag=1;
	clock_gettime(CLOCK_REALTIME, &timestamp);
		srand(timestamp.tv_nsec);
	return rand();
}

typedef struct node{
	struct node* lc;
	struct node* rc;
	int value;
	int calfunc;
}Node;


int prtintstr(int *str,int len)
{
int sum=0;
	for(int i=0;i<len;i++){
	printf("[%d]",*(str+i));
	sum +=*(str+i);
	}
	PRTN
	return sum;
}
char* genstr(int len)
{
	if(len&1)
		return NULL;
	printf("len=%d\n",len);
	int ready=0;
	char *brackets=(char*)calloc(1,len);
	*brackets='(';
	*(brackets+1)=')';
	ready=2;
	int pos=0;
	int opep=0;
	for(int i=1;i<len-2;i+=2)
	{
		pos=tmrand()%(i+2);
		
		for(opep=i+2;opep-pos>1;opep--)
		{
			*(brackets+opep)=*(brackets+opep-2);
		}
		*(brackets+pos)='(';
		*(brackets+pos+1)=')';
//		printf("string is %s \n",brackets);
	}
	printf("str is %s ,,strlen is %d\n",brackets,strlen(brackets));
	return brackets;
}
int calBrackets(char*cb)
{
	int len=strlen(cb);
	char*cbp=cb;
	int stack[len];
	int stp=0;
	
	while((cbp-cb)<len)
	{
		if(*(cbp++)=='(')
			stack[stp++]=-1;
		else {
			if(stack[stp-1]==-1)
				stack[stp-1]=1;
			else {
				while(stack[stp-2]!=-1)
				{
					stack[stp-2]+=stack[stp-1];
					stp--;
					stack[stp]=0;
				}
				stack[stp-2]=stack[stp-1]*2;
				stp--;
				stack[stp]=0;
			}
		}
		prtintstr(stack,stp);
	}
	
	return prtintstr(stack,stp);
}

int main()
{
	char*cb;
	int len;
	len= (4+tmrand()%20)*2;
	cb=genstr(len);
	int res=calBrackets(cb);
	printf("\nres = %d\n",res);
	scanf("%d",&len);
	return 0;
}