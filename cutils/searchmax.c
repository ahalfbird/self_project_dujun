#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#include <time.h>
//get the sum of the list

#define PRTAT printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");\
printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");

double gdata[20][10];
double iisum[10];

double sum1(double*data,int dlen)
{
    double sum=0;
    for(int i=0;i<dlen;i++)
        sum+=(double)*(data+i);
return sum*20/dlen;
}

double copyto(double *from,double *to,int dlen)
{
	for(int i=0;i<dlen;i++)
        *(to+i)=*(from+i);
	return 0;
}

//step1:fill the rand data
double datarand(double*data,int dlen)
{
	srand((unsigned)time(0)); 
    for(int i=0;i<dlen;i++)
        *(data+i)= rand()%20;
    return sum1(data,dlen);
}

//step2:modify the rand data so that the sum of the list is equal to half of10*dlen 
double datamodify(double*data,int dlen)
{
	double div=200/sum1(data,dlen);
	for(int i=0;i<dlen;i++)
        *(data+i)=*(data+i)*div;
	return sum1(data,dlen);
}

double dataiisum(double*data,int dlen)
{
	 double sum=0;
	 double dp=0;
    for(int i=0;i<dlen;i++){
		dp=pow(*(data+i),2)*20/dlen;
		sum+=dp;
	}
return sum;
}
int dataprt(double*data,int dlen)
{
		printf("\n***[%d]***\n\n",dlen);
	for(int i=0;i<dlen;i++)
	{
		printf("@[%lf]@",*(data+i));
	}
//		printf("\n***[%.12lf]***\n\n",sum1(data,dlen));
	return 0;
}

double datatest1(double*data,int dlen)
{
	datarand(data,dlen);
//	dataprt(data,dlen);
	datamodify(data,dlen);
//	dataprt(data,dlen);
	return dataiisum(data,dlen);
}



int datatest2(double *data,int dlen)
{
	
	
	double iist=0,iism=0;
	for(int i=0;i<10;i++)
	{
		iist=datatest1(data,dlen);
		if(!iism||iism>iist)
		{
			copyto(data,gdata[dlen/2-1],dlen);
			iism=iist;
		}
			
	}
	iisum[dlen/2-1]=iism;
	printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("when len=%d,iimin=%lf\n",dlen,iism);
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	dataprt(gdata[dlen/2-1],dlen);
	return 0;
}

int fileinput()
{
	const char*filename ="data.txt";
	FILE*fp=fopen(filename,"w");
	if(fp==NULL)
	{
		PRTAT
		printf("open file error");
		return -1;
	}
	for(int i=0;i<10;i++)
	{
		fprintf(fp, "\n\n\ndata number:%d----iisum:%lf\n\n",i*2+2,iisum[i]); 
		for(int j=0;j<i*2+2;j++)
		{
			fprintf(fp,"[%lf]",gdata[j][i]);
		}
	}
	fclose(fp);
		PRTAT
		return 0;
}


int datatest3(double*data)
{
	for(int i=2;i<=20;i+=2)
		datatest2(data,i);
	return 0;
}

int main()
{
printf("env is ok\n\n\n");
double *datal=(double*)calloc(20,sizeof(double));



//datatest3(datal);
//free(datal);
//fileinput();
getchar();
return 0;
}

