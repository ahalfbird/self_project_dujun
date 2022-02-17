/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。

你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。

 

示例 1：

输入：nums = [1,3,4,2,2]
输出：2
示例 2：

输入：nums = [3,1,3,4,2]
输出：3
示例 3：

输入：nums = [1,1]
输出：1
示例 4：

输入：nums = [1,1,2]
输出：1

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次

*/
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
	static sametag;
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
	printf("strlen=%d\n",len);
	int i;
	for(i=0;i<len;i++){
	printf("[%d]",*(str+i));
	sum +=*(str+i);
	}
	PRTN
	return sum;
}

int *randlist(int max)
{
	int listlen=max+1;
	int *list=(int *)calloc(listlen,sizeof(int));
	int i=0;
	for(i=0;i<listlen-1;i++)
	{
		*(list+i)=i+1;
	}
	*(list+i)=tmrand()%max+1;
	int tmp=0;
	int pos;
	i=0;
	for(i=0;i<listlen;i++)
	{
		pos=tmrand()%listlen;
//		printf("[pos:%d]",pos);
		tmp=*(list+i);
		*(list+i)=*(list+pos);
		*(list+pos)=tmp;
//		prtintstr(list,max+1);
	}
	return list;
}

int findrepeat(int *list,int max)
{
	int listlen=max+1;
	int mulmidnum=1+max;
	int sum=0;
	int i=0;
	for(;i<listlen;i++)
	{
		sum+=*(list+i)-i;
	}
	return sum;
}

int main()
{
	int max=tmrand()%50+10;
	int *list;
	list=randlist(max);
	
	if(list==null)
	{
	printf("nullpointer");
	goto endl;
	}
	
	prtintstr(list,max+1);
	printf("\n\nrepeat=%d\n",findrepeat(list,max));
endl:
	scanf("%d",&max);
	return 0;
}