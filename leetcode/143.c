/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1：



输入：head = [1,2,3,4]
输出：[1,4,2,3]
示例 2：



输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
 

提示：

链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000

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


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* genList(int len)
{
	int i=0;
	struct ListNode* head;
	struct ListNode* p;
	
	for(i=0;i<len;i++)
	{
		if(!i)
		{
			head=(struct ListNode*)calloc(1,sizeof(struct ListNode));
			p=head;
			p->val=i+1;
		}
		else {
			p->next=(struct ListNode*)calloc(1,sizeof(struct ListNode));
			p->next->val=i+1;
			p=p->next;
		}
		p->next=NULL;
	}
	
	return head;
}

int prtList(struct ListNode* head,int len)
{
	
	struct ListNode*tp=head;
	PRTN
	printf("List:  ");
	for(int i=1;i<=len;i++)
	{
		printf("[%4d]",tp->val);
		tp=tp->next;
	}
	PRTN
}
int getListLen(struct ListNode* node)
{
	int i=1;
	struct ListNode*p=node;
	while(p->next!=NULL)
	{
		p=p->next;
		i++;
	}
	return i;
}
int isNodeTail(struct ListNode* node)
{
	if(node->next!=NULL)
		return 1;
	return 0;
}

struct ListNode* flipList(struct ListNode* head,int len)
{
	//len is element num 
	struct ListNode* hp=head;
	struct ListNode* fst=head;
	struct ListNode* tp1;
	int i=1;
	while(i<=len)
	{
		if(!isNodeTail(fst))
			break;
		tp1=fst->next;
		fst->next=tp1->next;
		tp1->next=hp;
		hp=tp1;
		i++;
	}
	fst->next=NULL;
	return hp;
}

struct ListNode* getIndexNode(struct ListNode* head,int index)
{
	//index--1--head
	int i=0;
	struct ListNode* ip=head;
	for(i=1;i<index;i++)
		ip=ip->next;
	return ip;
}

void reorderList(struct ListNode* head){
	int i=0;
	int len=getListLen(head);
	int mid=(len+1)/2;
	struct ListNode* midp=head;
	struct ListNode* hp=head;
	midp=getIndexNode(head,mid+1);
	midp=flipList(midp,len-mid);
	struct ListNode* ohp=head;
	struct ListNode* omp=midp;
	struct ListNode* tp1=head,*tp2=midp;
	for(i=1;i<=len-mid;i++)
	{
		tp1=ohp->next;
		ohp->next=omp;
		tp2=omp->next;
		omp->next=tp1;
		//insert midp node to head
		ohp=tp1;
		omp=tp2;
		//reset head and midp
	}
	prtList(hp,len);
	
}


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



int main()
{
	int len;
	len=tmrand()%10+5;
	struct ListNode* head=genList(len);
	prtList(head,len);
	reorderList(head);

	scanf("%d",&len);
	return 0;
}