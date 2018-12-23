package com.pintia_qimoceshiti._18_12_20;
import java.util.*;
public class _7_1_sanjiaoxingmianji 
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		double a1,a2,b1,b2,c1,c2;
		a1=in.nextDouble();
		a2=in.nextDouble();
		b1=in.nextDouble();
		b2=in.nextDouble();
		c1=in.nextDouble();
		c2=in.nextDouble();
		double side1,side2,side3,s,area;
		side1=Math.sqrt((b1-a1)*(b1-a1)+(b2-a2)*(b2-a2));
		side2=Math.sqrt((b1-c1)*(b1-c1)+(b2-c2)*(b2-c2));
		side3=Math.sqrt((c1-a1)*(c1-a1)+(c2-a2)*(c2-a2));
		s=(side1+side2+side3)/2;
		area=Math.sqrt(s*(s - side1)*(s - side2)*(s - side3));
		System.out.printf("The area of the triangle is %.2f.", area);
	}
}
