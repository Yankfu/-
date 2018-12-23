package com.introduction_to_java_programming;//包必须在第一行
import java.util.*;
public class P112Chapter_3_21 
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int h,q,m,j,k,year;
		System.out.println("Enter year:(e.g.,2012):");
		year=input.nextInt();
		j=year/100;
		k=year%100;
		System.out.println("Enter month:1-12:");
		m=input.nextInt();
		System.out.println("Enter the day of the month:1-31");
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
			System.out.println("Day of the week is Saturday");
			break;
		case 1:
			System.out.println("Day of the week is Sunday");
			break;
		case 2:
			System.out.println("Day of the week is Monday");
			break;
		case 3:
			System.out.println("Day of the week is Tuesday");
			break;
		case 4:
			System.out.println("Day of the week is Wednwsday");
			break;
		case 5:
			System.out.println("Day of the week is Thursday");
			break;
		case 6:
			System.out.println("Day of the week is Friday");
			break;
		}
	}
}
