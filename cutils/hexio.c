#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FTR fopen("aaaaaaa","w")


int realtohex(char*buf,int len)
{
	
//			printf("\n==>realtohex\n");

	int i=0;
	char*p=buf;
	for(i=0;i<len;i++)
	{
		
		if(!((i+1)%9)||!((i+1)%36))
			;
		else if(*(p+i)>=0&&*(p+i)<10)
			*(p+i)+=48;
		else if(*(p+i)>9&&*(p+i)<16)
			*(p+i)+=55;
		else *(p+i)='$';
		
		
	}
//	printf("realhexbuf:[%4d]\t\t\t%s\n",len,buf);
	return 0;
	
}


char* chartohex(char*buf,int len)
{
//		printf("\n==>chartohex\n");

	char* tmpbuf;
	tmpbuf=(char*)calloc(len*2+len/4+len/16+2,1);
	int i=0,j=0;
	char c;

	for(i=0,j=0;i<len;i++)
	{
		c=*(buf+i);

	if(!(i%16)&&i)
	{
		*(tmpbuf+j)='\n';
			j++;	
	}
	else if(!(i%4)&&i)
		{
			*(tmpbuf+j)=' ';
			j++;
		}
	else ;
		*(tmpbuf+j)=(c&0xF0)>>4;
		j++;
		*(tmpbuf+j)=c&0x0F;
		j++;
	
	
	}
	
	buf=tmpbuf;

	return tmpbuf;
}





int getname(char*name)
{
	printf("\n==>getname\n");
	scanf("%s",name);//max length is 63
	
	return strlen(name);
}


int hread(char* buf,char*name)
{
	FILE*f;
	printf("\n==>hread\n");
	int length;
	if((f=fopen(name,"r+"))==NULL)
	{
		
		printf("open not ok");
	}
	
	fseek(f,0,SEEK_END);
	length=ftell(f);
//	printf("\nlength=%d\n",length);
	fseek(f,0,SEEK_SET);
	
	fread(buf,length, 1, f);
	FTR;
	fclose(f);
	
//	printf("%s\n",buf);
	
	return length;
}

int hwrite(char* buf,char*name,int length)
{
	FILE*f;
	printf("\n==>hwrite\n");
//	printf("%s",buf);
	if((f=fopen(name,"w+"))==NULL)
	{
		printf("open not ok");
	}
	
	length=strlen(buf);
	fwrite(buf,length, 1, f);
	fclose(f);
	
	return length;
}

void pint(char*str,int len)
{
	putchar('\n');
	int i=0;
	for(i=0;i<len;i++)
	{
		printf("%3d,",*(str+i));
		
	}
	putchar('\n');
}

int main()
{
	
	int namlen=0;
	char*name="data";
	char*buf;
	int flen=0;
	int slen=0;
//	namlen=getname(name);
	buf=calloc(256,1);
	flen=hread(buf,name);
	

	slen=strlen(buf);
	printf("\n%s\n",buf);
//	pint(buf,slen);
	buf=chartohex(buf,slen);
//	pint(buf,slen*2+slen/4+slen/24+2);
	realtohex(buf,slen*2+slen/4+slen/24+2);
//	pint(buf,slen*2+slen/4+slen/24+2);
	printf("\n%s\n",buf);
	
	hwrite(buf,"data1",slen*2+slen/4+slen/24+2);
	
//	fflush(f);
	getchar();
	printf("1");
	getchar();
	printf("2");
	getchar();
	printf("3");
	getchar();
	printf("4");
	return 0;
	
}