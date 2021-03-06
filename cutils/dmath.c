/*
This file is used to get common factor and common multiple with two numbers.
*/

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h>
#include<sys/time.h>
#include<windows.h>
#pragma pack(1);

#define CHARPRTLEN 50
#define PRTN putchar('\n');
#define PRTF(chs) printf("[%s:%s]\n",__func__,chs);

/*复杂度计算数*/
static int CirCount=0;
/*输出50个字符*/
int prtchs(char ch)
{
	char* chs=(char*)calloc(CHARPRTLEN,sizeof(char));
	int i=CHARPRTLEN;
	while(i)
	*(chs+--i)=ch;
	printf("%s",chs);
	return 0;
}
/*产生随机数*/
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
/*输出int数组*/
int prtintstr(int *str,int len)
{
int sum=0;
	PRTN
	prtchs('=');
	PRTN
	int i;
	for(i=0;i<len;i++){
	printf("[%d]",*(str+i));
	sum +=*(str+i);
	}
	PRTN
	prtchs('=');
	PRTN
	return sum;
}
/*产生随机数组*/
int *randlist(int *list,int len)
{
	int i=0;
	for(i=0;i<len;i++)
		*(list+i)=tmrand()%16+1;
	return list;
}
/*递归型归并排序*/
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

/*得出数字的所有因数*/
int *getFactor(int a)
{
//	PRTF("start")
	int *stack;
	if(a==1)
	{
		stack=(int*)calloc(2,sizeof(int));
		*stack=*(stack+1)=1;
		return stack;
	}
	int len=(int)(log(a)*1.0/log(2))+1;
	stack=(int*)calloc(len,sizeof(int));
	*stack=1;
	
	int tmp=a;
	int tfac=2;
	while(1)
	{
		
		CirCount++;
		if(tmp%tfac==0)
		{
//			PRTF("find factor")
			*(stack+*stack)=tfac;
			(*stack)++;
			tmp=tmp/tfac;
			
		}
		else{
//			PRTF("not find factor")
			if(tfac!=2)
				tfac+=2;
			else tfac++;
		}
//		printf("tfac=%d tmp=%d len=%d CirCount=%d",tfac,tmp,len,CirCount);
//		prtintstr(stack,len);
		if(tmp==1||tfac>tmp||*stack>len)
		break;
	}
//	prtintstr(stack,len);
	return stack;

}

/*得出公因数*/
int getCommonFactor(int a,int b)
{
int *stacka=getFactor(a);
int *stackb=getFactor(b);
int cfactor=1;
int ia=1,ib=1;
for(;(ia<*stacka)&&(ib<*stackb);)
{
	CirCount++;
	if(*(stacka+ia)>*(stackb+ib))
	{
		ib++;
	}
	else if(*(stacka+ia)<*(stackb+ib))
	{
		ia++;
	}
	else {
		cfactor*=*(stacka+ia);
		ia++;ib++;
	}
}
	free(stacka);
	free(stackb);
	return cfactor;
}

/*得出公倍数*/
int getCommonMultiple(int a,int b)
{
	return a*b/getCommonFactor(a,b);
}

double getInstanceALB(double ax, double ay,double bx, double by)
{
	double s=0;
	s=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
	s=sqrt(s);
	return s;
}

double* getIntersectionPointLALB(double a1x, double a1y,double a2x, double a2y,double b1x, double b1y,double b2x, double b2y)
{
	double LA[3];//ax+by+1=0;
	double LB[3];//ax+by+1=0;
	double *result;
	result=(double*)calloc(3,sizeof(double));
	LA[2]=LB[2]=1;
	LA[0]=(b1y-a1y)*1.0/(a2x*a1y-a2y*a1x);
	LA[1]=(a1x-b1x)*1.0/(a1x*a2y-a2x*a1y);
	LB[0]=(b2y-a2y)*1.0/(b2x*b1y-b2y*b1x);
	LB[1]=(a2x-b2x)*1.0/(b1x*b2y-b2x*b1y);
	if(LA[0]*LB[1]==LA[1]*LB[0])
	{
		//两条线平行或重合
		if(LA[0]==LB[0])
		{
			*result=-513;//重合的线
			*(result+1)=0;
		}else {
			*result=-512;//平行线
			*(result+1)=abs(a2x/a1x-1)*1.0/sqrt(LB[0]*LB[0]+LB[1]*LB[1]);
		}
		*(result+2)=0;
		return result;
	}
	double adx= a2x-a1x;
	double ady= a2y-a1y;
	double bdx= b2x-b1x;
	double bdy= b2y-b1y;
	double kbottom=bdx*ady-adx*bdy;
	if(kbottom)
	return NULL;
	double px= (  bdx*adx*(b1y-a1y)  - bdy*adx*b1x + bdx*ady*a1x  ) / kbottom;
	double py= (  bdy*ady*(a1x-b1x)  - bdy*adx*a1y + bdx*ady*b1y  ) / kbottom;
	*result=512;
	*(result+1)=px;
	*(result+2)=py;
	return result;
}

