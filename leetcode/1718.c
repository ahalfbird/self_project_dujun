/*给你一个整数 n ，请你找到满足下面条件的一个序列：

整数 1 在序列中只出现一次。
2 到 n 之间每个整数都恰好出现两次。
对于每个 2 到 n 之间的整数 i ，两个 i 之间出现的距离恰好为 i 。
序列里面两个数 a[i] 和 a[j] 之间的 距离 ，我们定义为它们下标绝对值之差 |j - i| 。

请你返回满足上述条件中 字典序最大 的序列。题目保证在给定限制条件下，一定存在解。

一个序列 a 被认为比序列 b （两者长度相同）字典序更大的条件是： a 和 b 中第一个不一样的数字处，a 序列的数字比 b 序列的数字大。比方说，[0,1,9,0] 比 [0,1,5,6] 字典序更大，因为第一个不同的位置是第三个数字，且 9 比 5 大。

 

示例 1：

输入：n = 3
输出：[3,1,2,3,2]
解释：[2,3,2,1,3] 也是一个可行的序列，但是 [3,1,2,3,2] 是字典序最大的序列。
示例 2：

输入：n = 5
输出：[5,3,1,4,3,5,2,4,2]
 

提示：

1 <= n <= 20
*/



#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
int prt(int *list,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("[%2d]",*(list+i));
	}
	putchar('\n');
	return 0;
}



int doope(int n)
{
	int *list;//操作队列
	int ope[n];//对应元素位置
	int succeed=0;//是否成功填入
	int fg1,fg2,fg3,fg4;
	int lp=0;//队列操作指针
	int opep=n-1;//等待操作的元素位置
	
	int i,j,k;//常用循环控制变量
	
	list=(int *)calloc(2*n+1,sizeof(int));
	*ope=0;
	*list=*(list+n)=n;//填入第一个元素n
	*(ope+opep)=0;
	opep--;
	lp++;
	if(n==1)
		return 0;
	while(succeed!=1)
	{
		lp=1;
		while(*(list+lp)!=0) lp++;//回溯lp指针
		
		printf("\n\nVAR:[succeed]%2d[lp]%2d[opep]%2d\nlist: ",succeed,lp,opep);
		prt(list,2*n-1);
		printf("ope: ");
		prt(ope,n);
		Sleep(1000);
		
		
		
		if(succeed==-1)//本轮失败,回溯
		{
			for(i=*(ope+opep);i<2*n-opep-2;i++)//向右推进节点,寻找本结点的其他可能
			{
				if((*(list+i)==0)&&(*(list+i+opep+1)==0))//存在可行节点
				{
					*(list+*(ope+opep))=*(list+*(ope+opep)+opep+1)=0;
					*(list+i)=*(list+i+opep+1)=opep+1;//填入list
					*(ope+opep)=i;//记录节点位置信息,更新操作栈
					opep--;//更新操作栈指针
					succeed=0;//更新标记
					break;
				}
			}
			
			if(i==2*n-opep-2)//本轮失败,回溯
				{
				*(list+*(ope+opep))=*(list+*(ope+opep)+opep+1)=0;//回溯list的数据
				*(ope+opep)=0;//回溯操作栈
				opep++;//回溯opep指针
				succeed=-1;//更新标记
				}
			continue;
		}
		
		if(succeed==0)//向下推进节点,寻找子节点的可能
		{
			
			if(opep==1)//正数第二个数
			{
			
				for(i=lp;i<2*n-3;i++)//当只剩2时,填入,或回溯或结束
				{
					if((*(list+i)==0)&&(*(list+i+2)==0))
					{	
						*(list+i)=*(list+i+2)=2;
						succeed=1;
						break;
					}
				}
				if(i==2*n-3)//本轮失败,回溯
				{
						*(ope+opep)=0;//回溯操作栈
						opep++;//回溯opep指针
						succeed=-1;//更新标记
				}
			}//2填入
			
			else
			{
				for(i=lp;i<2*n-opep-2;i++)//推进opep向下
				{
					if((*(list+i)==0)&&(*(list+i+opep+1)==0))//存在可行节点
					{
						*(list+i)=*(list+i+opep+1)=opep+1;//填入list
						*(ope+opep)=i;//记录节点位置信息
						opep--;//更新操作栈
						succeed=0;//更新标记
						break;
					}
				}
				if(i==2*n-opep-2)//本轮失败,回溯
				{
					opep++;//回溯opep指针
					succeed=-1;//更新标记
				}
			}
			continue;
		}
		
		
		
	}
	
	printf("\n------------------------\ncreate finish:");
	prt(list,2*n-1);
	getchar();
	return 0;
}



int main()
{
	int a;
	scanf("%d",&a);
	if(a>0&&a<21)
	doope(a);
	else return -1;
	getchar();
	return 0;
}

