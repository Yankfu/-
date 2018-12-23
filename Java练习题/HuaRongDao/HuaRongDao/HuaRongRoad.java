package xupt.xw.HuaRongDao;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class HuaRongRoad extends Application {
	Pane pane = new Pane();
	Scene scene = new Scene(pane,460,590);

	private Person[] person = {
		new Person(0, "曹操"),
		new Person(1, "张飞"),
		new Person(2, "马超"),
		new Person(3, "黄忠"),
		new Person(4, "赵云"),
		new Person(5, "关羽"),
		new Person(6, "兵甲"),
		new Person(7, "兵乙"),
		new Person(8, "兵丙"),
		new Person(9, "兵丁")
	};

	Button up = new Button();
	Button down = new Button();
	Button left = new Button();
	Button right = new Button();
	
	@Override
	public void start(Stage stage) throws Exception {
		
		stage.setTitle("华容道");
		stage.setHeight(590);
		stage.setWidth(460);
		stage.setScene(scene);
		stage.setResizable(true);
		stage.show();
		
		sizeInitialize();
		localInitialize();
		
		pane.getChildren().addAll(person);
		pane.getChildren().add(left);
		pane.getChildren().add(up);
		pane.getChildren().add(down);
		pane.getChildren().add(right);
		
		move();
	}

	private void move() {
		for(Person m : person) {
			m.setOnMouseClicked(new EventHandler<MouseEvent>() {
				@Override
				public void handle(MouseEvent e) {
					Person man = (Person)e.getSource();
					double x = e.getX();
					double y = e.getY();
					double w = man.getWidth();
					double h = man.getHeight();
					
					if(y > h-20 && y < h && x > 20 && x < w-20) {
						go(man,down);
					} 
					if(y < 20 && y > 0 && x > 20 && x < w-20) {
						go(man,up);
					}
					if(x < 20 && x > 0 && y > 20 && y < h - 20) {
						go(man,left);
					}
					if(x > 20 && x < w && y > 20 && y < h - 20) {
						go(man,right);
					}
				}
			});
		}
	}

	public void go(Person man,Button direction) {
		Rectangle manRect = new Rectangle(man.getWidth(), man.getHeight());              
		double x = man.getLayoutX();                         
		double y = man.getLayoutY();
		boolean canMove = true;
		
		if(direction==down) {
			y = y+105;
		} else if(direction==up) {
			y = y-105;
		} else if(direction==left) {
			x = x-105;
		} else if(direction==right) {
			x = x+105;
		}

		manRect.setLayoutX(x);
		manRect.setLayoutY(y);
		
		for(int k = 0;k<10;k++) {
			if((man.getNumber() != k) && 
					(manRect.getBoundsInParent().intersects
							(person[k].getLayoutX(), person[k].getLayoutY(), 
							person[k].getWidth(), person[k].getHeight()))) {
				canMove = false;
			}
		}
		
		if((manRect.getBoundsInParent().intersects
				(direction.getLayoutX(), direction.getLayoutY(), 
				direction.getWidth(), direction.getHeight()))) {
			canMove = false;
		}

		if(canMove) {
			man.setLayoutX(x);
			man.setLayoutY(y);
		}
	}

	
	private void sizeInitialize() {
		person[0].setPrefSize(200, 200);
		person[0].setMaxSize(200, 200);
		person[0].setMinSize(200, 200);
		for(int i = 1; i < 5; i++) {
			person[i].setPrefSize(100, 200);
			person[i].setMaxSize(100, 200);
			person[i].setMinSize(100, 200);
		}
		person[5].setPrefSize(200, 95);
		person[5].setMaxSize(200, 95);
		person[5].setMinSize(200, 95);
		for(int i = 6; i < 10; i++) {
			person[i].setPrefSize(95, 95);
			person[i].setMaxSize(95, 95);
			person[i].setMinSize(95, 95);
		}

		left.setPrefSize(10, 560);
		left.setMaxSize(10, 560);
		left.setMinSize(10, 560);
		up.setPrefSize(460,10);
		up.setMaxSize(460,10);
		up.setMinSize(460,10);
		down.setPrefSize(460, 10);
		down.setMaxSize(460, 10);
		down.setMinSize(460, 10);
		right.setPrefSize(10, 560);
		right.setMaxSize(10, 560);
		right.setMinSize(10, 560);
		
		for(Person man : person) {
			man.setFont(Font.font(STYLESHEET_CASPIAN, 22));
		}
	}

	private void localInitialize() {
		person[0].setLayoutX(130); person[0].setLayoutY(20);
		person[1].setLayoutX(20);  person[1].setLayoutY(20);
		person[2].setLayoutX(340); person[2].setLayoutY(20);
		person[3].setLayoutX(20);  person[3].setLayoutY(230);
		person[4].setLayoutX(340); person[4].setLayoutY(230);
		person[5].setLayoutX(130); person[5].setLayoutY(230);
		person[6].setLayoutX(20);  person[6].setLayoutY(440);
		person[7].setLayoutX(130); person[7].setLayoutY(340);
		person[8].setLayoutX(240); person[8].setLayoutY(340);
		person[9].setLayoutX(340); person[9].setLayoutY(440);

		left.setLayoutX(0);		left.setLayoutY(0);
		up.setLayoutX(0);   	up.setLayoutY(0);
		down.setLayoutX(0); 	down.setLayoutY(550);
		right.setLayoutX(450);  right.setLayoutY(0);
	}

	public static void main(String[] args) {
		Application.launch(args);
	}
}
