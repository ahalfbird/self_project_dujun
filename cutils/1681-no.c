/*
1681. 最小不兼容性
给你一个整数数组 nums​​​ 和一个整数 k 。你需要将这个数组划分到 k 个相同大小的子集中，使得同一个子集里面没有两个相同的元素。

一个子集的 不兼容性 是该子集里面最大值和最小值的差。

请你返回将数组分成 k 个子集后，各子集 不兼容性 的 和 的 最小值 ，如果无法分成分成 k 个子集，返回 -1 。

子集的定义是数组中一些数字的集合，对数字顺序没有要求。

 

示例 1：

输入：nums = [1,2,1,4], k = 2
输出：4
解释：最优的分配是 [1,2] 和 [1,4] 。
不兼容性和为 (2-1) + (4-1) = 4 。
注意到 [1,1] 和 [2,4] 可以得到更小的和，但是第一个集合有 2 个相同的元素，所以不可行。
示例 2：

输入：nums = [6,3,8,1,3,1,2,2], k = 4
输出：6
解释：最优的子集分配为 [1,2]，[2,3]，[6,8] 和 [1,3] 。
不兼容性和为 (2-1) + (3-2) + (8-6) + (3-1) = 6 。
示例 3：

输入：nums = [5,3,3,6,3,3], k = 3
输出：-1
解释：没办法将这些数字分配到 3 个子集且满足每个子集里没有相同数字。
 

提示：

1 <= k <= nums.length <= 16
nums.length 能被 k 整除。
1 <= nums[i] <= nums.length
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
#define PRTCT countprt(__func__);

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

int countprt(char*str)
{
	static int i=0;
	printf("step=%d,%s\n",i++,str);
	return i;
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

int judgeen(int *list,int len,int k)
{
	int slen=len/k;
	int i=0,j=0;
	int numnum=0;
	for(i=1;i<len;i++)
	{
		
		if(*(list+i-1)==*(list+i))
		{
			numnum=1;
			while(*(list+i-1)==*(list+i))
			{
				numnum++;
				i++;
			}
			if(numnum>k)
				return 0;
		}
	else numnum=0;
	}
	return 1;
}
int judgeend(int *list,int len,int k)
{
	int slen=len/k;
	int i=0,j=0;
	int numnum=0;
	for(i=0;i<k;i++)
	{
		sortlist(&*(list+i*len/k),slen);
		for(l=1;l<len/k;l++)
			{
				if(*(sublist+i*len/k+l-1)!=*(sublist+i*len/k+l))
					continue;
				else return 0;
			}
	}
	return 1;
}

int delsingleeq(int *list,int p,int k,int &tag,int len)
{
	int i=0;
	for(i=p+1;i<len;i++)
	{
		if(*(list+i-1)!=*(list+i))
			break;
	}
	
	
	
	
	return tag;
}

int *dosublist(int *list,int len,int k)
{
	printf("\n***********************dosublist is start, k=%d*******************************\n",k);
	int *sublist=(int *)calloc(len,sizeof(int));
	memcpy(sublist,list,len*sizeof(int));
	sortlist(sublist,len);
	prtintstr(sublist,len);
	if(judgeen(sublist,len,k))
	printf("\nthis list is ok\n");
	else printf("\nthis list is not ok\n");
	
	 if(k==len)
		 return prtintstr(sublist,len);


	prtintstr(sublist,len);
	printf("\n***********************dosublist is end*******************************\n");
	return sublist;
}


int main()
{
	int len=tmrand()%16+1;
	len=16;
	int *list=(int *)calloc(len,sizeof(int));
	int i=0,jj=0;
	for(jj=0;jj<10;jj++){
	randlist(list,len);
	prtintstr(list,len);
	if(list==null)
	{
	printf("nullpointer");
	goto endl;
	}

	for(i=2;i<len;){
	dosublist(list,len,i);
	i=i*2;
	}

	}

endl:
	scanf("%d",&len);
	return 0;
}