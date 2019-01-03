#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>


#define Height 11 //迷宫的高度，必须为奇数
#define Width 11 //迷宫的宽度，必须为奇数
#define Wall 1
#define Road 0
#define Start 2
#define End 3
#define Esc 5
#define Up 1
#define Down 2
#define Left 3
#define Right 4
#define MAXSIZE 1000

//坐标位置结构体
typedef struct local{
	
	int x;
	int y;
 
}LOCAL;
 
//栈结构
typedef struct stack{
	
	LOCAL data[MAXSIZE];
	int top;
 
}STACK;
 
//初始化栈
STACK *InitStack(void)
{
	STACK *map;
	map = (STACK *)malloc(sizeof(STACK));
	map->top = -1;
	
	return map;
}
 
//判栈空
int EmptyStack(STACK *map)
{
	if (map->top == -1)
		return 1;
	else
		return 0;
}
 
//判栈满
int IsFull(STACK *map)
{
	if (map->top == MAXSIZE - 1)
		return 1;
	else
		return 0;
 
}
 
//入栈
int PushStack(STACK *map, LOCAL *x)
{
	if (map->top <= MAXSIZE - 1){
		map->data[++map->top] = *x;
		return 1;
	}
	else{
		printf("栈已满\n");
		return 0;
	}
}
 
//出栈
int PopStack(STACK *map, LOCAL *x)
{
	if (map->top > -1){
		*x = map->data[map->top];
		map->top--;
		return 1;
	}
	else{
		printf("栈已空\n");
		return 0;
	}
}
 
//走迷宫函数
int VistMaze(int map[][Width], LOCAL path[][Width])
{
	int i, j;
 
	//初始化栈
	STACK *stack;
	LOCAL temp;
	stack = InitStack();
	temp.x = 0; temp.y = 0;
	if (map[START_I][START_J] == 0)//开始 
		PushStack(stack, &temp);
	else
		return 0;
	while(!EmptyStack(stack)){
		PopStack(stack, &temp);
		i = temp.x;	j = temp.y;
		map[i][j] = 2;
 
		if (i == END_I && j == END_J)//结束 
			break;
 
		//下
		if (i + 1 <= END_I && map[i + 1][j] == 0){
			map[i + 1][j] = 2;
			path[i + 1][j].x = i;	path[i + 1][j].y = j;
			temp.x = i + 1;
			temp.y = j;
			PushStack(stack, &temp);
		}
		//右
		if (j + 1 <= END_J && map[i][j + 1] == 0){
			map[i][j + 1] = 2;
			path[i][j + 1].x = i;	path[i][j + 1].y = j;
			temp.x = i;
			temp.y = j + 1;
			PushStack(stack, &temp);
		}
		//左
		if (j - 1 >= 0 && map[i][j - 1] == 0){
			map[i][j - 1] = 2;
			path[i][j - 1].x = i;	path[i][j - 1].y = j;
			temp.x = i;
			temp.y = j - 1;
			PushStack(stack, &temp);
		}
		//上
		if (i - 1 >= 0 && map[i - 1][j] == 0){
			map[i - 1][j] = 2;
			path[i - 1][j].x = i;	path[i - 1][j].y = j;
			temp.x = i - 1;
			temp.y = j;
			PushStack(stack, &temp);
		}
	}
	//如果到达终点而退出的循环则将路径标识出来
	if (i == END_I && j == END_J)
	{
		map[i][j] = 3;
		while(path[temp.x][temp.y].x != -1){
			temp = path[temp.x][temp.y];
			map[temp.x][temp.y] = 3;
		}
		
		return 1;
	}
	else{
		return 0;
	}
}


int map[Height+2][Width+2];
void gotoxy(int x,int y)//移动坐标 
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void create(int x,int y) //随机生成迷宫
{
    int c[4][2]={0,1,1,0,0,-1,-1,0}; //四个方向
    int i,j,t;
        //将方向打乱
    for(i=0;i<4;i++)
    {
        j=rand()%4;
        t=c[i][0];
		c[i][0]=c[j][0];
		c[j][0]=t;
        t=c[i][1];
		c[i][1]=c[j][1];
		c[j][1]=t;
    }
    map[x][y]=Road;
    for(i=0;i<4;i++)
    if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall)
    {
        map[x+c[i][0]][y+c[i][1]]=Road;
        create(x+2*c[i][0],y+2*c[i][1]);
    }
}
void paint(int x,int y) //画迷宫
{
    gotoxy(2*y-2,x-1);
    switch(map[x][y])
    {
        case Start:
        printf("入");break; //画入口
        case End:
        printf("出");break; //画出口
        case Wall:
        printf("▇");break; //画墙
        case Road:
        printf(" ");break; //画路
    }
}


int main()
{


    int i,j;
    srand((unsigned)time(NULL)); //初始化随即种子

    for(i=0;i<=Height+1;i++)
    	for(j=0;j<=Width+1;j++)
    		if(i==0||i==Height+1||j==0||j==Width+1) //初始化迷宫
    			map[i][j]=Road;
    		else map[i][j]=Wall;
 
    create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //从随机一个点开始生成迷宫，该点行列都为偶数


	for(i=0;i<=Height+1;i++) //边界处理 
    {
        map[i][0]=Wall;
        map[i][Width+1]=Wall;
    }
 
    for(j=0;j<=Width+1;j++) //边界处理
    {
        map[0][j]=Wall;
        map[Height+1][j]=Wall;
    }
    map[2][1]=Start; //给定入口
    map[Height-1][Width]=End; //给定出口
    
	

    for(i=1;i<=Height;i++)
    {
		for(j=1;j<=Width;j++) //画出迷宫
    	{
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
    for(i=1;i<=Height;i++)
    	for(j=1;j<=Width;j++) //画出迷宫
    		paint(i,j);

	LOCAL path[Height][Width];
	for(i = 0; i < Height; i++){
		for(j = 0; j < Width; j++){
			path[i][j].x = -1;
			path[i][j].y = -1;
		}
	}
	if (VistMaze(map, path) == 0){
		printf("没有路径可走\n");
		exit(0);
	}
 
	//打印出迷宫和路径
	printf("迷宫和路径：\n");
	for(i = 0; i <= Height; i++)
		printf("-");
	printf("\n");
	for (i = 0; i < Height; i++){
		printf("|");
		for (j = 0; j < Width; j++){
			if (map[i][j] == 1)
				printf("@");
			else if (map[i][j] == 3)
				printf("%%");
			else
				printf(" ");
		}
		printf("|\n");
	}
	for(i = 0; i <= Height; i++)
		printf("-");
	printf("\n");
 
	return 0;
    getch();
    return 0;
}
