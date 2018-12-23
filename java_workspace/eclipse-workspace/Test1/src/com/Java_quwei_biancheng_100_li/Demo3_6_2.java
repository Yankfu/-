package com.Java_quwei_biancheng_100_li;

public class Demo3_6_2 
{
	public static final void getGouguNum2(int maxnum)
	{
		for(int i=1;i<maxnum-2;i++)
		{
			for(int j=i+1;j<maxnum-1;j++)
			{
				int  sum=i*i+j*j;
				int c=(int)(Math.sqrt(sum));
				if(c*c==sum&&c<=maxnum)
				{
					System.out.println(" "+i+" "+j+" "+c);
				}
			}
		}
	}
	public static void main(String[] args)
	{
		System.out.print("勾股数如下：\n");
		long begin=System.currentTimeMillis();//计算耗时
		getGouguNum2(10000);
		long end=System.currentTimeMillis();//计算耗时
		System.out.print("耗时"+(end-begin)+"ms");
	}
}
