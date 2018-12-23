/**
 * 功能：gui界面开发演示
 * 
 */
package Yankfu;

import java.awt.*;
import javax.swing.*;
public class Demo6 extends JFrame{

	JButton jb1=null;
	public static void main(String[] args) 
	{
		Demo6 demo6=new Demo6();
		
	}
	
	//构造函数
	public Demo6()
	{

		//创建一个button按钮
		jb1=new JButton("我是按钮");
		//给窗体设置标题
		this.setTitle("Hello,world!");
		//设置大小，按像素
		this.setSize(200, 200);
		//添加JButton组件
		this.add(jb1);
		//设置初始位置(从左向右，从上到下)
		this.setLocation(100, 200);
		//设置当关闭窗口时，保证jvm也退出。
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//显示
		this.setVisible(true);
	}
}
