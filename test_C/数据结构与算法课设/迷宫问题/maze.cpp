#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>


#define Height 11 //�Թ��ĸ߶ȣ�����Ϊ����
#define Width 11 //�Թ��Ŀ�ȣ�����Ϊ����
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

//����λ�ýṹ��
typedef struct local{
	
	int x;
	int y;
 
}LOCAL;
 
//ջ�ṹ
typedef struct stack{
	
	LOCAL data[MAXSIZE];
	int top;
 
}STACK;
 
//��ʼ��ջ
STACK *InitStack(void)
{
	STACK *map;
	map = (STACK *)malloc(sizeof(STACK));
	map->top = -1;
	
	return map;
}
 
//��ջ��
int EmptyStack(STACK *map)
{
	if (map->top == -1)
		return 1;
	else
		return 0;
}
 
//��ջ��
int IsFull(STACK *map)
{
	if (map->top == MAXSIZE - 1)
		return 1;
	else
		return 0;
 
}
 
//��ջ
int PushStack(STACK *map, LOCAL *x)
{
	if (map->top <= MAXSIZE - 1){
		map->data[++map->top] = *x;
		return 1;
	}
	else{
		printf("ջ����\n");
		return 0;
	}
}
 
//��ջ
int PopStack(STACK *map, LOCAL *x)
{
	if (map->top > -1){
		*x = map->data[map->top];
		map->top--;
		return 1;
	}
	else{
		printf("ջ�ѿ�\n");
		return 0;
	}
}
 
//���Թ�����
int VistMaze(int map[][Width], LOCAL path[][Width])
{
	int i, j;
 
	//��ʼ��ջ
	STACK *stack;
	LOCAL temp;
	stack = InitStack();
	temp.x = 0; temp.y = 0;
	if (map[START_I][START_J] == 0)//��ʼ 
		PushStack(stack, &temp);
	else
		return 0;
	while(!EmptyStack(stack)){
		PopStack(stack, &temp);
		i = temp.x;	j = temp.y;
		map[i][j] = 2;
 
		if (i == END_I && j == END_J)//���� 
			break;
 
		//��
		if (i + 1 <= END_I && map[i + 1][j] == 0){
			map[i + 1][j] = 2;
			path[i + 1][j].x = i;	path[i + 1][j].y = j;
			temp.x = i + 1;
			temp.y = j;
			PushStack(stack, &temp);
		}
		//��
		if (j + 1 <= END_J && map[i][j + 1] == 0){
			map[i][j + 1] = 2;
			path[i][j + 1].x = i;	path[i][j + 1].y = j;
			temp.x = i;
			temp.y = j + 1;
			PushStack(stack, &temp);
		}
		//��
		if (j - 1 >= 0 && map[i][j - 1] == 0){
			map[i][j - 1] = 2;
			path[i][j - 1].x = i;	path[i][j - 1].y = j;
			temp.x = i;
			temp.y = j - 1;
			PushStack(stack, &temp);
		}
		//��
		if (i - 1 >= 0 && map[i - 1][j] == 0){
			map[i - 1][j] = 2;
			path[i - 1][j].x = i;	path[i - 1][j].y = j;
			temp.x = i - 1;
			temp.y = j;
			PushStack(stack, &temp);
		}
	}
	//��������յ���˳���ѭ����·����ʶ����
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
void gotoxy(int x,int y)//�ƶ����� 
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
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
    map[x][y]=Road;
    for(i=0;i<4;i++)
    if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall)
    {
        map[x+c[i][0]][y+c[i][1]]=Road;
        create(x+2*c[i][0],y+2*c[i][1]);
    }
}
void paint(int x,int y) //���Թ�
{
    gotoxy(2*y-2,x-1);
    switch(map[x][y])
    {
        case Start:
        printf("��");break; //�����
        case End:
        printf("��");break; //������
        case Wall:
        printf("�~");break; //��ǽ
        case Road:
        printf(" ");break; //��·
    }
}


int main()
{


    int i,j;
    srand((unsigned)time(NULL)); //��ʼ���漴����

    for(i=0;i<=Height+1;i++)
    	for(j=0;j<=Width+1;j++)
    		if(i==0||i==Height+1||j==0||j==Width+1) //��ʼ���Թ�
    			map[i][j]=Road;
    		else map[i][j]=Wall;
 
    create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //�����һ���㿪ʼ�����Թ����õ����ж�Ϊż��


	for(i=0;i<=Height+1;i++) //�߽紦�� 
    {
        map[i][0]=Wall;
        map[i][Width+1]=Wall;
    }
 
    for(j=0;j<=Width+1;j++) //�߽紦��
    {
        map[0][j]=Wall;
        map[Height+1][j]=Wall;
    }
    map[2][1]=Start; //�������
    map[Height-1][Width]=End; //��������
    
	

    for(i=1;i<=Height;i++)
    {
		for(j=1;j<=Width;j++) //�����Թ�
    	{
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
    for(i=1;i<=Height;i++)
    	for(j=1;j<=Width;j++) //�����Թ�
    		paint(i,j);

	LOCAL path[Height][Width];
	for(i = 0; i < Height; i++){
		for(j = 0; j < Width; j++){
			path[i][j].x = -1;
			path[i][j].y = -1;
		}
	}
	if (VistMaze(map, path) == 0){
		printf("û��·������\n");
		exit(0);
	}
 
	//��ӡ���Թ���·��
	printf("�Թ���·����\n");
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
