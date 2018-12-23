package com.pintia_qimoceshiti._18_12_20;

public class _7_8_sushu {
	    public static void main(String[] args) {
	        int n=2,i,j,count1 = 0, count2 = 1;
	        boolean isPalindromes = true;
	        boolean isPrime = true;
	        String s;
	        while(count2 <= 100){
	            for(i = 2; i<n ;i++){                 //判断是否为素数
	                if(n % i == 0){
	                    isPrime = false;               //不是素数
	                    break;
	                }
	            }
	            if(isPrime == true){
	                s = String.valueOf(n);            //将整型转换为字符串型
	                int len = s.length();
	                if(len == 1){
	                    System.out.print(n + " ");
	                    count1++;
	                    count2++;
	                }
	                else{
	                    for(j=0; j <= len/2-1; j++){         //判断是否为回文数
	                        if(s.charAt(j) != s.charAt(len-j-1)){
	                            isPalindromes = false;      //不是回文数
	                            break;
	                        }
	                    }
	                    if(isPalindromes == true){
	                        System.out.print(n + " ");
	                        count1++;
	                        count2++;                     //已输出回文数个数+1
	                    }
	                    if(count1 == 10){                   //一行输出10个
	                        System.out.print("\n");
	                        count1=0;
	                     }
	                }
	            }
	            n++;
	            isPrime = true;                           //每一次判断后要恢复初始值
	            isPalindromes = true;
	        }
	    System.out.print("");
	}
	}

