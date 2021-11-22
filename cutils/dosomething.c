#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <windows.h> 
#include<time.h>
#include<sys/time.h>
#include<conio.h>
#include <direct.h>
#include<string.h>
typedef struct Parse_File{
char* filename1;
char* filename2;
FILE* fp1;
FILE* fp2;
int filelen1;
int filelen2;
char* buf;
char* target;
}Psf;

int initFile(Psf*parse);
Psf* initParse(Psf*parse);
int parseFile(Psf*parse);
int exitParse(Psf*parse);
int delExplain(Psf*parse);

int logtag=0;
#define LOG printf("%s:[%d]\n",__func__,logtag++)

#define FILE_NAME "libnfc-nxp-pn557.conf"
#define TARGET_NAME "target-pn557.conf"

int main()
{
static Psf* parse;
parse =(Psf*) calloc(1,sizeof(Psf));
if(parse==NULL)
	printf("null pointer");
LOG;
parse->filename1=(char*)calloc(64,sizeof(char));
parse->filename2=(char*)calloc(64,sizeof(char));
parse->buf=(char*)calloc(512,sizeof(char));
snprintf(parse->filename1,strlen(FILE_NAME),FILE_NAME);
snprintf(parse->filename2,strlen(TARGET_NAME),TARGET_NAME);
LOG;

initFile(parse);
LOG;
delExplain(parse);
LOG;
exitParse(parse);
LOG;



int a;
scanf("%d",&a);
return 0;
}



int initFile(Psf*parse)
{
LOG;
	if((parse->fp1=fopen(parse->filename1,"r+"))==NULL)
		{
			printf("no such file,open file1 error\n");
			return -1;
	}
LOG;
	if((parse->fp2=fopen(parse->filename2,"w+"))==NULL)
		{
			printf("no such file,open file2 error\n");
			return -1;
	}
LOG;

fseek(parse->fp1,0,SEEK_END);
parse->filelen1=ftell(parse->fp1);
fseek(parse->fp1,0,SEEK_SET);
LOG;

fseek(parse->fp2,0,SEEK_END);
parse->filelen2=ftell(parse->fp2);
fseek(parse->fp2,0,SEEK_SET);
LOG;

return 0;
}






int parseFile(Psf*parse)
{
delExplain(parse);
return 0;
}

//this function is delete the explain in the libnfc-nxp.conf
int delExplain(Psf*parse)
{
int i=parse->filelen1;
char cfp;
int headtag=0;
int explaintag=0;
LOG;
while(i)
{

	headtag=0;
	explaintag=0;
	if(!headtag)
	{
	while(1){
	cfp=fgetc(parse->fp1);
	i--;
	//putchar(cfp);
	
	if(cfp==' ')
		continue;

	if(!headtag&&cfp=='#')
		{
		explaintag=1;
		}

	if(cfp=='\n'||cfp==10)
		{
		printf("i=%d:headtag=%d:read end line\n",i,headtag);
		if(!headtag)
			break;
		if(explaintag)
			break;
		
		*(parse->buf+headtag++)=cfp;
		*(parse->buf+headtag++)=0;
		fwrite(parse->buf,1,headtag,parse->fp2);
		printf("buf:%s\n",parse->buf);
		break;
		}
	*(parse->buf+headtag++)=cfp;
	
	};//while
	

	}
	
}
LOG;

return 0;
}


int exitParse(Psf*parse)
{
fclose(parse->fp1);
fclose(parse->fp2);
free(parse->filename1);
free(parse->filename2);
free(parse->buf);
free(parse->target);
free(parse);
return 0;
}























