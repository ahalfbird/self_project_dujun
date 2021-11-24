
import java.awt.AWTException;
import java.awt.Color;
import java.awt.MouseInfo;
import java.awt.Robot;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;
import javax.swing.JOptionPane;

public class at {
	
	
	
	public static void main(String[] args) throws AWTException {
		Robot r = new Robot();
		Util R = new Util();
		int[] rgb = new int[3];
		int[] point=new int [2];
		BufferedImage sample = null;
		


		
		//??????????????
		
		int[][] rect={{320,185},{1545,185},{320,930},{1545,930}};
		//?????????
		//???????????????????
		//??????????????windows????????????????????????  ??  ??  ??  

		int[]  point1={323,188};								
		//????????
		//??????

		File file = new File("D:\\img\\a.bmp");
		//????
		

		int potw=6;												
		//?????
		//????????????????

		double simnum=0.05;									
		//????????
		//?????????????????????????
	
//??????



		
		int width;
		int height;
		
		
		int res = JOptionPane.showConfirmDialog(null, "?????????????", "????", JOptionPane.YES_NO_OPTION);
		if (res == JOptionPane.YES_OPTION) {
		} else {
			System.exit(0);
			return;
		}
		
		
		System.out.println("??????......");

		try {

			sample = ImageIO.read(file);
			
		} catch (Exception e) {

			e.printStackTrace();
			System.out.println("???????");
		}
		
		
		width = sample.getWidth();
		height = sample.getHeight();
		System.out.println("????????"+width+"?"+height);
		int pixel;
		
		/*
		int rgbR;
		int rgbG;
		int rgbB;
		for (int i = 0; i < width; i+=6) { 
			for (int j = 0; j < height; j+=6) { 
			pixel = sample.getRGB(i, j); // ??????????????RGB?? 
			rgbR = (pixel & 0xff0000) >> 16; 
			rgbG = (pixel & 0xff00) >> 8; 
			rgbB = (pixel & 0xff); 
			Color imgc=new Color(rgbR,rgbG,rgbB);
			} 
			} 
		*/
		

		
		
		
	
		int rgbR;
		int rgbG;
		int rgbB;
		int tmppx;
		int tmppy;
		Color tmppc=new Color(0,0,0);
		int tmppi;
		int tmppj;
		int rop=0;	
			
		
		int startx=938-width/2;
		int starty=563-height/2;
		int endx=930+width/2;
		int endy=555+height/2;
		
		
		for(tmppj=potw/2,point1[0]=starty;point1[0]<endy&&tmppj<height-potw/2;point1[0]+=potw,tmppj+=potw)
		{
			if(R.check(50, 1000, 255, 255, 255, r)==true) {
				
				r.delay(10000);
			}
			
			
			for(tmppi=potw/2,point1[1]=startx;point1[1]<endx&&tmppi<width-potw/2;point1[1]+=potw,tmppi+=potw)
			{
				
				
				pixel = sample.getRGB(tmppi,tmppj);
				rgbR = (pixel & 0xff0000) >> 16; 
				rgbG = (pixel & 0xff00) >> 8; 
				rgbB = (pixel & 0xff); 
				if(R.isNearColor(tmppc,pixel,simnum))
				{
					
					if(rop==0)
					{
						
						R.getColorFromCircle(tmppc,r);
						R.moveMouse(point1[1]+potw, point1[0],r);
						r.mousePress(InputEvent.BUTTON1_MASK);
						rop=1;
						r.delay(100);
					}
					else {
						
						R.moveMouse(point1[1]+potw, point1[0],r);
						r.delay(100);
						
					}
					
				}
				else {
					
					r.delay(100);
					
					tmppc=new Color(rgbR,rgbG,rgbB);
					
					if(rop==1) {
					rop=0;
					R.moveMouse(point1[1]+potw, point1[0],r);
					r.mouseRelease(InputEvent.BUTTON1_MASK);
					r.delay(200);
					
					}
					
					R.getColorFromCircle(tmppc,r);
					R.moveMouse(point1[1], point1[0],r);
					r.mousePress(InputEvent.BUTTON1_MASK);
					rop=1;
					r.delay(100);
					
				}

				
			}
			
			if(rop==1) {
			rop=0;
			r.mouseRelease(InputEvent.BUTTON1_MASK);
			r.delay(100);
			
			}
				if(tmppj%80==potw/2)
				r.delay(5000);
		
		}
				
				
		
//		Color[][] tcolor={{new Color(13,209,69),new Color(196,255,13),new Color(141,243,218),new Color(0,168,243),new Color(61,71,204)},
//						{new Color(132,112,223),new Color(184,61,185),new Color(155,173,199),new Color(253,73,150),new Color(235,28,34)},
//						{new Color(135,0,28),new Color(184,121,85),new Color(255,126,38),new Color(255,201,22),new Color(255,241,0)},
//						{new Color(252,235,166),new Color(0,0,0),new Color(86,86,86),new Color(195,195,195),new Color(255,255,255)}};



//			int tmppx;
//			int tmppy;
//			Color tmppc=new Color(10,10,10);
//			int tmppi;
//			int tmppj;
//			int rop=0;
//			
//			//tmppc=r.getPixelColor(200, 205);
//			
////		for(tmppj=3,point1[0]=188;point1[0]<930&&tmppj<745;point1[0]+=6,tmppj+=6)
//			for(tmppj=3,point1[0]=210;point1[0]<930&&tmppj<700;point1[0]+=6,tmppj+=6)
//		{
//			
//			tmppi=3;
//			point1[1]=323;
//			r.delay(200);
//			for(tmppi=3,point1[1]=323;point1[1]<1545&&tmppi<1000;point1[1]+=10,tmppi+=10)
//		{
//				r.delay(20);
//			pixel = sample.getRGB(tmppi,tmppj); 
//			if(R.isNearColor(tmppc,pixel,0.2))
//		{
//				
//				moveMouse(point1[1], point1[0],r);
//				System.out.printf("%d  %d  \n",point1[1],point1[0]);
//				
//				if(rop==0)
//				{r.mousePress(InputEvent.BUTTON1_MASK);
//				
//				rop=1;
//				r.delay(20);
//				}
//				
//		}
//			else {
//				r.mouseRelease(InputEvent.BUTTON1_MASK);
//				rop=0;
//				r.delay(20);
//			}
//				
//		}
//		if(rop==1)
//			{	r.mouseRelease(InputEvent.BUTTON1_MASK);
//				rop=0;
//				r.delay(20);
//			}
//		
//		}
			
		
		
		r.delay(8000);
		R.moveMouse(1707, 853, r);
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
			
		}
		
	

	
}



		

    
		
	


