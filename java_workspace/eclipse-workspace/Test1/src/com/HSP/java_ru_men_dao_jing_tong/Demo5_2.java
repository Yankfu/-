/**
 * 功能：对象数组的使用
 */
package com.HSP.java_ru_men_dao_jing_tong;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Demo5_2 
{
	public static void main(String[] args) throws Exception
	{
		//定义一个可以存放四只狗的对象数组
		Dog dogs[]=new Dog[4];
		
		//给各个狗赋初值
//		Dog dogs[]=new Dog();
//		dogs[0].setName("花花");
//		dogs[0].setWeight(4.5f);
		//NullPointerException
		//空指针异常
		
		//从控制台输入各个狗的信息
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		for(int i=0;i<4;i++)
		{
			//创建第一只狗
			dogs[i]=new Dog();
			System.out.println("请输入第"+(i+1)+"只狗名");
			//从控制台读取狗名
			String name=br.readLine();
			//异常
			//将名字赋给对象
			dogs[i].setName(name);
			System.out.println("请输入狗的体重");
			String s_weight=br.readLine();
			float weight=Float.parseFloat(s_weight);
			//String转flota
			dogs[i].setWeight(weight);
		}
		//计算平均体重
		//计算总体重
		float allWeight=0;
		for(int i=0;i<4;i++)
		{
			allWeight+=dogs[i].getWeight();
		}
		//计算平均体重
		float avgWeight=allWeight/dogs.length;
		System.out.println("总体重="+allWeight+"平均体重="+avgWeight);
	
		//找出体重最大的
		
		//遍历，排序
		//假设第一只狗体重最大
		float maxWeight=dogs[0].getWeight();
		int maxIndex=0;
		//依次比较体重
		for(int i=1;i<dogs.length;i++)
		{
			if(maxWeight<dogs[i].getWeight())
			{
				maxWeight=dogs[i].getWeight();
				maxIndex=i;
			}
		}
		System.out.println("体重最大的狗是第"+(maxIndex+1)+"体重是"+dogs[maxIndex].getWeight());
		
	}
}

//定义一个狗类
class Dog
{
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public float getWeight() {
		return weight;
	}
	public void setWeight(float weight) {
		this.weight = weight;
	}
	private String name;
	private float weight;
}