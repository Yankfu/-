package Yankfu;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
public class pintia_7_6 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in=new Scanner(System.in);
		//����һ�����Դ����ֻ���Ķ�������
		Human humans[]=new Human[100];
			
		//�ӿ���̨�������������Ϣ
		String no="noname";
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		for(int i=0;i<100;i++)
		{
			//������һ
			humans[i]=new Human();
			//�ӿ���̨��ȡ��
			String name=br.readLine();
			//�쳣
			//�����ָ�������
			humans[i].setName(name);
			if ((humans[i].getName()).equals(no)) break;
			int num=in.nextInt();
			//Stringתint
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
				System.out.print("Nut Found��");
			}
		}
	}
}

//����һ������
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