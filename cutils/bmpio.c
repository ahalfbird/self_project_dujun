#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

struct bmp_head{
	char type[2];//type of bmp. it is must 'BM' here.
	unsigned int size;//size of bmp(bytes)
	short reserved1;//=0
	short reserved2;//=0
	unsigned int offset;//bmp data offset
	//14b
};

struct bmp_info{
	unsigned int bsize;//size of this struct
	int width;//bmp width (pixel/four bytes)
	int height;//bmp height (pixel/four bytes)
	unsigned short planes;//device level =1
	unsigned short count;//bit per pixel, must 1/4/8/24
	unsigned int compression;//0(no compress)/1(BI_RLE8)/2(BI_RLE4)
	unsigned int sizeimage;//size of bmp (bytes)
	unsigned int xmeter;//resolution of the horizon pixel/meter
	unsigned int ymeter;//resolution of the vertical pixel/meter
	unsigned int cused;//number of color table
	unsigned int cimportant;//number of important color
	//40b
};

struct bmp_pal{
	
};

struct RGB{
	unsigned char b;        
	unsigned char r; 
	unsigned char g;
	unsigned char a; 
};

struct bmp_data{
	int *data;
	     
};


struct bmp_file{
	struct bmp_head* head;
	struct bmp_info* info;
	struct bmp_data* data;
	struct bmp_pal* pal;
	
};


void prtchs(char*s,int length)
{
	for(int i=0;i<length;i++)
	{
		printf("%.2x ",*(s+i));
	}
	printf("\n");
}


 int main(int argc, char *argv[])
{
	
	FILE*f1,*f2;
	if((f1=fopen("test.bmp","r+"))==NULL)
	{
		printf("open not ok");
	}
	if((f2=fopen("test2.bmp","w+"))==NULL)
	{
		printf("open not ok");
	}
	
	fseek(f1,0,SEEK_END);
	char data[16];
	int tail=ftell(f1);
	printf("%d\n",tail);
	fseek(f1,0,SEEK_SET);
	for(int pos=0;pos<tail;pos+=16)
	{
		if(tail-pos<16)
			fread(data,1,tail-pos,f1);
	else fread(data,1,16,f1);
		
		fwrite(data,1,16,f2);  
	}
		
	 fclose(f1);
	 fclose(f2);
	 
	 printf("write end");
	getchar();
    return 0;
}
 
 
 
 
 
/*
BMP（全称Bitmap）是Windows操作系统中的标准图像文件格式，可以分成两类：
设备相关位图（DDB）和设备无关位图（DIB），使用非常广。
它采用位映射存储格式，除了图像深度可选以外，不采用其他任何压缩，
因此，BMP文件所占用的空间很大。
BMP文件的图像深度可选lbit、4bit、8bit及24bit。
BMP文件存储数据时，图像的扫描方式是按从左到右、从下到上的顺序。
由于BMP文件格式是Windows环境中交换与图有关的数据的一种标准，
因此在Windows环境中运行的图形图像软件都支持BMP图像格式。

在windows中，颜色顺序是：B G R。
   2、BMP的内存行顺序和图像显示的行顺序是上下颠倒的。
        即：BMP内存第0行，是真实图像下面的最后一行。
   举例，假如图像为2*2大小，像素三颜色按照RGB的顺序， 我们看到的图像为：
   1 2 3， 11 22 33
   4 5 6， 44 55 66

内存表示如下：
   6 5 4， 66 55 44 （0 0）   -- 第0行
   3 2 1， 33 22 11   （0 0）   -- 第1行
   注意，通常内存是需要内存对齐的，所以每行后面可能会有对齐所产生的0.

BMP文件的数据按照从文件头开始的先后顺序分为四个部分：
◆  位图文件头(bmp file header)：  提供文件的格式、大小等信息共14字节
◆  位图信息头(bitmap information)：提供图像数据的尺寸、位平面数、压缩方式、颜色索引等信息   共40字节
◆  调色板(color palette)：可选，如使用索引来表示图像，调色板就是索引与其对应的颜色的映射表
◆  位图数据(bitmap data)：图像数据区

bmp文件头包含如下信息：

bfType：2字节，文件类型；BMP格式的文件这两个字节是0x4D42，10进制就是19778，字符显示就是‘BM’；
bfSize：4字节，文件大小；检查文件信息，验证正确；
bfReserved1：2字节，保留，必须设置为0；
bfReserved2：2字节，保留，必须设置为0；
bfOffBits：4字节，从头到位图数据的偏移；表示从文件头到位图数据的偏移;

位图信息头（bitmap information）
位图信息头一共40字节，包含如下内容：
biSize：4字节，信息头的大小，即40；
biWidth：4字节，以像素为单位说明图像的宽度；
biHeight：4字节，以像素为单位说明图像的高度，同时如果为正，说明位图倒立（即数据表示从图像的左下角到右上角），如果为负说明正向；
biPlanes：2字节，为目标设备说明颜色平面数，总被设置为1；
biBitCount：2字节，说明比特数/像素数，值有1、2、4、8、16、24、32；
biCompression：4字节，说明图像的压缩类型，最常用的就是0（BI_RGB），表示不压缩；
biSizeImages：4字节，说明位图数据的大小，当用BI_RGB格式时，可以设置为0；
biXPelsPerMeter：表示水平分辨率，单位是像素/米，有符号整数；
biYPelsPerMeter：表示垂直分辨率，单位是像素/米，有符号整数；
biClrUsed：说明位图使用的调色板中的颜色索引数，为0说明使用所有；
biClrImportant：说明对图像显示有重要影响的颜色索引数，为0说明都重要；

调色板就是一个颜色的索引，这里是8位色图，一共有256中颜色，
由于每个颜色都有RGB三原色，也就是要3个字节表示，
这样的话256个颜色就不能表示所有的颜色，所以就需要一个索引，
用一个字节的索引指向4个字节表示的颜色（RGB加上Alpha值）。
如果把这4个字节表示为一个Color类型，那么调色板就是Color的数组。
由于Color类型也是一个数组，调色板就像一个二维数组palette[N][4]，
其中N是颜色的数量，这里就是256。


由于是8位色图，所以每个像素用1个字节表示，取出每个字节，
显示到相应的设备上就可以了。这里的biHeight为正数，说明图像倒立，
从左下角开始到右上角，以行为主序排列。如果是24位色图，
按照BGR的顺序排列，32位色图按照BGRAlpha排列。位图数据排列还有一个规则，
就是对齐。Windows默认的扫描的最小单位是4字节，如果数据对齐满足这个值的话
对于数据的获取速度等都是有很大的增益的。因此，BMP图像顺应了这个要求，
要求每行的数据的长度必须是4的倍数，如果不够需要进行比特填充（以0填充），
这样可以达到按行的快速存取。这样的话，
位图数据的大小就不一定是宽x高x每像素字节数了，因为每行还可能有0填充。


*/