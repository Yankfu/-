package com.pintia_qimoceshiti._3;
import java.math.BigInteger;
import java.util.*;

public class _7_2_特大数相除 {


public static void main(String[] args) {
	Scanner in=new Scanner(System.in);
	String num1 = in.nextLine();
	String num2 = in.nextLine();
	BigInteger big1 = new BigInteger(num1);
	BigInteger big2 = new BigInteger(num2);
	BigInteger result[] = big1.divideAndRemainder(big2);
	System.out.println("相除后的商是:" + result[0]);
}


}