package com.introduction_to_java_programming;

public class P30Chapter_1_13 
{
	public static void main(String[] args)
	{
		double a,b,c,d,e,f;
		a=3.4;
		b=50.2;
		c=2.1;
		d=5.5;
		e=44.5;
		f=5.9;
		double x=(e*d-b*f)/(a*d-b*c);
		double y=(a*f-e*c)/(a*d-b*c);
		System.out.printf("%.2f %.2f",x,y);
	}
}
