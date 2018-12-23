package Yankfu;
import java.util.*;
public class Pintia_cn_4_1 
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		double a1,a2,b1,b2;
		a1=in.nextDouble();
		a2=in.nextDouble();
		b1=in.nextDouble();
		b2=in.nextDouble();
		double x;
		x=Math.sqrt((b1-a1)*(b1-a1)+(b2-a2)*(b2-a2));
		System.out.printf("The distance is %.2f",x);
	}
}
