package com.introduction_to_java_programming;
import java.util.*;
public class P74Chapter_2_21_1 
{
	public static void main(String[] args) {
		double investmentAmount =0.0;
		double yearlyInterestRate =0.0;
		double monthlyInterest =0.0;
		int years = 0;
		double futureInvestmentValue =0.0;
		double temp = 0.0;
		Scanner input=new Scanner(System.in);
		System.out.println("Enter investment amount:" );
		investmentAmount =input.nextDouble();
		System.out.println("Enter annualinterest rate : " );
		yearlyInterestRate =input.nextDouble();
		System.out.println("Enter years: ");
		years =input.nextInt();
		yearlyInterestRate /=100.0;
		monthlyInterest = yearlyInterestRate/ 12.0;
		years *= 12;
		temp = investmentAmount * (1 +monthlyInterest);
		futureInvestmentValue =Math.pow(temp, years);
		System.out.println("Answer = "+String.valueOf(futureInvestmentValue));
		}
}
