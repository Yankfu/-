package Yankfu;
import java.awt.*;
import javax.swing.*;
public class apple {
    public static void main(String[] args)
    {
        DrawPanel panel=new DrawPanel();
        JFrame application =new JFrame();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        application.add(panel);
        application.setSize(250, 250);
        application.setVisible(true);
    }
}
class DrawPanel extends JPanel {
public void paintComponent(Graphics g) {
     super.paintComponent(g);

     g.setColor(Color.LIGHT_GRAY);
     g.fillRect(0, 0, 250, 250);
     g.setColor(Color.red);
     g.fillOval(40, 50, 90, 132);
     g.fillOval(90, 50, 90, 132);
     g.setColor(Color.red);
     g.fillOval(90,145, 30, 30);
     g.fillOval(90,60, 30, 30);
     g.fillOval(35,49, 80, 100);
     g.fillOval(105,49, 80, 100);
//     g.setColor(Color.BLUE);
     g.fillArc(37,75, 48, 80, 120, 180);
     g.fillArc(134,75, 48, 80, 180,240 );
     g.setColor(Color.GREEN);
     g.fillArc(108,12, 48, 48, 90, 120);
     g.fillArc(88, 0, 48, 48, 270, 120);
    }

}