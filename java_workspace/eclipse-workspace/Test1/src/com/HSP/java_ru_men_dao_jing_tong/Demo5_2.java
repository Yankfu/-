/**
 * ���ܣ����������ʹ��
 */
package com.HSP.java_ru_men_dao_jing_tong;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Demo5_2 
{
	public static void main(String[] args) throws Exception
	{
		//����һ�����Դ����ֻ���Ķ�������
		Dog dogs[]=new Dog[4];
		
		//������������ֵ
//		Dog dogs[]=new Dog();
//		dogs[0].setName("����");
//		dogs[0].setWeight(4.5f);
		//NullPointerException
		//��ָ���쳣
		
		//�ӿ���̨�������������Ϣ
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		for(int i=0;i<4;i++)
		{
			//������һֻ��
			dogs[i]=new Dog();
			System.out.println("�������"+(i+1)+"ֻ����");
			//�ӿ���̨��ȡ����
			String name=br.readLine();
			//�쳣
			//�����ָ�������
			dogs[i].setName(name);
			System.out.println("�����빷������");
			String s_weight=br.readLine();
			float weight=Float.parseFloat(s_weight);
			//Stringתflota
			dogs[i].setWeight(weight);
		}
		//����ƽ������
		//����������
		float allWeight=0;
		for(int i=0;i<4;i++)
		{
			allWeight+=dogs[i].getWeight();
		}
		//����ƽ������
		float avgWeight=allWeight/dogs.length;
		System.out.println("������="+allWeight+"ƽ������="+avgWeight);
	
		//�ҳ���������
		
		//����������
		//�����һֻ���������
		float maxWeight=dogs[0].getWeight();
		int maxIndex=0;
		//���αȽ�����
		for(int i=1;i<dogs.length;i++)
		{
			if(maxWeight<dogs[i].getWeight())
			{
				maxWeight=dogs[i].getWeight();
				maxIndex=i;
			}
		}
		System.out.println("�������Ĺ��ǵ�"+(maxIndex+1)+"������"+dogs[maxIndex].getWeight());
		
	}
}

//����һ������
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