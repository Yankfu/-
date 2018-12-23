package com.introduction_to_java_programming;
import java.util.*;
public class P73Chapter_2_17 
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.print("Enter the temperature in Fahrenheit between -58F and 41F:");
		double ta=input.nextDouble();
		System.out.print("Enter the wind speed(>=2) in miles per hour:");
		double v=input.nextDouble();
		double va=Math.pow(v, 0.16);
		double twc;
		twc=35.74+0.6215*ta-35.75*va+0.4275*ta*va;
		System.out.printf("The wind chill index is %.5f",twc);
	}
}
