package Yankfu;
import java.util.Scanner;
import java.text.DecimalFormat;

abstract class shape {// ������

    /* ���󷽷� ����� */
    public abstract double getArea();

    /* ���󷽷� ���ܳ� */
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
        DecimalFormat d = new DecimalFormat("#.####");// ����4λС��
        double side = input.nextDouble();

        shape rp = new RPentagon(side);

        System.out.println(d.format(rp.getArea()));
        System.out.println(d.format(rp.getPerimeter()));
        input.close();
    } 
}