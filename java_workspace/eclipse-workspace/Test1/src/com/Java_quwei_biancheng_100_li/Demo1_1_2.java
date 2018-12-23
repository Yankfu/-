package com.Java_quwei_biancheng_100_li;
import java.util.Scanner;
public class Demo1_1_2 
{
	public static void main(String[] args)
	{
		@SuppressWarnings("resource")
		Scanner input=new Scanner(System.in);
		int n=input.nextInt();
		for(int j=n-1;j>=0;j--)
			System.out.print(" ");
		System.out.println("*");
		for(int i=1;i<n-1;i++)
		{
			for(int k=1;k<=n-i;k++)
				System.out.print(" ");
			System.out.print("*");
			for(int k=1;k<=2*i-1;k++)
				System.out.printf(" ");
			System.out.println("*");
		}
		System.out.print(" ");
		for(int m=2*n-1;m>0;m--)
			System.out.print("*");
	}
}