class Util{
	
	public static int pointx=0;
	public static  int pointy=0;
	public static  int cirx=608;
	public  static int ciry=443;
	public static  int barx=297;
	public static  int bary=710;
	public static  int bendx=910;
	public  static int bendy=710;


	
	public static void moveMouse(int x , int y , Robot r) {
		int maxTimes = 5;
		for(int count = 0;
				MouseInfo.getPointerInfo().getLocation().getX()!=x
						||MouseInfo.getPointerInfo().getLocation().getY()!=y
						&& count < maxTimes;
				count++) {
			r.mouseMove(x, y);
		}
	}	
	
	

	public static boolean check(int x, int y , int red , int green , int blue , Robot r) {
		Color color = null;
		color = r.getPixelColor(x, y);
		//System.out.println(color.getRed()+","+color.getGreen()+","+color.getBlue());
		if(color.getRed()==red && color.getGreen()==green && color.getBlue()==blue) {
			return true;
		}
		return false;
		
	}
	

	


	public static boolean isNearColor(Color color1,int pixel,double issue)
	{
		int rgb1[]=new int[3];
		int rgb2[]=new int[3];
		rgb1[0]=color1.getRed();
		rgb1[1]=color1.getGreen();
		rgb1[2]=color1.getBlue();
		rgb2[0]=(pixel & 0xff0000) >> 16; 
		rgb2[1]=(pixel & 0xff00) >> 8; 
		rgb2[2]=(pixel & 0xff);

		double sum=0;
		double det[]=new double[3];
		for(int i=0;i<3;i++)
		{
			det[i]=((double)rgb2[i]-(double)rgb1[i])/255;
			det[i]=det[i]*det[i];
			sum+=det[i];
		}
		sum=Math.sqrt(sum);
		
		if(sum>issue)
		return false;	
		return 	true;
	}
			
				

	public static void getColorFromGame(int turn,Robot r) throws AWTException
	{
		
		moveMouse(190,210,r);
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
		

		int x=360;//870
		int y=270;//610
		x=360+(turn%5)*138;
		y=270+(int)(turn/5)*113;
		r.delay(200);
		moveMouse(x,y,r);	
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
		
		r.delay(200);
		


		System.out.println("?????"+turn+"?????");

		return ;
	}

	
	
