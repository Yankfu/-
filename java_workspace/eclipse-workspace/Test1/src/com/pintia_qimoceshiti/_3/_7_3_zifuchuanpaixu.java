package com.pintia_qimoceshiti._3;
import java.util.Scanner;
public class _7_3_zifuchuanpaixu {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        char[] str=new char[100];
        char temp;
        String string,replace = null;
        Scanner sc=new Scanner(System.in);
        string=sc.next();
        str=string.toCharArray();
        replace=string;
            for(int i=0;i<string.length();i++)
            for(int j=string.length()-1;j>i;j--)
            {
                if(str[j]<=str[j-1])
                {
                    temp=str[j];
                    str[j]=str[j-1];
                    str[j-1]=temp;
                }
            }
            System.out.println(str);
    }
}