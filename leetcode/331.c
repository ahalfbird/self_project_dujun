/*
序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。

给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。

你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。

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

void getr(int len,int *lp)
{
	//逆时针旋转90
	*(lp+6)=len-*(lp+1);
	*(lp+7)=*lp;
	//顺时针旋转90
	*(lp+2)=*(lp+1);
	*(lp+3)=len-*lp;
	*(lp+4)=len-*lp;
	*(lp+5)=len-*(lp+1);
}

void rot(int **m,int len)
{
	int ci=0;
	//len等于一行数字个数
	if(len%2==0)
	{
		ci=(len-1)/2+1;
	}
	else ci=(len-1)/2;
	
	int i,j,tmp;
	int lp[8];
	for(i=0;i<ci;i++)
		for(j=0;j<ci;j++)
		{
			*lp=i;
			*(lp+1)=j;
			getr(len-1,lp);
			tmp=m[*(lp+6)][*(lp+7)];
			m[*(lp+6)][*(lp+7)]=m[*(lp+4)][*(lp+5)];
			m[*(lp+4)][*(lp+5)]=m[*(lp+2)][*(lp+3)];
			m[*(lp+2)][*(lp+3)]=m[*lp][*(lp+1)];
			m[*(lp)][*(lp+1)]=tmp;
			
		}
	
		
}

void prt(int **lt,int a)
{
	for(int i=0;i<a;i++)
	{	for(int k=0;k<a;k++)
			printf("[%3d] ",lt[i][k]);
		putchar('\n');
	}
	
}

int main()
{
	int a;
	int **lt;
	scanf("%d",&a);
	lt=calloc(a,sizeof(int));
	for(int i=0;i<a;i++)
	*(lt+i)=calloc(a,sizeof(int));
	for(int i=0;i<a;i++)
		for(int k=0;k<a;k++)
			lt[i][k]=i*a+k;
		
	prt(lt,a);
	rot(lt,a);
	prt(lt,a);
	
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}




