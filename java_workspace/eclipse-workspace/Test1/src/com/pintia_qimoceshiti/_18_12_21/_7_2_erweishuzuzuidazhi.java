package com.pintia_qimoceshiti._18_12_21;
import java.util.*;
public class _7_2_erweishuzuzuidazhi {

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		int b=in.nextInt();
		int c=0;
		int d=0;
		double[][] arr=new double[a][b];
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				arr[i][j]=in.nextDouble();
		double max=arr[0][0];
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if(arr[i][j]>=max)
				{
					max=arr[i][j];
					c=i;
					d=j;
				}
		System.out.printf("The location of the largest element is %.1f at (%d,%d)",max,c,d);
	}

}
