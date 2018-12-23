package com.HSP.java_ru_men_dao_jing_tong;
/*
 * 抽象类的必要性
 */
public class Demo6 
{
	public static void main(String[] args)
	{
		
	}
}


abstract class Animal
//抽象类不能被实例化
{
	String name;
	int age;
	//动物会叫
	abstract public void cry();
}

class Cat extends Animal
{

	@Override
	public void cry() 
	{
		// TODO Auto-generated method stub
		System.out.println("喵喵喵");
		
	}
}

