package com.Java_quwei_biancheng_100_li;
import java.util.*;
public class Demo1_2_1 
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=i;j++)
			{
				System.out.print(" "+j+"*"+i+"="+(i*j));
			}
			System.out.println(" ");
		}
	}
}
