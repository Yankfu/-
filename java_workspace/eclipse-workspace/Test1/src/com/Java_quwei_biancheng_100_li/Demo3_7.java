package com.Java_quwei_biancheng_100_li;

public class Demo3_7 
{
	public static void main(String[] args)
	{
		for(int i=1;i<10000;i++)
		{
			ziShouShu(i);
		}
	}

	private static void ziShouShu(int n) 
	{
		// TODO Auto-generated method stub
		String strI=String.valueOf(n);
		String multiStr=String.valueOf(n*n);
		String last=multiStr.substring(multiStr.length()-strI.length());
		if(last.equals(strI))
		{
			System.out.println(n+"*"+n+"="+multiStr+"--> "+n+" 是自守数");
		}
	}
}
