package com.introduction_to_java_programming;

public class P30Chapter_1_7 
{
	public static void main(String[] args)
	{
		double pai;
		double res=0;
		double j;
		double k=-1;
		for(double i=1;i<=11;i+=2)
		{
			k=k*-1;
			j=k*1/i;
			res+=j;
			System.out.println(j+" "+k);
		}
		System.out.println(4*res);
	}
}
