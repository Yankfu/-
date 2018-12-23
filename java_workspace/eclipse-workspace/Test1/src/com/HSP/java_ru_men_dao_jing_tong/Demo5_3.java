package com.HSP.java_ru_men_dao_jing_tong;
/*
 * 功能：演示各种排序法
 */
public class Demo5_3 
{
	public static void main(String[] args)
	{
		int arr[]= {1,6,0,-1,9};
		int temp=0;
		Bubble bubble=new Bubble();
		bubble.sort(arr);
		for(int i=0;i<=arr.length;i++)
		{
			System.out.print(arr[i]+"");
		}
	}
}

class Bubble
{
	//排序方法
	public void sort(int arr[])
	{
		int temp=0;
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<=arr.length-i;j++)
			{
				if(arr[j]>arr[j+1])
				{
					//换位
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
			
				}
			}
		}
	}
}