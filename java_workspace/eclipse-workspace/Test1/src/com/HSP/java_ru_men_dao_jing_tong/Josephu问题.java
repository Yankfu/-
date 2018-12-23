/*
 * 功能：丢手帕问题
 */
package com.HSP.java_ru_men_dao_jing_tong;

public class Josephu问题 
{
	public static void main(String[] args)
	{
		
	}
}

class Child
{
	int no;
	Child nextChild=null;
	
	public Child(int no)
	{
		//给小孩一个编号
		this.no=no;
	}
}

//环形链表
class Cyc_link
{
	//先定义一个指向链表第一个小孩的引用
	//指向第一个小孩的引用，不能动
	Child firstChild=null;
	Child temp=null;
	int len=0;//表示共有多少个小孩
	//设置链表大小
	public void setLen(int len)
	{
		this.len=len;
	}
	
	//初始化环形链表
	public void creatLink()
	{
		for(int i=1;i<=len;i++)
		{
			if(i==1) 
			{
				//创建第一个小孩
				Child ch=new Child(i);
				this.firstChild=ch;
				this.temp=ch;
			}
			else
			{
				//继续创建小孩
				Child ch=new Child(i);
				temp.nextChild=ch;
				temp=ch; 
			}
		}
		
	}
}