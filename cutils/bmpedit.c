#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h>
#include<sys/time.h>
#include<windows.h>
#include "bmp.h"
#pragma pack(1);



 int main(int argc, char *argv[])
{

int width=400;
int height=300;
char* name="target.bmp";

struct bmpheader header;
inithead(&header);
header.head.size=54+3*width*height;
header.info.width=width;
header.info.height=height;
header.info.sizeimage=3*width*height;

struct RGB*colors;
colors=setcolor(header);

FILE* f = fopen(name,"wb");
fwrite(&header,sizeof(struct bmpheader),1,f);
fwrite(colors,header.info.sizeimage,1,f);
fclose(f);



printf("\n\nmain ok");
getchar();
return 0;
}
 
 
 
 
 
