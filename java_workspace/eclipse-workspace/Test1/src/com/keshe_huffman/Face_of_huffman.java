package com.keshe_huffman;
import java.awt.*;
import javax.swing.*;
public class Face_of_huffman extends JFrame{

	JPanel jp1,jp2,jp3;
	JLabel jlb1,jlb2,jlb3,jlb4;
	JButton jb1,jb2;
	JTextField jtf1,jtf2;
	JPasswordField jpf1,jpf2;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Face_of_huffman face=new Face_of_huffman();
	}
	
	public Face_of_huffman()
	{
		jp1=new JPanel();
		jp2=new JPanel();
		jp3=new JPanel();
		
		jlb1=new JLabel("请输入要编码的内容：");
		jlb2=new JLabel("编译完成的哈夫曼码：");
		jlb3=new JLabel("请输入要翻译的内容：");
		jlb4=new JLabel("翻译后的内容：");
		jb1=new JButton("编码");
		jb2=new JButton("译码");
		
		jtf1=new JTextField(10);
		jpf1=new JPasswordField(10);
		jtf2=new JTextField(10);
		jpf2=new JPasswordField(10);
	
		this.setLayout(new GridLayout(3,1));
		
		jp1.add(jlb1);
		jp1.add(jtf1);
		
		jp2.add(jlb2);
		jp2.add(jpf1);
		
		jp1.add(jlb3);
		jp1.add(jtf2);
		
		jp2.add(jlb4);
		jp2.add(jpf2);
		
		jp3.add(jb1);
		jp3.add(jb2);
		
		//加入JFrame
		this.add(jp1);
		this.add(jp2);
		this.add(jp3);
		
		this.setTitle("Huffman");
		this.setSize(600,300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}

