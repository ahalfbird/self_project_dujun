/*
868. 二进制间距
给定一个正整数 n，找到并返回 n 的二进制表示中两个 相邻 1 之间的 最长距离 。如果不存在两个相邻的 1，返回 0 。

如果只有 0 将两个 1 分隔开（可能不存在 0 ），则认为这两个 1 彼此 相邻 。两个 1 之间的距离是它们的二进制表示中位置的绝对差。例如，"1001" 中的两个 1 的距离为 3 。

 

示例 1：

输入：n = 22
输出：2
解释：
22 的二进制是 "10110" 。
在 22 的二进制表示中，有三个 1，组成两对相邻的 1 。
第一对相邻的 1 中，两个 1 之间的距离为 2 。
第二对相邻的 1 中，两个 1 之间的距离为 1 。
答案取两个距离之中最大的，也就是 2 。
示例 2：

输入：n = 5
输出：2
解释：
5 的二进制是 "101" 。
示例 3：

输入：n = 6
输出：1
解释：
6 的二进制是 "110" 。
示例 4：

输入：n = 8
输出：0
解释：
8 的二进制是 "1000" 。
在 8 的二进制表示中没有相邻的两个 1，所以返回 0 。
示例 5：

输入：n = 1
输出：0
 

提示：

1 <= N <= 10^9
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
int randope(int *ope)
{
	*ope=tmrand();
	return *ope;
}
int getonelen(int ope)
{
	char bit[32];
	int bit_p=0;
	int read_p1=0;
	int read_p2=0;
	int len=0;
	int onetag=0;
	if(ope)
	{
		while(bit_p<32){
		printf("[bit_p=%d][read_p1=%d][len=%d][opebit=%c]\n",bit_p,read_p1,len,(ope&1)+'0');
		if(ope&1)
		{
			onetag++;
			if(!read_p1)
				read_p1=bit_p;
			else {
				if((bit_p-read_p1)>len)
				{
					len=bit_p-read_p1;
				}
				read_p1=bit_p;
			}
		}
		
		ope=ope>>1;
		bit_p++;
		
		}
	}
	else len=0;
	return len;
}
int main()
{
	int ope=0;
	int i=10;
	while(i--){
	randope(&ope);
	printf("\n[ope=%d][len=%d]\n",ope,getonelen(ope));
	}
	scanf("%d",&ope);
	return 0;
}

