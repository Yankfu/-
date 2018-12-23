package com.pintia_qimoceshiti._18_12_20;
import java.util.*;
public class _7_7_shijian 
{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num;
        int hour = 0;
        int minute = 0;
        int second = 0;
        
        num = scan.nextInt();
        num=num/1000;
        second = num % 60;
        num -= second;
        if(num > 0) {
            num /= 60;
            minute = num % 60;
            num -= minute;
            if(num > 0) {
                hour = num / 60;
            }          
        }
        String str1="";
        String str2="";
        String str3="";
        str1=String.valueOf(hour);
        str2=String.valueOf(minute);
        str3=String.valueOf(second);
        System.out.print(str1+":"+str2+":"+str3);
    }
}
