
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

FILE *filelog_p;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeStack {
	int count;
	int max;
	char *steptag;
	struct TreeNode **list;
};
struct TreeStack stack;
int tmrand()
{
	static int sametag;
//	logfprintf("[sametag:%d]",sametag);
	struct timespec timestamp;
	clock_gettime(CLOCK_REALTIME, &timestamp);
	if(sametag==timestamp.tv_nsec)
		return rand();
	srand(timestamp.tv_nsec);
	sametag=timestamp.tv_nsec;
	return rand();
}

int logfprintf(char *format, ...)
{
	va_list args;
	va_start(args,format);
	vfprintf(filelog_p,format,args);
	vprintf(format,args);
	va_end(args);
	fflush(filelog_p);
	return 0;
}


int prtStack()
{
	int i=0;

	logfprintf("\n[%s][count:%d][max:%d]\n",__func__,stack.count,stack.max);
	for(i=0;i<stack.max;i++)
	{
		if(stack.list[i]==NULL)
		{
			if(i==0)
			{
				logfprintf("didnot gen any node in stack\n");
			return -1;
			}
			else {
				break;
			}
		}
		logfprintf("[%d][val:%d][tag:%d]\n",i,(stack.list[i])->val,*(stack.steptag+i));

	}
	return i;
}

int prtTree(struct TreeNode* head,int mode)
{
	int tmpmode=mode;
	if((tmpmode&0xf0)==0x00)
	{
		logfprintf("\n<<<=================TreeNode[tmpmode=%d]====================\n",tmpmode);
		tmpmode=tmpmode|0x10;
	}
	switch(tmpmode&0x0f)
	{
		case 0:
		logfprintf("[%2d]",head->val);
		if(head->left!=NULL)
			prtTree(head->left,tmpmode);
		if(head->right!=NULL)
			prtTree(head->right,tmpmode);
		
		break;
		case 1:
		if(head->left!=NULL)
			prtTree(head->left,tmpmode);
		logfprintf("[%2d]",head->val);
		if(head->right!=NULL)
			prtTree(head->right,tmpmode);
		
		break;
		case 2:
		if(head->left!=NULL)
			prtTree(head->left,tmpmode);
		if(head->right!=NULL)
			prtTree(head->right,tmpmode);
		logfprintf("[%2d]",head->val);
		
		break;
		default:
		logfprintf("cannot reference node\n");
		break;
	}
	if((tmpmode&0xf0)==0x10&&(mode&0xf0)==0x00)
	{
		logfprintf("\n====================TreeNode[tmpmode=%d]=================>>>\n",tmpmode);
		tmpmode=tmpmode|0x30;
	}
	return 0;
}



int isGenChild()
{
	//75% to gen child 
	return tmrand()%8;
}

struct TreeNode * pushTreeStack()
{
	struct TreeNode *pgen=(struct TreeNode *)calloc(1,sizeof(struct TreeNode));
	pgen->left=NULL;
	pgen->right=NULL;
	pgen->val=tmrand()%100;
	stack.list[stack.count+1]=pgen;
	return pgen;
}

struct TreeNode * popTreeStack()
{
	stack.list[stack.count]=NULL;
	stack.count--;
	return stack.list[stack.count];
}

int prtSTree(struct TreeNode* head,int mode)
{
	
	return 0;
}
struct TreeNode*genTree()
{
	struct TreeNode *head;
	struct TreeNode *pgen;
	stack.max=4;
	stack.steptag=(char*)calloc(stack.max+1,sizeof(char));
	*(stack.steptag+stack.max)='\0';
	stack.list=(struct TreeNode**)calloc(stack.max,sizeof(struct TreeNode*));
	stack.count=0;
	