/*the instance between a and line with b & c*/
double getInstanceALB(double ax, double ay,double bx, double by,double cx, double cy)
{
	double inst=0;
	//line ax+by+1=0;
	double a=(cy-by)*1.0/(cx*by-bx*cy);
	double b=(cx-bx)*1.0/(bx*cy-cx*by);
	inst=abs(ax*a+ay*b+1)*1.0/sqrt(a*a+b*b);
	return inst;
}

int seqfunc1(int n,int *param)
{
	//等差数列, 差值1, param[0]为初值
	return n+*param-1;
}

int seqfunc2(int n,int *param)
{
	//等比数列, param[0]为初值, param[1]为比值
	return pow(param[1],n-1)*param[0];
}

int seqfunc3(int n,int *param)
{
	//Fibonacci数列
	if(n==1)
		return 1;
	if(n==2)
		return 1;
	else return seqfunc3(n-1,NULL)+seqfunc3(n-2,NULL);
}

int seqfunc4(int n,int *param)
{
	//回摆数列1,-1,1,-1,...
	return (n%2)*2-1;
}

int seqfunc4(int n,int *param)
{
	//锯齿数列
	return abs(n%c-c/2)*(b-a)*2/c+a;
}

int Sequence(int (*SeqFunc)(int,int*),int n,int *param)
{
	int num=init;
	for(int i=1;i<n;i++)
		init=SeqFunc(n,init);
	return 0;
}


/*
ax1,ay1
ax2,ay2
bx1,by1
bx2,by2
(ay2-ay1)(px-ax1)=(ax2-ax1)(py-ay1)   ==>  ady*px = ady*ax1 +adx(py-ay1)
(by2-by1)(px-bx1)=(bx2-bx1)(py-by1)   ==>  bdy*px = bdy*bx1 +bdx(py-by1)

ady*px = ady*ax1 +adx(py-ay1)
ady*px = (bdy*bx1 +bdx(py-by1))(ady/bdy)
0=       ady*ax1 +adx(py-ay1) - (bdy*bx1 +bdx(py-by1))(ady/bdy)     ==>  ady*ax1 +adx(py-ay1) -ady*bx1 - bdx(py-by1)*ady/bdy

0=       ady*ax1 +adx(py-ay1) -ady*bx1 - bdx(py-by1)*ady/bdy
0=       ady*(ax1-bx1)+ adx*py-adx*ay1 - bdx*ady/bdy*py + bdx*ady/bdy*by1
0=       (adx-bdx*ady/bdy)*py + ady*(ax1-bx1) -adx*ay1 + bdx*ady/bdy*by1
0=       (adx*bdy-bdx*ady)*py + bdy*ady*(ax1-bx1)- adx*bdy*ay1 + bdx*ady*by1

py=     [  bdy*ady*(ax1-bx1)- adx*bdy*ay1 + bdx*ady*by1  ] / (bdx*ady-adx*bdy)

px= ax1 + (py-ay1)*adx/ady
px= ax1 -ay1*adx/ady + py*adx/ady  ==> px = k20_1 + py*adx/ady

px= k20_1 + [  bdy*ady*(ax1-bx1)- adx*bdy*ay1 + bdx*ady*by1  ] *adx/ady / (bdx*ady-adx*bdy)
px= k20_1 + [  bdy*adx*(ax1-bx1)- adx*bdy*ay1*adx/ady + bdx*adx*by1  ]  / (bdx*ady-adx*bdy)
px= [ (ax1 -ay1*adx/ady)*(bdx*ady-adx*bdy)  +  bdy*adx*(ax1-bx1)- adx*bdy*ay1*adx/ady + bdx*adx*by1   ] /  (bdx*ady-adx*bdy)  ==>  px=[...]/ k26_1

px= [ ax1*bdx*ady+ay1*adx*adx*bdy/ady -ax1*adx*bdy - ay1*adx*bdx + bdy*adx*ax1 - bdy*adx*bx1  - ay1*adx*adx*bdy/ady + bdx*adx*by1        ]/k26_1
px=     [ ax1*bdx*ady - bdy*adx*bx1 + bdx*adx*(by1-ay1)  ]/ k26_1

py=     [  bdy*ady*(ax1-bx1)  - bdy*adx*ay1 + bdx*ady*by1  ] / (bdx*ady-adx*bdy)
px=     [  bdx*adx*(by1-ay1)  - bdy*adx*bx1 + bdx*ady*ax1  ] / (bdx*ady-adx*bdy)
*/

