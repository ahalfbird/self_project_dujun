/*
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

 
示例 1 ：

输入：num = "1432219", k = 3
输出："1219"
解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
示例 2 ：

输入：num = "10200", k = 1
输出："200"
解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 ：

输入：num = "10", k = 2
输出："0"
解释：从原数字移除所有的数字，剩余为空就是 0 。
 

提示：

1 <= k <= num.length <= 105
num 仅由若干位数字（0 - 9）组成
除了 0 本身之外，num 不含任何前导零
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





void tmrand()
{
	struct timespec timestamp;
	clock_gettime(CLOCK_REALTIME, &timestamp);
	srand(timestamp.tv_nsec);
}

void prt(int a)
{
	int i,k;
	int b=a;
	int al[32];
//	printf("[%10s]  ",str);
	for(i=31;i>=0;i--)
	{
		al[i]=b&1;
		b=b>>1;
	}
	for(i=0;i<4;i++)
	{
		for(k=0;k<8;k++)
		
			printf("%d",al[i*8+k]);
		
		putchar(' ');
	}
	PRTN
}


int add(int *a)
{
	int p1=1;
	int pk=1;
	int n1,n2;
	int i=0;
	int tp;
	int tk;
	int sign=0;
	if(abs(*(a+1))<abs(*(a+2)))
	{
		n1=*(a+2);
		n2=*(a+1);
	}
	else
	{
		n1=*(a+1);
		n2=*(a+2);
	}
	
//	prt(*(a+1));prt(*(a+2));
	for(pk=0;pk<31;pk++)
	{
		if(n2&p1)
		{
			tp=p1;
			tk=pk;
			while(n1&tp)
			{
				n1=n1&~tp;
				tp=tp<<1;
				tk++;
				if(tk==31)
					sign=1;
			}
			n1=n1|tp;
//			printf("[%d]",pk);
		}
		p1=p1<<1;
//		printf("[%x]\n",n1);prt(n1);
	}
	
	*a=n1;
	if(sign)
		n1=~(~n1&p1);

//	printf("\n[a1]%8x+[a2]%8x=[a0]%8x\n",*(a+1),*(a+2),*a);
return *a;

}

int main()
{
	int a[3];
	tmrand();
	for(int i=10;i>0;i--){
	a[1]=rand();
	a[2]=rand();

	add(a);
	printf("[%x][%x][%x]\n\n",a[0],a[1],a[2]);
	
	}
	getchar();
	return 0;
}


