/**
 * ���ܣ�gui���濪����ʾ
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
	
	//���캯��
	public Demo6()
	{

		//����һ��button��ť
		jb1=new JButton("���ǰ�ť");
		//���������ñ���
		this.setTitle("Hello,world!");
		//���ô�С��������
		this.setSize(200, 200);
		//���JButton���
		this.add(jb1);
		//���ó�ʼλ��(�������ң����ϵ���)
		this.setLocation(100, 200);
		//���õ��رմ���ʱ����֤jvmҲ�˳���
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//��ʾ
		this.setVisible(true);
	}
}
