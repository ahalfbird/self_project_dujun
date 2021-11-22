#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <windows.h> 
#include<time.h>
#include<sys/time.h>
#include<conio.h>
#include<math.h>

struct pstn{
	int x;
	int y;
};

struct direct{
	char d;//按位从大到小,向上1向下0,向左向右,比例
};

struct g_obj{
	char species;
	char *addmes;
	char *tag;
};

struct g_ant{
	int tag;
	struct pstn ps;
	
};

struct g_map{
	char *map;
	int lx;
	int ly;
	struct pstn in;
	struct pstn out;
};

struct g_road{
	struct pstn* pst;
	int length;
};

struct g_stack{
	
};




int g_srand()
{
	struct timespec timestamp;
	clock_gettime(CLOCK_REALTIME, &timestamp);
	srand(timestamp.tv_nsec);
	return 0;
}

int judge_sign(int a)
{
//	printf("\nfunc:judge_sign\n");
	
	if(!a)
		return 0;
	if(a>0)
		return 1;
	else return -1;
	
}

int judge_rl(struct pstn p1,struct pstn p2,struct pstn p3)
{
	printf("\nfunc:judge_rl\n");
	
	int v[2][2];
	v[0][0]=p2.x-p1.x;
	v[0][1]=p2.y-p1.y;
	v[1][0]=p3.x-p1.x;
	v[1][1]=p3.y-p1.y;
	int res=0;
	res=v[0][0]*v[1][1]-v[1][0]*v[0][1];
	if(res>0)
		return 1;//p3 is on the right of p1->p2
	else if(res<0)
		return -1;//p3 is on the right of p1->p2
	else return 0;//p3 is in the line of p1->p2
	}

float judge_ds(struct pstn p1,struct pstn p2,struct pstn p3)
{
	printf("\nfunc:judge_ds\n");
	return 0;
}

int g_road_p2p_link(int mode, struct pstn p1,struct pstn p2, struct g_map*map)
{
//	printf("\nfunc:g_road_p2p_link\n");
	struct pstn vdir;
	struct pstn pnt;
	pnt.x=p1.x;
	pnt.y=p1.y;
	vdir.x=p2.x-p1.x;
	vdir.y=p2.y-p1.y;
	int addnum=0;
	float addf,pf;
	int adx,ady;
	
	*(map->map+pnt.x+pnt.y*map->ly)=0;
	
	switch(mode)
	{
		case 1://right example=(pnt.x=p2.x,pnt.y=p1.y)
		addnum=judge_sign(vdir.x);
		while(pnt.x!=p2.x)
		{
			pnt.x+=addnum;
			*(map->map+pnt.x+pnt.y*map->ly)=0;
		}
		addnum=judge_sign(vdir.y);
		while(pnt.y!=p2.y)
		{
			pnt.y+=addnum;
			*(map->map+pnt.x+pnt.y*map->ly)=0;
		}
		break;
		
		
		case -1://left example=(pnt.x=p1.x,pnt.y=p2.y)
		addnum=judge_sign(vdir.y);
		while(pnt.y!=p2.y)
		{
			pnt.y+=addnum;
			*(map->map+pnt.x+pnt.y*map->ly)=0;
		}
		addnum=judge_sign(vdir.x);
		while(pnt.x!=p2.x)
		{
			pnt.x+=addnum;
			*(map->map+pnt.x+pnt.y*map->ly)=0;
		}
		break;
		
		
		case 0://directly go to the end
		if(vdir.y!=0)
		{
		addf=1.0*abs(vdir.x)/abs(vdir.y);
		adx=judge_sign(vdir.x);
		ady=judge_sign(vdir.y);
		}
		else {
		adx=judge_sign(vdir.x);
		ady=judge_sign(vdir.y);
		addf=10000;
		}
		
		
		if(addf>=1){
//			printf("x>y[addf]%.4f\n",addf);
			pf=pnt.y;
			while(pnt.x!=p2.x)
			{
				pnt.x+=adx;
				pf+=1.0*ady/addf;
				pnt.y=(int)pf;
				*(map->map+pnt.x+pnt.y*map->ly)=0;
//			printf("whilestep[%d][%d][pf]%.4f\n",pnt.x,pnt.y,pf);
				if(abs(pf-pnt.y)>=1)
				{
					pnt.y+=ady;
					*(map->map+pnt.x+pnt.y*map->ly)=0;
//			printf("DOES IT GO RIGHTX???\n");		
				}
			}
		}
		else{
//			printf("x>y[addf]%.4f\n",addf);
			pf=pnt.x;
			while(pnt.y!=p2.y)
			{
				pnt.y+=ady;
				pf+=1.0*adx*addf;
				pnt.x=(int)pf;
				*(map->map+pnt.x+pnt.y*map->ly)=0;
//			printf("whilestep[%d][%d][pf]%.4f\n",pnt.x,pnt.y,pf);
				if(abs(pf-pnt.x)>=1)
				{
				pnt.x+=adx;
				*(map->map+pnt.x+pnt.y*map->ly)=0;
//			printf("DOES IT GO RIGHTY???\n");	
				}
			}
		}
		break;
		default://
		
		break;
		
	}
	return 0;
}

