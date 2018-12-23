package com.introduction_to_java_programming;
import java.util.*;
public class P74Chapter_2_21 
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.print("Enter investment amount:");
		double ia=input.nextDouble();
		System.out.print("Enter annual interest rate in percentage:");
		double mi=input.nextDouble();
		mi=1+(mi/100.0)/12.0;
		System.out.print("Enter number of years:");
		double nOy=input.nextDouble();
		mi=ia*mi;
		double i;
		i=Math.pow(mi,nOy);
		System.out.printf("Accumulated value is $%.2f", i);
	}
}
