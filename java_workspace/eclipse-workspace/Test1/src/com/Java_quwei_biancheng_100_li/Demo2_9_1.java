package com.Java_quwei_biancheng_100_li;
import java.text.*;
public class Demo2_9_1 
{
	static double polynomiallD(double a[],int n,double x)
	{
		int i;
		double result;
		result=a[n-1];
		for(i=n-2;i>=0;i--)
		{
			result=result*x+a[i];
		}
		return result;
	}
	public static void main(String[] args)
	{
		int i;
		double a[]= {-15.0,-7.0,7.0,2.0,-3.0,7.0,3.0};
		double[] x= {-2.0,-0.5,1.0,2.0,3.7,4.0};
		double result;
		
		DecimalFormat df=new DecimalFormat("0.0000000E000");
		DecimalFormat df1=new DecimalFormat("0.00");
		
		System.out.println("计算P(x)=3x6+7x5-3x4+2x3+7x2-7x-15的值");
		for(i=0;i<6;i++)
		{
			result=polynomiallD(a,7,x[i]);
			System.out.print("x="+df1.format(x[i])+"时，p（x）="+df.format(result)+"\n");
		}
		System.out.print("\n");
	}
}