int g_road_link(int mode,struct g_road*road,struct g_map *map)
{
//	printf("\nfunc:g_road_link\n");

	int i=0;
	for(i=1;i<road->length;i++)
	{
//		printf("stepinto:[%4d][%4d]=>[%4d][%4d]\n",(road->pst+i-1)->x,(road->pst+i-1)->y,(road->pst+i)->x,(road->pst+i)->y);
		g_road_p2p_link(mode,*(road->pst+i-1),*(road->pst+i),map);
	}
	
	return 0;
}


int g_road_init(struct g_road* road,int len,struct g_map*map)
{
//	printf("\nfunc:g_road_init\n");
	g_srand();
	free(road);
	road=(struct g_road*)calloc(1,sizeof(struct g_road));
	road->length=5+rand()%6;
	road->pst=(struct pstn*)calloc(len,sizeof(struct pstn));
	struct pstn* pstnp=road->pst;
	pstnp->x=map->in.x;
	pstnp->y=map->in.y;
	
	
	for(int i=0;i<road->length-2;i++)
	{
	pstnp++;
	pstnp->x=1+rand()%(map->lx-2);
	pstnp->y=1+rand()%(map->ly-2);
	}
	pstnp++;
	pstnp->x=map->out.x;
	pstnp->y=map->out.y;
	
	
	return 0;
}

int g_addw(struct g_map*map, struct g_road*road)
{
	printf("\nfunc:g_addw\n");
	
	return 0;
}

int g_map_reset(struct g_map* map)
{
//	printf("\nfunc:g_map_reset\n");
	int i=0;
	int j=0;
	for(i=1;i<map->ly-1;i++)
	for(j=1;j<map->lx-1;j++)
	*(map->map+i+j*map->ly)=31;
	return 0;
}

int g_map_init(struct g_map* map,int length)
{
//	printf("\nfunc:g_map_init\n");
	int i=0;
	int j=0;
//	map=(struct g_map*)calloc(1,sizeof(struct g_map));
	map->lx=length&0xFFFF;
	map->ly=(length&0xFFFF0000)>>16;
	map->map=(char*)calloc(map->lx*map->ly,1);
//	printf("%d %d\n\n",map->lx,map->ly);
	map->in.x=1;
	map->in.y=1;
	map->out.x=map->lx-2;
	map->out.y=map->ly-2;
	g_map_reset(map);

	for(i=0;i<map->lx;i++)
		*(map->map+i)=33;
	for(i=map->lx*(map->ly-1);i<map->lx*map->ly;i++)
		*(map->map+i)=33;
	for(i=0;i<map->lx*map->ly;i+=map->ly)
		*(map->map+i)=33;
	for(i=map->lx-1;i<map->lx*map->ly;i+=map->ly)
		*(map->map+i)=33;
	
	
	return 0;
}



int g_stack()
{
	printf("\nfunc:g_stack\n");
	return 0;
}

int snf_map(char *p,int len,int Len)
{
	int i=0,j=0;
	int tag=0;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(*(p+j+i*Len)==0)
			{
				tag+= (1<<(j+i*len));
			}
		}
	}
	
	
	return tag;
}

int g_map_link_enhance(int mode,struct g_map*map)
{
//	printf("\nfunc:g_map_link_enhance\n");
	
	
	int snf;
	char*pe;
	int i=0,j=0;
	
	switch(mode)
	{
		case 0:
	

		for(j=1;j<map->ly-2;j++){
			pe=map->map+map->lx*j+1;
			for(i=1;i<map->lx-2;i++)
			{
			snf=snf_map(pe,2,map->lx);
//			printf("[%d%c]",snf,*pe);
			if(snf==9||snf==6)
			*pe=*(pe+1)=0;
			pe++;
			}
//		putchar('\n');
		}
		break;
		case 1:
		break;
		default:
		break;
	}
	return 0;
}



int g_go()
{
	printf("\nfunc:g_go\n");
	return 0;
}


int map_prt(struct g_map*map)
{
	int i=0;
	int j=0;
	
	Sleep(500);
	system("cls");
for(j=0;j<map->ly;j++)	
{
	for(i=0;i<map->lx;i++)
	{
		char o=*(map->map+j*map->ly+i);
		switch(o)
		{
			case 0:
				putchar(' ');//空白
				break;
			case 1:
				putchar('@');//初始化后未赋值
				break;
			case 33:
				putchar('$');//边界
				break;
				
			case 31:
				putchar('H');//障碍
				break;
				
			case 96:
				putchar('X');//角色
				break;
				
			default:
			break;
		};
			putchar(' ');

	}
	putchar('\n');
	
}
printf("\n======================================");

}

int main()
{
	int mode=1;
	int length=30;
	length=length<<16;
	length+=30;
	struct g_map *map;
	map=(struct g_map*)calloc(1,sizeof(struct g_map));
	g_map_init(map,length);
	
	struct g_road*road;
	g_road_init(road,0,map);
	
printf("\nfunc:main\n");
/*	
	g_map_reset(map);
	g_road_link(1,road,map);
	map_prt(map);
	
	g_map_reset(map);
	g_road_link(-1,road,map);
	map_prt(map);
*/
	for(int i=0;i<100;i++){

g_road_link(0,road,map);
map_prt(map);
g_map_link_enhance(0,map);
	map_prt(map);
	if(rand()%5==0)
		g_map_reset(map);
g_road_init(road,0,map);
	}
	getchar();
	return 0;
}