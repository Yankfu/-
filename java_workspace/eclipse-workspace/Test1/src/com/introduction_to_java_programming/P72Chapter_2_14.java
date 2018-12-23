package com.introduction_to_java_programming;
import java.util.*;
public class P72Chapter_2_14 
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		System.out.print("Enter weight in pounds:");
		double pounds=in.nextDouble();
		pounds=pounds*0.45359237;
		System.out.print("Enter height in inches:");
		double inches=in.nextDouble();
		inches=inches*0.0254;
		double BMI=pounds/(inches*inches);
		System.out.printf("BME is %.4f",BMI);
	}
}
