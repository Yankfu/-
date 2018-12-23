/*
 * 完全数
 */
package com.Java_quwei_biancheng_100_li;

public class Demo3_3 
{
	public static void main(String[] args)
	{
		int i,j,sum;
		for(i=2;i<10000;i++)
		{
			sum=0;
			for(j=1;j<=i/2;j++)
			{
				if(i%j==0)
					sum=sum+j;
			}
			if(sum==i)
				printwanshu(i);
		}
	}

	private static void printwanshu(int n) 
	{
		// TODO Auto-generated method stub
		int j;
		System.out.print(n+"的约数（自身除外）为：");
		for(j=1;j<=n/2;j++)
		{
			if(n%j==0)
				System.out.print(j+" ");
		}
		System.out.print("\n");
	}
}
