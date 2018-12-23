package com.HSP.java_ru_men_dao_jing_tong;
//接口
public class Test 
{
	public static void main(String[] args)
	{
		Computer computer=new Computer();
		Camera camera1=new Camera();
		Phone phone1=new Phone();
		computer.use_Usb(camera1);
		computer.use_Usb(phone1);
	}
}


interface Usb
{
	int a=1;
	public void start();
	public void stop();
}
//当一个类实现了一个接口，就要求该类把这个接口的所有方法都实现
class Camera implements Usb
{
	public void start()
	{
		System.out.println("我是相机，开始工作了！！！");
	}
	public void stop()
	{
		System.out.println("我是相机，停止工作了！！！");
	}
}

class Phone implements Usb
{
	public void start()
	{
		System.out.println("我是手机，开始工作了！！！");
	}
	public void stop()
	{
		System.out.println("我是手机，停止工作了！！！");
	}
}

class Computer
{
	public void use_Usb(Usb usb)
	{
		usb.start();
		usb.stop();
	}
}