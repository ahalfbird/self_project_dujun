#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

#define OVER_FLOW -2

struct FIFOlist{
  int *head;
  int *tail;
  int *list;
  int listnum;
  int elenum;
};

int FIFOinit(struct FIFOlist*list,int listnum){


    list->list=(int*)calloc(listnum,sizeof(int));
    list->listnum=listnum;
    list->elenum=0;
    list->head=list->list;
    list->tail=list->list;
    return listnum*sizeof(int);
};

int FIFOadd(struct FIFOlist*list,int*ele){

    if(list->elenum==list->listnum)
    {
        printf("FIFOlist is full so that you cannot add element at all!\n");
        return OVER_FLOW;
    }

	*(list->tail)=*ele;
	
	if((list->tail-list->list)!=list->listnum-1)
    list->tail++;
	else list->tail=list->list;
	
    return ++list->elenum;

};

int FIFOdel(struct FIFOlist*list){

	switch(list->elenum){
		case 0:
		printf("FIFOlist is blank!\n");
        return 0;
		case 1:
		*(list->head)=0;
		list->head=list->list;
		list->tail=list->list;
		list->elenum=0;
		break;
		default:
		*(list->head)=0;
	if((list->head-list->list)!=list->listnum-1)
    list->head++;
	else list->head=list->list;
return --list->elenum;
		
	};
};

int FIFOprt(struct FIFOlist*list)
{
	printf("prt\n");
    int *ip=list->list;
//    printf("[%d][%d]:",list->elenum,list->listnum);
    while(ip<list->list+list->listnum)
    {
	printf("[%6d]  ",*ip++);
	}
	printf("\n");
    return 0;
}

int FIFOshow(struct FIFOlist*list)
{
	printf("show\n");
    int *ip=list->head;
	for(int i=0;i<list->elenum;i++)
    {
		
		printf("[%6d]  ",*ip++);
		if(ip==list->list+list->listnum)
			ip=list->list;
	}
	printf("\n");
    return 0;
}

int FIFOfree(struct FIFOlist*list)
{
    free(list->list);
    free(list);
    return 0;
}

 int main(int argc, char *argv[])
{

     struct FIFOlist *fifo=(struct FIFOlist*)calloc(sizeof(struct FIFOlist),1);
     
	 
     FIFOinit(fifo,8);
     
	
	
	int a=0;
     for(int i=0;i<10;i++)
     {
		 a=rand();
         FIFOadd(fifo,&a);
		 FIFOshow(fifo);
         if(rand()%2)
         {FIFOdel(fifo);
		 FIFOprt(fifo);}
     }

     FIFOfree(fifo);
	 
	getchar();
    return 0;
}
 
