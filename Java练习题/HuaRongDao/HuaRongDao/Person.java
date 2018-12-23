package xupt.xw.HuaRongDao;

import javafx.scene.control.Button;

class Person extends Button{
	private int number;
	private String name;

	public Person(int number, String name) {
		this.setName(name);
		this.number = number;
	}

	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		super.setText(name);
		this.name = name;
	}
	
}