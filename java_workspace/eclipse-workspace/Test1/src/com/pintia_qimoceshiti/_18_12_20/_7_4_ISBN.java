package com.pintia_qimoceshiti._18_12_20;
import java.util.*;
public class _7_4_ISBN {

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int i=in.nextInt();
		int j=i;
		int jieguo;
		int d1;
		int d2;
		int d3;
		int d4;
		int d5;
		int d6;
		int d7;
		int d8;
		int d9;
		d1=i%10;
		i=i/10;
		d2=i%10;
		i=i/10;
		d3=i%10;
		i=i/10;
		d4=i%10;
		i=i/10;
		d5=i%10;
		i=i/10;
		d6=i%10;
		i=i/10;
		d7=i%10;
		i=i/10;
		d8=i%10;
		i=i/10;
		d9=i%10;
		jieguo=(d1*9+d2*8+d3*7+d4*6+d5*5+d6*4+d7*3+d8*2+d9*1)%11;
        if(jieguo==10)
        {
        	System.out.print(j+"X");
        }
        else
        {
        	System.out.print(j);
        	System.out.printf("%d",jieguo);
        }
	}

}
