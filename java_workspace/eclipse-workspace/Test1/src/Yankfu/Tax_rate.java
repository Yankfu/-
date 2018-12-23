package Yankfu;
import java.util.*;
public class Tax_rate 
{
	public static void main(String[] args)
	{
		@SuppressWarnings("resource")
		Scanner in=new Scanner(System.in);
		System.out.println("Please enter yout type(1-4):");
		System.out.println("1. Single filers");
		System.out.println("2. Married filing jointly or qualifying window/windower");
		System.out.println("3. Married filing separately");
		System.out.println("4. Head of household");
		int type=in.nextInt();
		System.out.println("Please enter your wage:");
		double wage=in.nextDouble();
		switch (type)
		{
		case 1:
			Single_filers(wage);
			break;
		case 2:
			Married_filing(wage);
			break;
		case 3:
			Married_filing_separately(wage);
			break;
		case 4:
			Head_of_household(wage);
			break;
		}
				
	}
	public static void Single_filers(double wage)
	{
		double waged = 0,tax = 0,rate = 0;
		if(wage<=6000)
		{
			rate=0.1;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=27950)
		{
			rate=0.15;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=67700)
		{
			rate=0.27;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=141250)
		{
			rate=0.30;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=307050)
		{
			rate=0.35;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else
		{
			rate=0.386;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		System.out.printf("The rate of your tax rate is %.2f.\n",rate);
		System.out.printf("The tax is %.2f.\n", tax);
		System.out.printf("Your after-rate wage is %.2f.\n", waged);
	}
	public static void Married_filing(double wage)
	{
		double waged = 0,tax = 0,rate = 0;
		if(wage<=12000)
		{
			rate=0.1;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=46700)
		{
			rate=0.15;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=112850)
		{
			rate=0.27;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=171950)
		{
			rate=0.30;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=307050)
		{
			rate=0.35;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else
		{
			rate=0.386;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		System.out.printf("The rate of your tax rate is %.2f.\n",rate);
		System.out.printf("The tax is %.2f.\n", tax);
		System.out.printf("Your after-rate wage is %.2f.\n", waged);
	}
	public static void Married_filing_separately(double wage)
	{
		double waged = 0,tax = 0,rate = 0;
		if(wage<=6000)
		{
			rate=0.1;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=23350)
		{
			rate=0.15;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=56425)
		{
			rate=0.27;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=85975)
		{
			rate=0.30;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=153525)
		{
			rate=0.35;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else
		{
			rate=0.386;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		System.out.printf("The rate of your tax rate is %.2f.\n",rate);
		System.out.printf("The tax is %.2f.\n", tax);
		System.out.printf("Your after-rate wage is %.2f.\n", waged);
	}
	public static void Head_of_household(double wage)
	{
		double waged = 0,tax = 0,rate = 0;
		if(wage<=10000)
		{
			rate=0.1;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=37450)
		{
			rate=0.15;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=96700)
		{
			rate=0.27;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=156600)
		{
			rate=0.30;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else if(wage<=307050)
		{
			rate=0.35;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		else
		{
			rate=0.386;
			waged=wage*(1-rate);
			tax=wage*rate;
		}
		System.out.printf("The rate of your tax rate is %.2f.\n",rate);
		System.out.printf("The tax is %.2f.\n", tax);
		System.out.printf("Your after-rate wage is %.2f.\n", waged);
	}
}
