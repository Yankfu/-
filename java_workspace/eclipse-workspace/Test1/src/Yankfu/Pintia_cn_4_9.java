package Yankfu;
import java.util.*;
public class Pintia_cn_4_9 
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		double a=in.nextDouble();
        double c = Math.toRadians(36);
        c=Math.tan(c);
        double s=(5*a*a)/(4*c);
        System.out.printf("%.4f\n",s);
        System.out.printf("%.0f",5*a);
	}
}
