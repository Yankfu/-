package Yankfu;
import java.util.Scanner;
import java.text.DecimalFormat;

abstract class shape {// 抽象类

    /* 抽象方法 求面积 */
    public abstract double getArea();

    /* 抽象方法 求周长 */
    public abstract double getPerimeter();
}
class RPentagon extends shape
{

	double a;
	public RPentagon(double side) {
		// TODO Auto-generated constructor stub
		this.a=side;
	}

	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		return (5*a*a*Math.tan(Math.toRadians(54)))/4;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 5*a;
	}
	
}

public class pintia_6_3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        DecimalFormat d = new DecimalFormat("#.####");// 保留4位小数
        double side = input.nextDouble();

        shape rp = new RPentagon(side);

        System.out.println(d.format(rp.getArea()));
        System.out.println(d.format(rp.getPerimeter()));
        input.close();
    } 
}