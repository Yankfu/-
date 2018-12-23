/**
 * 网格布局
 */
package Yankfu;
import java.awt.*;
import javax.swing.*;
public class Demo8_4 extends JFrame{
	
	//
	int size=9;
	JButton jbs[]=new JButton[size];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Demo8_4 demo8_4=new Demo8_4();
	}
	
	public Demo8_4()
	{
		for(int i=0;i<size;i++)
		{
			jbs[i]=new JButton(String.valueOf(i));
		}
		
		//设置网络布局
		this.setLayout(new GridLayout(3,3,10,10));
		
		//添加组件
		for(int i=0;i<size;i++)
		{
			this.add(jbs[i]);
		}
		
		//设置窗体属性
		this.setTitle("网格布局");
		this.setSize(300, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLocation(200, 200);
		//显示窗口
		this.setVisible(true);
	}
}
