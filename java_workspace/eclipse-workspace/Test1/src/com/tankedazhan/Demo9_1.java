/**����java��ͼԭ��
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
	//��ʼ��
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

//����һ���Լ�����壬���ڻ�ͼ����ʾ��һ������
@SuppressWarnings("serial")
class MyPanel extends JPanel
{

	//����JPanel��paint����
	public void paint(Graphics g)//Graphics�ǻ�ͼ����Ҫ�࣬�������Ϊһֱ����
	{
		//���ø��ຯ������ɳ�ʼ��
		super.paint(g);//���Բ�����
		System.out.print("paint������\n");
		//���Կ�ʼ��ͼ
		//��ʼ��Բ�ˡ�
		//g.drawOval(10,10,30,30);
		//��ֱ��,���������յ�����
		//g.drawLine(10, 10, 250, 250);
		//�������α߿�
//		g.drawRect(10, 10, 50, 60);
//		g.setColor(Color.blue);
//		g.fillRect(100, 100, 50, 60);
		//������ϻ���ͼƬ
		Image im=
				Toolkit.getDefaultToolkit().getImage(
						Panel.class.getResource("\TIMͼƬ20181218210514.jpg"));
		//��ʾ
		g.drawImage(im, 90, 90, 160, 108,this);

	}
}