package com.HSP.java_ru_men_dao_jing_tong;
/*
 * 功能：数组的必要性
 * @author 85723
 *
 */

public class Demo5_1 
{
	public static void main(String[] args)
	{
		/*
		//定义一个可以存放六个float类型的数组
		float arr[]=new float[6];
		//使用for赋值
		
		 *程序员用法
		*数据类型 数组名[] =new 数据类型[大小]；
		*int a[]=new int[5];
		 * 
		arr[0]=3;//精度自动转换
		arr[1]=5;
		arr[2]=1;
		arr[3]=3.4f;
		arr[4]=2;
		arr[5]=50;
		
		//计算六只鸡总体重
		float all=0;
		for(int i=0;i<6;i++)
		{
			all += arr[i];
		}
		System.out.println("总体重是："+all);
		*/
		/*
		 *没事找事形
		 * 第一步：先声明数组
		 * int a[]或int[] a;
		 * 第二步：创建数组
		 * 数组名= new 数据类型[大小];
		 * a=new int[10];
		 * 
		 */
		//定义一个size=5 的int数组
		//int arr[];
		//arr=new int[5];
		
		//如果你访问的数组的范围大了（数组越界）
		//编译可以通过，但是是错误的，会运行错误。
		//arr[5]=10;
		
		//如何知道数组大小
		//System.out.println(arr.length);
		
		/*
		 * 古板用法
		 * 第一步：初始化数组
		 * 数据类型 数组名[]={元素值，元素值...}
		 * int a[]={2,5,6,7,8,9};
		 */
//		float arr[]= {3,6,7.1f,1.1f,3};
//		float all=0;
//		for(int i=0;i<arr.length;i++)
//		{
//			all+=arr[i];
//		}
//		System.out.println("平均时间："+(all/arr.length));
//		
		
		
	}

}
