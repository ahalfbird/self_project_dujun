#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define CIMG_HLINE 	11
#define CIMG_VLINE 	12
#define CIMG_IMG1  	13
#define CIMG_NULL	0

int img_prt(int sel)
{
	char*p=src;
	printf("p",src);
	return 0;
}

char* getstr(int sel)
{
	static char*src;
	
	switch(sel)
	{
		case 0:
		printf("\n\n");
		
		case 11:
		src="\n-------------------------\n";
		break;
		case 12:
		src="\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n";
		break;
		case 13:
		src="\n\
			********************\
			*********OO*********\
			*********OO*********\
			********O**O********\
			*****OOO****OOO*****\
			**OOO*O******O*OOO**\
			*O****************O*\
			*OOOOOOOOOOOOOOOOOO*\
			*O*****OO**OO*****O*\
			********************\
			********************\
			\n";
		break;
		default:
		printf("");
		break;
	};
	return 0;
}
int main()
{
	
	return 0;
}