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


public class GOarknights {
	public static void main(String[] args) throws AWTException, IOException, InterruptedException{
		Robot r = new Robot();
		Util R = new Util();
		
		
		
		
		int lefttop_x=161;
		int lefttop_y=36;
		int rightdown_x=1832;
		int rightdown_y=976;
		
		
		int max = 1;
		
		int startact_x=1600;//白色开始行动 255255255
		int startact_y=900;
		int startfit_x=1550;//红色开始行动 255255255
		int startfit_y=700;
		int test1_x=620;//左下作战结束 255255255
		int test1_y=870;
		int test2_x=1520;//代理指挥左边白块 255255255
		int test2_y=810;
		
		
		int test3_x=1575;//添加体力清空选择黑框 494949
		int test3_y=585;
		int test4_x=1550;//添加体力对号圆框 494949
		int test4_y=810;
		
		
		//程序开始
		
		int times=0;
		int res = JOptionPane.showConfirmDialog(null, "即将开启作战，点击确认继续", "Arknights", JOptionPane.YES_NO_OPTION);

		if (res == JOptionPane.YES_OPTION) {

			

		} else {

			System.exit(0);

			return;

		}
		
		
		
		for(int i = 0 ; i < max; i++) {
			times=0;
		
		
			System.out.println("1");
			R.delay();
			
			while(R.check(test2_x, test2_y, 255, 255, 255, r)!=true) {
				
				System.out.println("2");
				R.delay();
				
			}
			
			System.out.println("进入作战界面");
			
			
			//点击开始行动进入编队界面
			R.press(startact_x, startact_y, r);
			

			
		/*	
			if(R.check(test3_x, test3_y, 49, 49, 49, r)==true)
				
				if(R.check(test4_x, test4_y, 49, 49, 49, r)==true)
				{
					R.delay();
					
					System.exit(0);
					
					//点击添加体力
					//R.press(test4_x,test4_y, r);
					
					
					
				
					
					if(R.netdelay(r)==false)
					{
						System.exit(0);
					}
					
					
					R.delay();
					//点击开始行动进入编队界面
					R.press(startact_x, startact_y, r);
					if(R.netdelay(r)==false)
					{
						System.exit(0);
					}
					
					
				}
			
			*/

			
			R.delay();
			R.delay();
			//点击开始行动
			R.press(startfit_x,startfit_y, r);
			
			
			
			
			for(int j=0;j<200;j++)
			{
				times++;
				R.delay();
			}
			
			/*通过特定坐标点的颜色来识别是否结束*/
			while(R.check(test1_x, test1_y, 255, 255, 255, r)!=true) {
				
				R.delay();
				times++;
				if(times>=1300)
					break;
			}
			
			System.out.println("作战结束");
			
			R.delay();
			R.delay();
			
			if(times>=1000) {
				//剿灭
				
				R.press(1529, 541, r);
				

			
			
			R.delay();
			R.delay();
			
			R.press(1529, 541, r);
			
			}
			
			
		
			R.delay();
			R.delay();
			
			
			R.press(1529, 541, r);
			
			

		}
		
	}
}

class Util{
	//移动鼠标
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
	 * 点击屏幕
	 * @param x , y 坐标
	 * @param r 机器人 
	 * 点击完成后默认等待 1秒左右
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
	 * 检查 点颜色
	 * @param x,y 检查点的坐标
	 * @param red green blue 这个点应该有的rgb
	 * @param robot类
	 * @return 相同返回true，不同返回false
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
	
	public static boolean netdelay(Robot r) throws AWTException {
		boolean netonline=false;
		int net1x=940;
		int net1y=890;
		int net2x=980;
		int net2y=890;
		Color color = null;
		int times=0;
		do {
		
			if(times>=20)
			{System.out.println("服务器未响应");
			return false;
			}
			new Robot().delay(1000);
			color = r.getPixelColor(net1x, net1y);
			if(color.getRed()>253 && color.getGreen()>253 && color.getBlue()>253) {
				color = r.getPixelColor(net2x, net2y);
				if(color.getRed()>253 && color.getGreen()>253 && color.getBlue()>253)
				{
					
					netonline=false;
					times++;
					System.out.println("等待服务器响应"+times+"秒");
					continue;
				}
			}
			else {
				netonline=true;
				break;
			}
			
		}while(netonline!=true);
		
		return true;
	}

}





