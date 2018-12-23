package Yankfu;
import java.util.*;
public class Pintia_cn_4_2 
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		double a,b,c,d;
		a=in.nextDouble();
		b=in.nextDouble();
		c=in.nextDouble();
		d=(b*b-4*a*c);
		if(d<0)
		{
			System.out.print("The equation has no real roots.");
		}
		else if(d==0)
		{
			System.out.printf("The root is:%.2f",((b*-1)/2*a));
		}
		else
		{
			double x1,x2;
			d=Math.sqrt(d);
			x1=(((b*-1)+d)/2*a);
			x2=(((b*-1)-d)/2*a);
			System.out.printf("The roots are %.2f and %.2f",x1,x2);
		}
	}
}
