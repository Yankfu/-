package Yankfu;

public class Demo1 
{
	public static void main(String[] args)
	{
		
	}
}

class Animal
{
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	String name;
	int age;
	//动物会叫
	public void cry()
	{
		System.out.println("不知道怎么叫");
	}
}
class Cat extends Animal
{
	public void cry()
	{
		System.out.println("喵");
	}
	
}