package com.pintia_qimoceshiti._18_12_20;
import java.util.*;
public class _7_2_day_of_week
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int h,q,m,j,k,year;
		year=input.nextInt();
		j=year/100;
		k=year%100;
		m=input.nextInt();
		q=input.nextInt();
		if(m==1)
		{
			m=13;
			if(k==0)
			{
				k=99;
				j-=1;
			}
			else k--;
		}
		else if(m==2)
		{
			m=14;
			if(k==0)
			{
				k=99;
				j-=1;
			}
			else k--;
		}
		h=(q+(int)(26*(m+1)/10)+k+(int)(k/4)+(int)(j/4)+5*j)%7;
		switch(h)
		{
		case 0:
			System.out.println("Saturday");
			break;
		case 1:
			System.out.println("Sunday");
			break;
		case 2:
			System.out.println("Monday");
			break;
		case 3:
			System.out.println("Tuesday");
			break;
		case 4:
			System.out.println("Wednwsday");
			break;
		case 5:
			System.out.println("Thursday");
			break;
		case 6:
			System.out.println("Friday");
			break;
		}
	}
}