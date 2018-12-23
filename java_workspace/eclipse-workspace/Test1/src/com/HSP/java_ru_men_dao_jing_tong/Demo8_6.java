package com.HSP.java_ru_men_dao_jing_tong;
import java.awt.*;
import javax.swing.*;
public class Demo8_6 extends JFrame{

	//定义组件
	JPanel jp1,jp2,jp3;
	JLabel jlb1,jlb2;
	JButton jb1,jb2;
	JTextField jtf1;
	JPasswordField jpf1;
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Demo8_6 demo8_6=new Demo8_6();
	}

	public Demo8_6()
	{
		jp1=new JPanel();
		jp2=new JPanel();
		jp3=new JPanel();
		
		jlb1=new JLabel("用户名");
		jlb2=new JLabel("密    码");
		jb1=new JButton("登陆");
		jb2=new JButton("取消");
		
		jtf1=new JTextField(10);
		jpf1=new JPasswordField(10);
		
		//设置布局管理
		this.setLayout(new GridLayout(3,1));
		
		jp1.add(jlb1);
		jp1.add(jtf1);
		
		jp2.add(jlb2);
		jp2.add(jpf1);
		
		jp3.add(jb1);
		jp3.add(jb2);
		
		//加入JFrame
		this.add(jp1);
		this.add(jp2);
		this.add(jp3);
		
		this.setTitle("666");
		this.setSize(300,150);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}
