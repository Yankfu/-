#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 

#define Height 9
#define Width 9
#define START_I 2 
#define START_J 1
#define END_I Height-1 
#define END_J Width
#define MAXSIZE 1000
#define Wall 1
#define Road 0
 
//坐标位置结构体
typedef struct local
{	
	int x;
	int y;
 
}LOCAL;
int maze[Height+2][Width+2];
//栈结构
typedef struct stack
{
	
	LOCAL data[MAXSIZE];
	int top;
 
}STACK;
 
//初始化栈
STACK *InitStack(void)
{
	STACK *maze;
	maze = (STACK *)malloc(sizeof(STACK));
	maze->top = -1;
	
	return maze;
}
 
//判栈空
int EmptyStack(STACK *maze)
{
	if (maze->top == -1)
		return 1;
	else
		return 0;
}
 
//判栈满
int IsFull(STACK *maze)
{
	if (maze->top == MAXSIZE - 1)
		return 1;
	else
		return 0;
 
}
 
//入栈
int PushStack(STACK *maze, LOCAL *x)
{
	if (maze->top <= MAXSIZE - 1)
	{
		maze->data[++maze->top] = *x;
		return 1;
	}
	else
	{
		printf("栈已满\n");
		return 0;
	}
}
 
//出栈
int PopStack(STACK *maze, LOCAL *x)
{
	if (maze->top > -1)
	{
		*x = maze->data[maze->top];
		maze->top--;
		return 1;
	}
	else
	{
		printf("栈已空\n");
		return 0;
	}
}
 
//走迷宫函数
int VistMaze(int maze[][Width+2], LOCAL path[][Width+2])
{
	int i, j;
 
	//初始化栈
	STACK *stack;
	LOCAL temp;
	stack = InitStack();
	temp.x = 0; temp.y = 0;
	if (maze[START_I][START_J] == 0)
		PushStack(stack, &temp);
	else
		return 0;
	while(!EmptyStack(stack))
	{
		PopStack(stack, &temp);
		i = temp.x;	
		j = temp.y;
		maze[i][j] = 2;
 
		if (i == END_I && j == END_J)
			break;
 
		//下
		if (i + 1 <= END_I && maze[i + 1][j] == 0)
		{
			maze[i + 1][j] = 2;
			path[i + 1][j].x = i;
			path[i + 1][j].y = j;
			temp.x = i + 1;
			temp.y = j;
			PushStack(stack, &temp);
		}
		//右
		if (j + 1 <= END_J && maze[i][j + 1] == 0)
		{
			maze[i][j + 1] = 2;
			path[i][j + 1].x = i;	
			path[i][j + 1].y = j;
			temp.x = i;
			temp.y = j + 1;
			PushStack(stack, &temp);
		}
		//左
		if (j - 1 >= 0 && maze[i][j - 1] == 0)
		{
			maze[i][j - 1] = 2;
			path[i][j - 1].x = i;	
			path[i][j - 1].y = j;
			temp.x = i;
			temp.y = j - 1;
			PushStack(stack, &temp);
		}
		//上
		if (i - 1 >= 0 && maze[i - 1][j] == 0)
		{
			maze[i - 1][j] = 2;
			path[i - 1][j].x = i;	
			path[i - 1][j].y = j;
			temp.x = i - 1;
			temp.y = j;
			PushStack(stack, &temp);
		}
	}
	//如果到达终点而退出的循环则将路径标识出来
	if (i == END_I && j == END_J)
	{
		maze[i][j] = 3;
		while(path[temp.x][temp.y].x != -1)
		{
			temp = path[temp.x][temp.y];
			maze[temp.x][temp.y] = 3;
		}
		
		return 1;
	}
	else
	{
		return 0;
	}
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
    maze[x][y]=Road;
    for(i=0;i<4;i++)
    if(maze[x+2*c[i][0]][y+2*c[i][1]]==Wall)
    {
        maze[x+c[i][0]][y+c[i][1]]=Road;
        create(x+2*c[i][0],y+2*c[i][1]);
    }
}
 
 
int main(void)
{
	//迷宫
	int i, j;
	
	//生成随机迷宫 
	{ 
	srand((unsigned)time(NULL));
		
	for(i=0;i<=Height+1;i++)
    	for(j=0;j<=Width+1;j++)
    		if(i==0||i==Height+1||j==0||j==Width+1) //初始化迷宫
    			maze[i][j]=Road;
    		else maze[i][j]=Wall;
 
    create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //从随机一个点开始生成迷宫，该点行列都为偶数
//    for(i=0;i<=Height+1;i++) //边界处理 
//    {
//        maze[i][0]=Wall;
//        maze[i][Width+1]=Wall;
//    }
// 
//    for(j=0;j<=Width+1;j++) //边界处理
//    {
//        maze[0][j]=Wall;
//        maze[Height+1][j]=Wall;
//    }
	} 
	

	//定义路径数组,将到(x,y)点的路径保存进数组
	LOCAL path[Height+2][Width+2];
	for(i = 0; i < Height+2; i++)
	{
		for(j = 0; j < Width+2; j++)
		{
			path[i][j].x = -1;
			path[i][j].y = -1;
		}
	}
 
	//打印出迷宫
	maze[2][1]=0;
	maze[Height-1][Width]=0;
	printf("原迷宫：\n");
	printf("\n");
	for (i = 0; i < Height+2; i++)
	{
		for (j = 0; j < Width+2; j++)
		{
			if (maze[i][j] == 1)
				printf("■");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");
	FILE *fp;
	char filename[50];
	strcpy(filename,"maze.txt");
	fp=fopen(filename,"wt+");
	for (i = 0; i < Height+2; i++)
	{
		for (j = 0; j < Width+2; j++)
		{
			fprintf(fp,"%d",maze[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
 
	if (VistMaze(maze, path) == 0)
	{
		printf("没有路径可走\n");
		exit(0);
	}
 
	//打印出迷宫和路径
	for(i=0;i<Height+2;i++)
	{
		maze[0][i]=0;
		maze[i][0]=0;
		maze[Height+2][i]=0;
		maze[i][Width+2]=0;
	 } 
	printf("迷宫和路径：\n");
	printf("\n");
	for (i = 0; i < Height+2; i++)
	{
		for (j = 0; j < Width+2; j++)
		{
			if (maze[i][j] == 1)
				printf("■");
			else if (maze[i][j] == 3)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");
	FILE *fp1;
	char filename1[50];
	strcpy(filename1,"maze_path.txt");
	fp1=fopen(filename1,"wt+");
	for (i = 0; i < Height+2; i++)
	{
		for (j = 0; j < Width+2; j++)
		{
			fprintf(fp1,"%d",maze[i][j]);
		}
		fprintf(fp1,"\n");
	}
	fclose(fp1);
	return 0;
}

