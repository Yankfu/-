package com.introduction_to_java_programming;
import java.util.*;
public class P30Chapter_1_11 
{
	public static void main(String[] args)
	{
		double initPopolation;
		Scanner input=new Scanner(System.in);
		System.out.print("Please input the init population:");
		initPopolation=input.nextDouble();
		long theSecondOfYear=365*3600*24;
		double incrementOfYear=theSecondOfYear*(1/7.0-1/13.0+1/45.0);
		for(int i=1;i<=5;i++)
		{
			System.out.printf("The %d year population is: %10.2f\n",i,(initPopolation+i*incrementOfYear));
		}
	}
}
