package com.Java_quwei_biancheng_100_li;

public class Demo3_8 
{
	public static void fanXu(int n)
	{
		int i,j,k;
		i=n/100;
		j=n/10%10;
		k=n%10;
		int fx=k*100+j*10+i;
		if(n*fx==280021)
		{
			System.out.println(i+" "+j+" "+k);
		}
	}
	public static void main(String[] args)
	{
		int i;
		System.out.println("要找的数如下");
		for(i=101;i<=999;i++)
		{
			fanXu(i);
		}
	}
	
}
