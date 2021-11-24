package Gtool;


import java.awt.AWTException;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.HeadlessException;
import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Transferable;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Random;

import javax.swing.JOptionPane;


public class Qpzdjdraw {
	
	
	public static void main(String[] args) throws AWTException, IOException, InterruptedException{
		Robot r = new Robot();
		Util R = new Util();
		
		int max = 1;
		
		//����ʼ
		
		int times=0;
		int res = JOptionPane.showConfirmDialog(null, "����������ͼ�����ȷ�ϼ���", "����ս����", JOptionPane.YES_NO_OPTION);

		if (res == JOptionPane.YES_OPTION) {

			

		} else {

			System.exit(0);

			return;

		}
		
		
		
	}
}

class ViewRect {
	int Pot[][]= new int[4][2];
	int midx,midy;
	int celllen;
	int gridnum;
	int width;
	int height;
	ViewRect() {
		for(int i=0;i<4;i++)
			Pot[i][0]=Pot[i][1]=0;
	}
	ViewRect(int[][] pot) {
		initRect(pot);
	}
	public int getwidth()
	{
		return Pot[1][0]-Pot[0][0];
	}
	public int getheight()
	{
		return Pot[2][1]-Pot[0][1];
	}
	public int setgridnum(int a)
	{
		gridnum=a;
		celllen=getwidth()/gridnum;
		return celllen;
	}
	public int initRect(int[][] pot)
	{
		//pot0 is lftp pointer,pot1 is rgbt pointer
		for(int i=0;i<4;i++)
		{
			Pot[i][0]=pot[i][0];
			Pot[i][1]=pot[i][1];
		}
		width=getwidth();
		height=getheight();
		midx=(pot[0][0]+pot[1][0])/2;
		midy=(pot[0][1]+pot[2][1])/2;
		return 0;
	}
	
}


class QpUtil{
	//�ƶ����
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
	/*
	 * �����Ļ
	 * @param x , y ����
	 * @param r ������ 
	 * �����ɺ�Ĭ�ϵȴ� 1������
	 */
	public static void press(int x, int y , Robot r) {
		int pressX = x ;
		int pressY = y ;
		moveMouse(pressX, pressY, r);
		r.mousePress(InputEvent.BUTTON1_MASK);
		r.mouseRelease(InputEvent.BUTTON1_MASK);
		r.delay(1000 + new Random().nextInt(1000));
	}
	
	/*
	 * ��� ����ɫ
	 * @param x,y ���������
	 * @param red green blue �����Ӧ���е�rgb
	 * @param robot��
	 * @return ��ͬ����true����ͬ����false
	 * 
	 * */
	public static boolean check(int x, int y , int red , int green , int blue , Robot r) {
		Color color = null;
		color = r.getPixelColor(x, y);
		System.out.println(color.getRed()+","+color.getGreen()+","+color.getBlue());
		if(color.getRed()==red && color.getGreen()==green && color.getBlue()==blue) {
			return true;
		}
		return false;
		
	}
	
	public static void delay() throws AWTException{
		new Robot().delay(1000);
	}
	


}





