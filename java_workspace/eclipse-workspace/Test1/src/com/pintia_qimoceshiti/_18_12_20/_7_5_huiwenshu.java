package com.pintia_qimoceshiti._18_12_20;


import java.util.Scanner;

public class _7_5_huiwenshu {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();

		String str1 = num + "";
		// String str1 = Integer.toString(num);
		// String str1 = String.valueOf(num);

		StringBuilder str2 = new StringBuilder(str1);
		str2.reverse();
		int count = 0;

		for (int i = 0; i < str1.length(); i++) {
			if (str1.charAt(i) != str2.charAt(i)) {
				System.out.println(str1 + " is NOT a palindrome.");
				break;
			} else {
				count++;
			}
		}
		if (count == str1.length()) {
			System.out.println(str1 + " is a palindrome.");
		}
	}

}
