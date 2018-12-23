import java.util.Arrays;
import java.util.Scanner;
package com.Java_quwei_biancheng_100_li;

public class Demo3_5 
{
	public static void main(String[] args)
	{
		for(int input=1000;input<=9999;input++)
		{
			System.out.println("\n"+input+" 验证如下: ");
			
			if(input%1111==0)
			{
				System.out.println("数字全部相同！");
				continue;
			}else
			{
				int flag=0;
				int input2=input;
				do
				{
					input2=he(fen(input2));
					flag++;
				}while(input2!=6174);
				
				if(input2==6174)
				{
					System.out.println("计算了"+flag+"次，"+"命题为真！");
				}
				else
					System.out.println("命题为假");
			}
		}
		System.out.println("程序结束");
	}
	public static int[] fen(int input)
	{
		int a[]=new int [4];
		a[0]=input/1000;
		input=input%1000;
		a[1]=input/100;
		input=input%100;
		a[2]=input;
		input=input%10;
		a[3]=input;
		Arrays.sort(a);
	}
	public static int he(int a[])
	{
		Arrays.sort(a);
		int max=a[3]*1000+a[2]*100+a[1]*10+a[0];
		int min=a[0]*1000+a[1]*100+a[2]*10+a[3];
		System.out.println(max+"-"+min+"="+(max-min));
		return max-min;
	}
}
