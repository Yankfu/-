package com.Java_quwei_biancheng_100_li;

public class Demo2_3 
{
	public static final double MONEYRATE=0.0171;//相当于宏定义，final不改变变量，相当于常量。
	public static void main(String[] args)
	{
		double money[]=new double[48];
		money[47]=1000;
		System.out.printf("48月初的剩余存款数为：%.2f\n", money[47]);
		for(int i=47;i>0;i--)
		{
			money[i-1]=1000+money[i]/(1+MONEYRATE/12);
			System.out.printf("%d月初的剩余存款数为：%.2f\n",i,money[i-1] );
		}
		System.out.printf("\n最初要存入%.2f元", money[0]);
	}
}
