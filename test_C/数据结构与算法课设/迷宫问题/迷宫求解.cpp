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
 
//����λ�ýṹ��
typedef struct local
{	
	int x;
	int y;
 
}LOCAL;
int maze[Height+2][Width+2];
//ջ�ṹ
typedef struct stack
{
	
	LOCAL data[MAXSIZE];
	int top;
 
}STACK;
 
//��ʼ��ջ
STACK *InitStack(void)
{
	STACK *maze;
	maze = (STACK *)malloc(sizeof(STACK));
	maze->top = -1;
	
	return maze;
}
 
//��ջ��
int EmptyStack(STACK *maze)
{
	if (maze->top == -1)
		return 1;
	else
		return 0;
}
 
//��ջ��
int IsFull(STACK *maze)
{
	if (maze->top == MAXSIZE - 1)
		return 1;
	else
		return 0;
 
}
 
//��ջ
int PushStack(STACK *maze, LOCAL *x)
{
	if (maze->top <= MAXSIZE - 1)
	{
		maze->data[++maze->top] = *x;
		return 1;
	}
	else
	{
		printf("ջ����\n");
		return 0;
	}
}
 
//��ջ
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
		printf("ջ�ѿ�\n");
		return 0;
	}
}
 
//���Թ�����
int VistMaze(int maze[][Width+2], LOCAL path[][Width+2])
{
	int i, j;
 
	//��ʼ��ջ
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
 
		//��
		if (i + 1 <= END_I && maze[i + 1][j] == 0)
		{
			maze[i + 1][j] = 2;
			path[i + 1][j].x = i;
			path[i + 1][j].y = j;
			temp.x = i + 1;
			temp.y = j;
			PushStack(stack, &temp);
		}
		//��
		if (j + 1 <= END_J && maze[i][j + 1] == 0)
		{
			maze[i][j + 1] = 2;
			path[i][j + 1].x = i;	
			path[i][j + 1].y = j;
			temp.x = i;
			temp.y = j + 1;
			PushStack(stack, &temp);
		}
		//��
		if (j - 1 >= 0 && maze[i][j - 1] == 0)
		{
			maze[i][j - 1] = 2;
			path[i][j - 1].x = i;	
			path[i][j - 1].y = j;
			temp.x = i;
			temp.y = j - 1;
			PushStack(stack, &temp);
		}
		//��
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
	//��������յ���˳���ѭ����·����ʶ����
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
 
void create(int x,int y) //��������Թ�
{
    int c[4][2]={0,1,1,0,0,-1,-1,0}; //�ĸ�����
    int i,j,t;
    //���������
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
	//�Թ�
	int i, j;
	
	//��������Թ� 
	{ 
	srand((unsigned)time(NULL));
		
	for(i=0;i<=Height+1;i++)
    	for(j=0;j<=Width+1;j++)
    		if(i==0||i==Height+1||j==0||j==Width+1) //��ʼ���Թ�
    			maze[i][j]=Road;
    		else maze[i][j]=Wall;
 
    create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //�����һ���㿪ʼ�����Թ����õ����ж�Ϊż��
//    for(i=0;i<=Height+1;i++) //�߽紦�� 
//    {
//        maze[i][0]=Wall;
//        maze[i][Width+1]=Wall;
//    }
// 
//    for(j=0;j<=Width+1;j++) //�߽紦��
//    {
//        maze[0][j]=Wall;
//        maze[Height+1][j]=Wall;
//    }
	} 
	

	//����·������,����(x,y)���·�����������
	LOCAL path[Height+2][Width+2];
	for(i = 0; i < Height+2; i++)
	{
		for(j = 0; j < Width+2; j++)
		{
			path[i][j].x = -1;
			path[i][j].y = -1;
		}
	}
 
	//��ӡ���Թ�
	maze[2][1]=0;
	maze[Height-1][Width]=0;
	printf("ԭ�Թ���\n");
	printf("\n");
	for (i = 0; i < Height+2; i++)
	{
		for (j = 0; j < Width+2; j++)
		{
			if (maze[i][j] == 1)
				printf("��");
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
		printf("û��·������\n");
		exit(0);
	}
 
	//��ӡ���Թ���·��
	for(i=0;i<Height+2;i++)
	{
		maze[0][i]=0;
		maze[i][0]=0;
		maze[Height+2][i]=0;
		maze[i][Width+2]=0;
	 } 
	printf("�Թ���·����\n");
	printf("\n");
	for (i = 0; i < Height+2; i++)
	{
		for (j = 0; j < Width+2; j++)
		{
			if (maze[i][j] == 1)
				printf("��");
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

