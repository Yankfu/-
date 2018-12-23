/**讲解java绘图原理
 * 
 */
package com.tankedazhan;
import javax.swing.*;
import java.awt.*;
import java.awt.image.ImageObserver;
import java.net.URL;
public class Demo9_1 extends JFrame
{
	MyPanel mp=null;
	//初始化
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Demo9_1 demo9_1=new Demo9_1();
	}
	
	public Demo9_1()
	{
		mp=new MyPanel();
		this.add(mp);
		this.setSize(400,300);
		this.setLocation(200,200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}

//定义一个自己的面板，用于绘图和显示的一个区域
@SuppressWarnings("serial")
class MyPanel extends JPanel
{

	//覆盖JPanel的paint方法
	public void paint(Graphics g)//Graphics是绘图的重要类，可以理解为一直画笔
	{
		//调用父类函数，完成初始化
		super.paint(g);//绝对不能少
		System.out.print("paint被调用\n");
		//可以开始画图
		//开始画圆了。
		//g.drawOval(10,10,30,30);
		//划直线,起点坐标和终点坐标
		//g.drawLine(10, 10, 250, 250);
		//画出矩形边框
//		g.drawRect(10, 10, 50, 60);
//		g.setColor(Color.blue);
//		g.fillRect(100, 100, 50, 60);
		//在面板上画出图片
		Image im=
				Toolkit.getDefaultToolkit().getImage(
						Panel.class.getResource("\TIM图片20181218210514.jpg"));
		//显示
		g.drawImage(im, 90, 90, 160, 108,this);

	}
}