	//atomatic operation, donot separate code
	pgen=(struct TreeNode *)calloc(1,sizeof(struct TreeNode));
	pgen->left=NULL;
	pgen->right=NULL;
	pgen->val=tmrand()%16;
	stack.list[stack.count]=pgen;
	stack.steptag[stack.count]=0;
	head=pgen;
	/*
	tagmap 
	value			indication( right | left | this node -----0 no go through | 1 go through and has node | 2 go through but no node)
	0x00			0 0 0
	0x01			0 0 1
	0x02			0 0 2 ----this would not be appeared.
	0x05			0 1 1
	0x09			0 2 1
	0x15			1 1 1
	0x19			1 2 1
	0x25			2 1 1
	0x29			2 2 1
	*/
	

unsigned short node_num=1;
unsigned short ctrl_flag=0;
/*
value				indication
0					not start
1					generating nodes
2					poping stack,return back
3					succeed to gen all nodes
4					some errors orrored in circle
*/

while(1){

	Sleep(40);
	logfprintf("<<<[%2d][%2d][0x%2x]>>>",ctrl_flag,stack.count,stack.steptag[stack.count]);
	if(stack.count<stack.max-1)
	{
		switch(stack.steptag[stack.count])
		{
			
		case	0x00:
		//start to deal node
		ctrl_flag=1;
		stack.steptag[stack.count]=0x01;
		case	0x01:
		//gen left child node or not
				if(isGenChild())
			{
				node_num++;
				(stack.list[stack.count])->left=pushTreeStack();
				stack.steptag[stack.count]=0x05;
				++stack.count;
			}
		else {
				stack.steptag[stack.count]=0x09;
			}
		break;
		
		
		case	0x05:
		//curnode gens left node, start to gen right node
		case	0x09:
		//curnode didnot gen left node, start to gen right node
				if(isGenChild())
			{
				node_num++;
				(stack.list[stack.count])->right=pushTreeStack();
				stack.steptag[stack.count]+=0x10;
				++stack.count;
			}
		else {
				stack.steptag[stack.count]+=0x20;
			}
		break;
		
		
		
		case	0x15:
		//curnode gens two child node, return back to parent
		case	0x19:
		//curnode gens right child node, return back to parent
		case	0x25:
		//curnode gens left child node, return back to parent
		case	0x29:
		//curnode didnot gen any child node, return back to parent
		popTreeStack();
		ctrl_flag=2;
		if(stack.count==0&&(stack.steptag[stack.count]&0xf0)!=0)
		{
			//curnode is head and already go through all node
			ctrl_flag=3;
		}
		else ctrl_flag=2;
		break;
		
		
		
		default:
		//step into error condition
		ctrl_flag=4;
		break;
		
		}
		
	} else {
		//this node is the tail of tree
		stack.steptag[stack.count]=0x29;
		popTreeStack();
		ctrl_flag=2;
	}
	if(ctrl_flag==3||ctrl_flag==4)
		break;
}
	printf("\ngen %d nodes",node_num);
	return head;
}

struct TreeNode*genTreeByManual()
{
	int i=0;
	
	struct TreeNode*head;
	head=(struct TreeNode *)calloc(10,sizeof(struct TreeNode));
	
	for(i=0;i<10;i++)
		(*(head+i)).val=i;
	(*(head+0)).left=(head+1);
	(*(head+0)).right=(head+2);
	
	(*(head+1)).left=(head+3);
	(*(head+1)).right=(head+4);
	
	(*(head+2)).left=NULL;
	(*(head+2)).right=(head+5);
	
	(*(head+3)).left=(head+6);
	(*(head+3)).right=NULL;
	
	(*(head+4)).left=NULL;
	(*(head+4)).right=(head+7);
	
	(*(head+5)).left=(head+8);
	(*(head+5)).right=(head+9);

	(*(head+6)).left=NULL;
	(*(head+6)).right=NULL;
	
	(*(head+7)).left=NULL;
	(*(head+7)).right=NULL;
	
	(*(head+8)).left=NULL;
	(*(head+8)).right=NULL;
	
	(*(head+9)).left=NULL;
	(*(head+9)).right=NULL;
	
	
	return head;
}

int main()
{
	int len;
	logfprintf("\n\nmain start\n");
	struct TreeNode*head;
	struct TreeNode*mhead;
	
	filelog_p=fopen("log.txt","a+");
	
	
	head=genTree();
	if(head==null)
		logfprintf("\nhead is null\n");
	prtTree(head,0);
	prtTree(head,1);
	prtTree(head,2);
	
	fclose(filelog_p);
	logfprintf("\nmain end\n\n");
	scanf("%d",&len);
	

	return 0;
}