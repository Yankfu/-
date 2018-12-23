package com.pintia_qimoceshiti._18_12_21;
import java.util.*;
public class _7_1_liangzhixianjiaodian 
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		double x1;
		double x2;
		double x3;
		double x4;
		double y1;
		double y2;
		double y3;
		double y4;
		double k1;
		double k2;
		double b1;
		double b2;
		double x;
		double y;
		x1=in.nextDouble();
		y1=in.nextDouble();
		x2=in.nextDouble();
		y2=in.nextDouble();
		x3=in.nextDouble();
		y3=in.nextDouble();
		x4=in.nextDouble();
		y4=in.nextDouble();
		k1=(x1-x2)/(y1-y2);
		k2=(x3-x4)/(y3-y4);
		if(k1==k2)
		{
			System.out.print("The two lines are parallel");
		}
		else
		{
			b1=y2-k1*x2;
			b2=y3-k2*x3;
			x=(b2-b1)/(k1-k2);
			y=k2*x+b2;
			System.out.print("The intersecting point is at (");
			System.out.printf("%f", x);
			System.out.printf(",%f)", y);
		}
		
	}
}
