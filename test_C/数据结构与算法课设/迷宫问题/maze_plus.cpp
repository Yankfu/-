#include <stdio.h>
#include <stdlib.h>
 
typedef struct n
{
	int i;
	int j;
	int f;
	struct n* next;
}link;
//���� 
link* init(){
	link* l = (link*)malloc(sizeof(link));
	l->i=0;
	l->j=0;
	l->f=0;
	l->next=NULL;
	return l;
}
link* l;
//�пղ��� 
int isEmpty(link *l){
	if(l->next==NULL)
		return 1;
	return 0;
}
//��ջ���� :ͷ�巨 
void ru(link *l,int i,int j,int f){
	link *p = (link*)malloc(sizeof(link));
	p->i=i;
	p->j=j;
	p->f=f;
	p->next=l->next;
	l->next=p;
}
//��ջ���� 
int chu(link* l){
	if(isEmpty(l))
		return 0;
	link* p=l->next;
	l->next=l->next->next;
	free(p);
	return 1;
}
//�㷨 
int VistMaze(int maze[][100],int endi,int endj,int starti,int startj, int i, int j)
{
	int end = 0;//end==flag,1Ϊ�ѳ��Թ���0Ϊδ�� 
	maze[i][j] = 2;
	if (i == endi && j == endj){
		end = 1;
	}
	if (end != 1 && j + 1 <= endj && maze[i][j + 1] == 0){		//��
		ru(l,i,j,1);
		if (VistMaze(maze,endi,endj,starti,startj, i, j + 1) == 1)
			return 1;
	}
	if (end != 1 && i + 1 <= endi && maze[i + 1][j] == 0){		//��
		ru(l,i,j,2);
		if (VistMaze(maze,endi,endj,starti,startj, i + 1, j) == 1)
			return 1;
	}
	if (end != 1 && j - 1 >= startj && maze[i][j - 1] == 0){	//��
		ru(l,i,j,3);
		if (VistMaze(maze,endi,endj,starti,startj, i, j - 1) == 1)
			return 1;
	}
	if (end != 1 && i - 1 >= starti && maze[i - 1][j] == 0){	//��
		ru(l,i,j,4);
		if (VistMaze(maze,endi,endj,starti,startj, i - 1, j) == 1)
			return 1;
	}
	//����һ���ĸ��������Ϊǽʱ����������Ϊ0ͨ·������һ����2ȥ̽����һ��ͨ· 
	if (end != 1){
		maze[i][j] = 0;
		chu(l);
	}
	return end;
}
//������� 
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
			scanf("%1d",&a[q][w]);//��Ϊ���벻�ܴ��ո�����ÿ��������ʱ��ȡһ���ַ� 
		}
	}
	printf("���·����\n");
	if(VistMaze(a,i,j,1,1,1,1) == 1){
		ru(l,i,j,0);//�����if�ѽ������һ�����������ͨ·ȫ����ջ����һ����ͨ·���һ��������ջ
		
		show(l);
	}
}