	public static void getColorFromCircle(Color color,Robot r)throws AWTException
	{
		
		Mathutil mu=new Mathutil();
		int pos[][]={{800,433},{512,277},{512,609}};

		int rgb[]= {color.getRed(),color.getGreen(),color.getBlue()};
		int maxcolor;
		int maxnum;
		
		
		if(rgb[0]==0)
			rgb[0]++;
		if(rgb[1]==0)
			rgb[1]++;
		if(rgb[2]==0)
			rgb[2]++;
		
int[] c1= {rgb[0],rgb[1],rgb[2]};
		int[] c2= {0,1,2};		
		
for(int i=1;i<3;i++)
	if(c1[i]>=c1[0])
	{c1[0]+=c1[i];
	c1[i]=c1[0]-c1[i];
	c1[0]=c1[0]-c1[i];
	c2[0]+=c2[i];
	c2[i]=c2[0]-c2[i];
	c2[0]=c2[0]-c2[i];}
	
for(int i=2;i<3;i++)
	if(c1[i]>=c1[1])
	{c1[1]+=c1[i];
	c1[i]=c1[1]-c1[i];
	c1[1]=c1[1]-c1[i];
	c2[1]+=c2[i];
	c2[i]=c2[1]-c2[i];
	c2[1]=c2[1]-c2[i];
	}
//System.out.printf("rgb:%d   %d   %d\n",rgb[0],rgb[1],rgb[2]);		
//System.out.printf("c1:%d   %d   %d\n",c1[0],c1[1],c1[2]);
//System.out.printf("c2:%d   %d   %d\n",c2[0],c2[1],c2[2]);


			double r1,r2,tmpnnn;
		
		tmpnnn=(1-(double)c1[0]/256);
		r1=tmpnnn*193;
	//	System.out.print(r1);
		r2=2/3*Math.PI*((double)c1[1]/(c1[1]+c1[2])-0.5);
	//	System.out.print(r2);
		r2=Math.cos(r2);
	//	System.out.print(r2);
		r2=(tmpnnn*tmpnnn+1-2*r2*tmpnnn)*193*193;
	//	System.out.print(r2);
		r1=r1*r1;
		
			
			
			
			double x[]= {0,0,0,0,0};

			
		x=mu._X2Y2(608, 443,r1 , pos[c2[0]][0],pos[c2[0]][1],r2);
		
//		System.out.printf("\nx:%f   %f   %f   %f   %f \n",x[0],x[1],x[2],x[3],x[4]);
		
		
		if(x[0]==-1)
		{
			System.out.printf("%d  %d  %d  %f  %f\n",c1[0],c1[1],c1[2],r1,r2);
			System.out.println("??????");
			return;
		}
		
		if(x[0]==0)
		{
			System.out.println("?????");
			return;
		}
		
		
		double sum1=Math.abs(x[1]-pos[c2[1]][0])+Math.abs(x[2]-pos[c2[1]][1]);
		double sum2=Math.abs(x[3]-pos[c2[1]][0])+Math.abs(x[4]-pos[c2[1]][1]);
		
		
		int colorx=608;
		int colory=443;
		
		
		if(sum1<=sum2)
		{colorx=(int)x[1];
		colory=(int)x[2];
			}
		else {
			colorx=(int)x[3];
			colory=(int)x[4];
		}
			
//		System.out.printf("colorxy:%d  %d\n",colorx,colory);
		
//		public int pointx=0;
//		public int pointy=0;
//		public int cirx=608;
//		public int ciry=444;
//		public int barx=297;
//		public int bary=710;
//		public int bendx=910;
//		public int bendy=710;
		
		moveMouse(200, 320,r);
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
		r.delay(200);
		
//??
		
		pointx=bendx-610*c1[0]/255;
		moveMouse(pointx, 710,r);
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
		
		
//??
		
		
		r.delay(200);
	    moveMouse(colorx, colory,r);
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
		
//		Color cr=r.getPixelColor(colorx, colory);
//		rgb[0]=cr.getRed();
//		rgb[1]=cr.getGreen();
//		rgb[2]=cr.getBlue();
//		System.out.printf("\n%d   %d   %d   %d   %d   %d\n",pointx,colorx,colory,rgb[0],rgb[1],rgb[2]);
		
		
		r.delay(200);
		moveMouse(200, 320,r);
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
		
		r.delay(200);
		return;
	}
	
	
	public static void prtpoint(int x,int y,Robot r) throws AWTException
	{
		r.delay(20);
		moveMouse(x,y,r);
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
		r.delay(20);
	}
	

}



class KeyThread extends Thread implements KeyListener{

	/**
	 * ??????????
	 */
	public void run() {
		
	}
	
	
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void keyPressed(KeyEvent e) {
		switch (e.getKeyCode()) {
		default:System.out.println("????");
		
		System.exit(0);
		this.interrupt();
		break;
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		switch (e.getKeyCode()) {
		default:System.out.println("????");
		
		System.exit(0);
		this.interrupt();
		break;
		}
	}
}




