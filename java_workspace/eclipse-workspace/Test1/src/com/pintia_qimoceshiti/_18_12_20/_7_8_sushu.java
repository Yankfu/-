package com.pintia_qimoceshiti._18_12_20;

public class _7_8_sushu {
	    public static void main(String[] args) {
	        int n=2,i,j,count1 = 0, count2 = 1;
	        boolean isPalindromes = true;
	        boolean isPrime = true;
	        String s;
	        while(count2 <= 100){
	            for(i = 2; i<n ;i++){                 //�ж��Ƿ�Ϊ����
	                if(n % i == 0){
	                    isPrime = false;               //��������
	                    break;
	                }
	            }
	            if(isPrime == true){
	                s = String.valueOf(n);            //������ת��Ϊ�ַ�����
	                int len = s.length();
	                if(len == 1){
	                    System.out.print(n + " ");
	                    count1++;
	                    count2++;
	                }
	                else{
	                    for(j=0; j <= len/2-1; j++){         //�ж��Ƿ�Ϊ������
	                        if(s.charAt(j) != s.charAt(len-j-1)){
	                            isPalindromes = false;      //���ǻ�����
	                            break;
	                        }
	                    }
	                    if(isPalindromes == true){
	                        System.out.print(n + " ");
	                        count1++;
	                        count2++;                     //���������������+1
	                    }
	                    if(count1 == 10){                   //һ�����10��
	                        System.out.print("\n");
	                        count1=0;
	                     }
	                }
	            }
	            n++;
	            isPrime = true;                           //ÿһ���жϺ�Ҫ�ָ���ʼֵ
	            isPalindromes = true;
	        }
	    System.out.print("");
	}
	}

