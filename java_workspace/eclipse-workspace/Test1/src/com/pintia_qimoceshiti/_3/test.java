import java.util.*;
public class Main {


public static void main(String[] args) {
	Scanner in=new Scanner(System.in);
	String num1 = in.next();
	char[] num=num1.toCharArray();	
	System.out.println(isNum(num1));
}

public static boolean isNum(String str){
return str.matches("^[-+]?(([0-9]+)([.]([0-9]+))?|([.]([0-9]+))?)$");
}
}
