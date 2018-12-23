package com.pintia_qimoceshiti._18_12_20;
import java.util.*;
public class _7_3_waimianduoleng {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		double f;
		int ws;
		f=in.nextDouble();
		ws=in.nextInt();
		double cold;
		cold=35.74 + 0.6215*f-35.75*Math.pow(ws, 0.16)+0.4275*f*Math.pow(ws, 0.16);
		System.out.printf("The wind chill index is %f", cold);
	}

}
