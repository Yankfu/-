package Yankfu;
import java.util.*;
public class Chinese_tax_rate 
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		System.out.println("请输入工资:");
		double wage=in.nextDouble();
		tax_rate(wage);
	}
	public static void tax_rate(double wage)
	{
		double waged = 0,tax = 0,rate = 0;
		waged=wage-5000;
		if(waged<=3000)
		{
			rate=0.03;
			tax=(wage-5000)*rate;
			wage=wage-tax;
		}
		else if(waged<=12000)
		{
			rate=0.15;
			tax=(wage-5000)*rate-210;
			wage=wage-tax;
		}
		else if(waged<=25000)
		{
			rate=0.20;
			tax=(wage-5000)*rate-1410;
			wage=wage-tax;
		}
		else if(waged<=35000)
		{
			rate=0.25;
			tax=(wage-5000)*rate-2660;
			wage=wage-tax;
		}
		else if(waged<=55000)
		{
			rate=0.30;
			tax=(wage-5000)*rate-4410;
			wage=wage-tax;
		}
		else if(waged<=80000)
		{
			rate=0.35;
			tax=(wage-5000)*rate-7160;
			wage=wage-tax;
		}
		else
		{
			rate=0.45;
			tax=(wage-5000)*rate-15160;
			wage=wage-tax;
		}
		System.out.printf("shuihougongzi %.2f.\n", wage);
	}
}