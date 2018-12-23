package com.pintia_qimoceshiti._18_12_20;
import java.util.*;
public class _7_6_tongjizifuchuan {

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		String str=in.next();
		int count=0;
		for (int i = 0; i < str.length(); i++) 
		{  

            char c = str.charAt(i);  
            if((c >= 'a' && c<='z') || (c >= 'A' && c<='Z'))
            {
            	count++;
            }
		}
		System.out.print("The number of letters inside the string is: "+count);
	}
}
