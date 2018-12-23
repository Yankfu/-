package com.Java_quwei_biancheng_100_li;

import java.text.*;
import java.util.*;

public class Demo2_1 
{
	public static void main(String[] args)
	{
		@SuppressWarnings("resource")
		Scanner input = new Scanner(System.in);
		System.out.println("请输入起始年份:");
		int year=input.nextInt();
		System.out.println("请输入要打印未来几年：");
		int n=input.nextInt();
		getBlackFri(year,n);
	}

	private static void getBlackFri(int year, int n) {
		// TODO Auto-generated method stub
		SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd E");
		int k=0;
		Calendar cal=Calendar.getInstance();
		while(k<n)
		{
			for(int i=0;i<12;i++)
			{
				cal.set(year, i,13);
				if(5==(cal.get(Calendar.DAY_OF_WEEK)-1))
				{
					System.out.println("黑色星期五："+sdf.format(cal.getTime()));
				}
			}
			year++;
			k++;
		}
	}
}
