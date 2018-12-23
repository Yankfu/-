package com.Java_quwei_biancheng_100_li;
import java.io.*;
public class Demo1_1_1 
{
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(b.readLine());
		for(int i=1;i<=num;i++)
		{
			for(int j=1;j<=num-i;j++)
			{
				System.out.print(" ");
			}
			for(int k=1;k<=2*i-1;k++)
			{
				System.out.printf("*");
			}
			System.out.println();
		}
	}
}
