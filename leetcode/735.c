/*
735. 行星碰撞
给定一个整数数组 asteroids，表示在同一行的行星。

对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。

找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

 

示例 1：

输入：asteroids = [5,10,-5]
输出：[5,10]
解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
示例 2：

输入：asteroids = [8,-8]
输出：[]
解释：8 和 -8 碰撞后，两者都发生爆炸。
示例 3：

输入：asteroids = [10,2,-5]
输出：[10]
解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。
示例 4：

输入：asteroids = [-2,-1,1,2]
输出：[-2,-1,1,2]
解释：-2 和 -1 向左移动，而 1 和 2 向右移动。 由于移动方向相同的行星不会发生碰撞，所以最终没有行星发生碰撞。 
 

提示：

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
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
	printf("strlen=%d\n",len);
	int i;
	for(i=0;i<len;i++){
	printf("[%d]",*(str+i));
	sum +=*(str+i);
	}
	PRTN
	return sum;
}

int *randlist(int len)
{

	int *list=(int *)calloc(len,sizeof(int));
	int i=0;
	for(i=0;i<len;i++)
	{
		*(list+i)=tmrand()%2000-1000;
		if(!(*(list+i)))
		*(list+i)=1000;
	}
	return list;
}

int getdir(int a)
{
	if(a>0)
		return 1;
	else if(a<0)
		return -1;
	else return 0;
}

int *delzero(int *list,int len)
{
	int p=0;
	for(int i=0;i<len;i++)
		if(list[i])
			list[p++]=list[i];
	for(;p<len;p++)
		list[p]=0;
	return list;
}

int *onejudge(int *ori_list,int len)
{
	int *list=(int*)calloc(len,sizeof(int));
	int i=0;
	int j=0;
	int fln=0;
	int sln=0;
	int fmp=0;
	int smp=0;
	int ftag=0;
	memcpy(list,ori_list,len*sizeof(int));
//	prtintstr(list,len);
	fln=getdir(list[0]);
//	PRTN
	for(i=1;i<len;i++)
	{
		if(getdir(list[i-1])==getdir(list[i]))
		continue;
		else {
			fln=getdir(list[i-1]);
			sln=getdir(list[i]);
			switch(fln)
			{
				case -1:
				ftag=i;
//				printf("\n[i:%d][fln:%d][sln:%d][ftag:%d]\n",i,fln,sln,ftag);
				break;
				case 1:
				fmp=i-1;
				smp=i;
//				printf("[fmp:%d][smp:%d]",fmp,smp);
					while(fmp>=ftag)
					{
						
						if(abs(list[fmp])>abs(list[smp]))
							list[smp++]=0;
						else if(abs(list[fmp])<abs(list[smp]))
							list[fmp--]=0;
						else {
							list[smp++]=0;
							list[fmp--]=0;
						}
						if(sln!=getdir(list[smp])||smp==len)
							break;
//					printf("[fmp:%d][smp:%d]",fmp,smp);
//					prtintstr(list,len);
					}
					break;
				default:break;
				}
			if(fmp==len)
				break;
			}
		}

	delzero(list,len);
	prtintstr(list,len);
	
	return list;
}

int main()
{
	int len=tmrand()%103+2;
	int *list;
	list=randlist(len);
	
	if(list==null)
	{
	printf("nullpointer");
	goto endl;
	}
	prtintstr(list,len);
	onejudge(list,len);
endl:
	scanf("%d",&len);
	return 0;
}