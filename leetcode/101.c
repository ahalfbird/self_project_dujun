/*
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3


*/

// doesnot finish
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
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


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

struct TreeNode* selectNode(struct TreeNode* node,int mode)
{
	//mode=1  select max, mode=0 select min
	int tag=0;
	if(node->left==NULL)
		tag+=1;
	if(node->right==NULL)
		tag+=2;
	switch(tag)
	{
		case 0:return NULL;
		case 1:return node->left;
		case 2:return node->right;
		default:break;
	}
	tag=0;
	if(node->left->val < node->right->val)
		tag+=4;
	if(mode)
		tag+=8;
		switch(tag)
	{
		case 0:return node->right;
		case 4:return node->left;
		case 8:return node->left;
		case 12:return node->right;
		default:break;
	}
	return NULL;
}

int viaTree(struct TreeNode* head,int *list,int lp)
{
	
	if(head==NULL)
		return 0;
	list[lp]=head->val;
	if(list->left==NULL)
		list[++lp]=0;
	else{
	list[++lp]=head->left->val;
	viaTree(head->left,list,lp);
	}
	if(list->right==NULL)
		list[++lp]=0;
	else{
	list[++lp]=head->right->val;
	viaTree(head->right,list,lp);
	}
}

int * goTree1(struct TreeNode* head)
{
	struct TreeNode*p1,*p2;
	p1=head->left;
	p2=head->right;
	
	
}

int main()
{
	int len;

	scanf("%d",&len);
	return 0;
}