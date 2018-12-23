package Yankfu;
import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;
public class Test3 extends JFrame{

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		new Test3().setVisible(true);
	}
	
	public Test3()
	{
		super();
		initialize();
	}
	
	public void initialize()
	{
		this.setSize(300, 300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.add(new CanvasPael());
		this.setTitle("»æÍ¼ÊµÑé2");
	}
	
	class CanvasPael extends JPanel
	{
		public void paint(Graphics g)
		{
			super.paint(g);
			Graphics2D g2=(Graphics2D)g;
			Shape[] shapes=new Shape[4];
			shapes[0]=new Ellipse2D.Double(5,5,100,100);
			shapes[1]=new Rectangle2D.Double(110, 5, 100, 100);
			shapes[2]=new Rectangle2D.Double(15, 15, 80, 80);
			shapes[3]=new Ellipse2D.Double(120, 15, 80, 80);
			for(Shape shape:shapes)
			{
				Rectangle2D bounds=shape.getBounds2D();
				if(bounds.getWidth()==80)
					g2.fill(shape);
				else
					g2.draw(shape);
			}
		}
	}

}
