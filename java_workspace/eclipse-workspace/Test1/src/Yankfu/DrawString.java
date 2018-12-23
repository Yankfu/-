package Yankfu;
import java.awt.*;

import javax.swing.*;
public class DrawString extends JFrame
{

	private Shape rect;
	private Font font;
	private Date date;
	public DrawString()
	{
		rect = new Rectangle2D.Double(10, 10, 200, 80);
		font = new Font("宋体",Font.BOLD,16);
		date = new Date();
		this.setSize(230,140);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.add(new CanvasPanel());
		this.setTitle("绘图文本");
	}
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		new DrawString().setVisible(true);
	}
	
	class CanvasPanel extends Canvas
	{
		public void paint(Graphics g)
		{
			super.paint(g);
			Graphics2D g2=(Graphics2D)g;
			g2.setColor(Color.CYAN);
			g2.fill(rect);
			g2.setColor(Color.BLUE);
			g2.setFont(font);
			g2.drawString("现在的时间是", 20, 30);
			g2.drawString(String.format("%tr", date), 50, 60);
		}
	}

}
