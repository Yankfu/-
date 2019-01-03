#include <stdio.h>
#include <stdlib.h>
 
typedef struct n
{
	int i;
	int j;
	int f;
	struct n* next;
}link;
//创建 
link* init(){
	link* l = (link*)malloc(sizeof(link));
	l->i=0;
	l->j=0;
	l->f=0;
	l->next=NULL;
	return l;
}
link* l;
//判空操作 
int isEmpty(link *l){
	if(l->next==NULL)
		return 1;
	return 0;
}
//入栈操作 :头插法 
void ru(link *l,int i,int j,int f){
	link *p = (link*)malloc(sizeof(link));
	p->i=i;
	p->j=j;
	p->f=f;
	p->next=l->next;
	l->next=p;
}
//出栈操作 
int chu(link* l){
	if(isEmpty(l))
		return 0;
	link* p=l->next;
	l->next=l->next->next;
	free(p);
	return 1;
}
//算法 
int VistMaze(int maze[][100],int endi,int endj,int starti,int startj, int i, int j)
{
	int end = 0;//end==flag,1为已出迷宫，0为未出 
	maze[i][j] = 2;
	if (i == endi && j == endj){
		end = 1;
	}
	if (end != 1 && j + 1 <= endj && maze[i][j + 1] == 0){		//右
		ru(l,i,j,1);
		if (VistMaze(maze,endi,endj,starti,startj, i, j + 1) == 1)
			return 1;
	}
	if (end != 1 && i + 1 <= endi && maze[i + 1][j] == 0){		//下
		ru(l,i,j,2);
		if (VistMaze(maze,endi,endj,starti,startj, i + 1, j) == 1)
			return 1;
	}
	if (end != 1 && j - 1 >= startj && maze[i][j - 1] == 0){	//左
		ru(l,i,j,3);
		if (VistMaze(maze,endi,endj,starti,startj, i, j - 1) == 1)
			return 1;
	}
	if (end != 1 && i - 1 >= starti && maze[i - 1][j] == 0){	//上
		ru(l,i,j,4);
		if (VistMaze(maze,endi,endj,starti,startj, i - 1, j) == 1)
			return 1;
	}
	//当下一步的各个方向均为墙时，将本部设为0通路，由上一步的2去探索下一个通路 
	if (end != 1){
		maze[i][j] = 0;
		chu(l);
	}
	return end;
}
//输出函数 
void show(link* l){
	if(l->next)
		show(l->next); 
	if(l->i)
		printf("(%d,%d,%d)",l->i,l->j,l->f);
}
int main(void)
{
	int i,j;
	int q,w; 
//	link* l;
	l = init();
	scanf("%d %d",&i,&j);
	int a[100][100];
	for(q=1;q<=i;q++){
		for(w=1;w<=j;w++){
			scanf("%1d",&a[q][w]);//因为输入不能带空格，所以每次在输入时截取一个字符 
		}
	}
	printf("输出路径：\n");
	if(VistMaze(a,i,j,1,1,1,1) == 1){
		ru(l,i,j,0);//上面的if已将除最后一步以外的所有通路全部入栈，这一步将通路最后一步单独入栈
		
		show(l);
	}
}

