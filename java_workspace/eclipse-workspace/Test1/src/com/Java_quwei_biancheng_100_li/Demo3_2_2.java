/*
 * 输入一个数判断是否是水仙花数
 */
package com.Java_quwei_biancheng_100_li;

public class Demo3_2_2 
{
	public static boolean fun(int i)
	{
		int s=0;
		
		int n=(i+"").length();
		for(int k=1;k<=n;k++)
		{
			int t1=(int)(i/Math.pow(10, k-1));
			int t2=(int)Math.pow((t1%10), n);
			s+=t2;
		}
		if(s==i)
		{
			return true;
		}else
		{
			return false;
		}
	}
	public static void main(String[] args)
	{
		for(int a=100;a<=999999;a++)
		{
			if(fun(a))
			{
				System.out.println(a+"是水仙花数");
			}
		}
	}
}
