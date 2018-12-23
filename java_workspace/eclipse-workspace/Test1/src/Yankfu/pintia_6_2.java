package Yankfu;

import java.util.Scanner;
import java.text.DecimalFormat;

abstract class shape {// ������
     /* ���󷽷� ����� */
    public abstract double getArea( );

    /* ���󷽷� ���ܳ� */
    public abstract double getPerimeter( );
}
class RegularPolygon extends shape
{

	int n;
	double side;
	public RegularPolygon(int n, double side) {
		// TODO Auto-generated constructor stub
		this.n=n;
		this.side=side;
	}

	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		return n*side*side/(Math.tan((Math.toRadians(180)/n))*4);
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return n*side;
	}
	
}
public class pintia_6_2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        DecimalFormat d = new DecimalFormat("#.####");// ����4λС��
        int n=input.nextInt();
        double side = input.nextDouble();

        shape rp = new  RegularPolygon(n,side);

        System.out.println(d.format(rp.getArea()));
        System.out.println(d.format(rp.getPerimeter()));
        input.close();
    }
}