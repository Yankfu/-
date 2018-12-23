package com.introduction_to_java_programming;
import java.util.Scanner;

public class P280Chapter_7_21 {
	public static void main(String []args) {
		Scanner input=new Scanner(System.in);
		System.out.print("Enter the number of bea to drop: ");
		int n=input.nextInt();
		System.out.print("Enter the number of slots in the bean machine: ");
		int m=input.nextInt();
		
		pathOfBea(n,m);
		input.close();
	}
	public static char randomarrow() {
		int arrow=(int)(Math.random()*2);
		
		char arr = 0;
		switch(arrow) {
		case 0:arr='L';break;
		case 1:arr='R';break;
		}
		System.out.print(arr);	
		return arr;	
		
	}
	public static void pathOfBea(int n,int m) {
		int count=0;
		int[] slots=new int[m];
		char[] path=new char[m-1];
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<m-1;i++)
			{
				path[i]=randomarrow();
				if(path[i]=='R')
					count++;
			}
			slots[count]++;
			count=0;
			System.out.println();
		}
		for(int i=max(slots);i>0;i--)
			{
			   for(int j=0;j<m;j++)
			   {
				   if(slots[j]>=i)
				      System.out.print("o");
				   else
					  System.out.print(" "); 
			   }
			   System.out.println("");
			}
	}
	public static int max(int[]num){  
        int maxNum = 0;  
        for(int i = 0;i < num.length;i++){  
            if(num[i] > maxNum)  
                maxNum = num[i];  
        }  
        return maxNum;  
    }  
}