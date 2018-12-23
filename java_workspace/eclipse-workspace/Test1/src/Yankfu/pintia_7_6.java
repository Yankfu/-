package Yankfu;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
public class pintia_7_6 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in=new Scanner(System.in);
		//定义一个可以存放四只狗的对象数组
		Human humans[]=new Human[100];
			
		//从控制台输入各个狗的信息
		String no="noname";
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		for(int i=0;i<100;i++)
		{
			//创建第一
			humans[i]=new Human();
			//从控制台读取名
			String name=br.readLine();
			//异常
			//将名字赋给对象
			humans[i].setName(name);
			if ((humans[i].getName()).equals(no)) break;
			int num=in.nextInt();
			//String转int
			humans[i].setNum(num);
		}
		String name1=br.readLine();
		for(int i=0;i<100;i++)
		{
			if(name1.equals(humans[i].getName())) 
			{
				System.out.print(humans[i].getName());
			}
			else
			{
				System.out.print("Nut Found！");
			}
		}
	}
}

//定义一个狗类
class Human
{
	public static char[] getNum;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	private String name;
	private int num;
}