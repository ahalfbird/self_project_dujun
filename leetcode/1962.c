

//ok
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<conio.h>
#include <stdarg.h>

#define null NULL
#define PRTN putchar('\n');
int opetimes=0;

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
	printf("\n===========================================\nstrlen=%d\n",len);
	int i;
	for(i=0;i<len;i++){
	printf("[%d]",*(str+i));
	sum +=*(str+i);
	}
	printf("\n===========================================\n");
	return sum;
}

int *randlist(int *list,int len)
{
	int i=0;
	for(i=0;i<len;i++)
		*(list+i)=tmrand()%16+1;
	return list;
}



void _swap(int *p1,int *p2)
{
	*p1+=*p2;
	*p2=*p1-*p2;
	*p1=*p1-*p2;
}


int quicksort(int *list,int len)
{
	//二叉排序
	opetimes=0;
	int i=0,j=0;
	int endflag=1;
	while(endflag)
	{
		if(i*2+1<len)
			if(*(list+i)<*(list+i*2+1))
			{
				j=i*2+1;
				while(*(list+(j+1)/2-1)<*(list+j)&&j>0)
				{
					_swap(list+j,list+(j+1)/2-1);
					j=(j+1)/2-1;
					if(j==0)
						break;
				}
			}
			else endflag=1;
		else {
			endflag=0;
			break;
		}
		if((i+1)*2<len)
			if(*(list+i)<*(list+i*2+2))
			{
				j=i*2+2;
				while(*(list+(j+1)/2-1)<*(list+j)&&j>0)
				{
					_swap(list+j,list+(j+1)/2-1);
					j=(j+1)/2-1;
					if(j==0)
						break;
				}
			}
			else endflag=1;
		else {
			endflag=0;
			break;
		}
		i++;
		opetimes++;
		//prtintstr(list,len);
	}
	
	return opetimes;
}

int stone1(int *list,int len,int k)//list last number
{
	int i=0;
	int tmp=0;
	int j=0;
	opetimes=0;
	
	for(j=k;j>0;j--){
	
	*list-=*list/2;
	i=0;
	tmp=1;
		while(tmp)
		{
			if(*(list+i*2+2)>*(list+i*2+1))
			{
				if(*(list+i*2+2)>*(list+i))
				{
					_swap(list+i,list+i*2+2);
					i=i*2+2;
				if(i>=len)
					tmp=0;
				else tmp=1;
				}
				else tmp=0;
			}
			else
			{
				if(*(list+i*2+1)>*(list+i))
				{
				_swap(list+i,list+i*2+1);
				i=i*2+1;
				if(i>=len)
					tmp=0;
				else tmp=1;
				}
				else tmp=0;
			}
		}
	prtintstr(list,len);
	}
	return opetimes;
}


int stone0(int *list,int len,int k)
{
	int i=0;
	opetimes=quicksort(list,len);
	prtintstr(list,10);
	opetimes=stone1(list,len,k);
	int sum=0;
	for(i=0;i<len;i++)
		sum+=*(list+i);
	return sum;
}


int main()
{
	
int list[]={2,6,9,7,35,16,16,1,68,46};
	
	//prtintstr(list,10);

	printf("\n\n[result:%d]\n\n",stone0(list,10,3));
	quicksort(list,10);
	prtintstr(list,10);
	int len;
	scanf("%d",&len);
	return 0;
}













/*
1962. 移除石子使总数最小
给你一个整数数组 piles ，数组 下标从 0 开始 ，其中 piles[i] 表示第 i 堆石子中的石子数量。另给你一个整数 k ，请你执行下述操作 恰好 k 次：

选出任一石子堆 piles[i] ，并从中 移除 floor(piles[i] / 2) 颗石子。
注意：你可以对 同一堆 石子多次执行此操作。

返回执行 k 次操作后，剩下石子的 最小 总数。

floor(x) 为 小于 或 等于 x 的 最大 整数。（即，对 x 向下取整）。

 

示例 1：

输入：piles = [5,4,9], k = 2
输出：12
解释：可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [5,4,5] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [3,4,5] 。
剩下石子的总数为 12 。
示例 2：

输入：piles = [4,3,6,7], k = 3
输出：12
解释：可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [4,3,3,7] 。
- 对第 3 堆石子执行移除操作，石子分布情况变成 [4,3,3,4] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [2,3,3,4] 。
剩下石子的总数为 12 。
 

提示：

1 <= piles.length <= 105
1 <= piles[i] <= 104
1 <= k <= 105
*/