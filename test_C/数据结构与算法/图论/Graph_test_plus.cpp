#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define MAX 21
#define INFINITY 32767
#define TRUE 1
#define FALSE 0
 
typedef int Boole;  //布尔类型 存储TRUE FALSE
Boole visited[MAX];    //访问标志数组 
 
typedef int QElemType;    //链队列的数据类型 
typedef int Status; 
 
 
/*邻接矩阵结构*/ 
typedef struct
{
	char vex[MAX];   //顶点表 
	int arcs[MAX][MAX];   //邻接矩阵 可看作边表   
	int vexnum,arcnum;   //顶点数和边数 
}AdjMatrix;
 
/*队列结构*/
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
 
typedef struct
{
	QueuePtr front,rear;  //队头队尾指针 
}LinkQueue;
 
//创建空队列
Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(0);
	Q.front->next=NULL;
	return 1;	
} 
 
//入队列
//将s作为新元素加入队尾 
Status EnQueue(LinkQueue &Q,int i)
{
	QueuePtr s;
	s=(QueuePtr)malloc(sizeof(QNode));
	if(!s)
		exit(0);
	s->data=i;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	return 1;	
}
 
//检验是否为空
Status QueueEmpty(LinkQueue Q)
{
	if(Q.front->next==NULL)
		return 0;
	else
		return 1;	
 } 
 
//出队列
Status DeQueue(LinkQueue *Q,int *i)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return 0;
	p=Q->front->next;     //该写法值得商榷
						//相当于p储存第一个结点
	*i=p->data;
	Q->front->next=p->next;
	
	if(p==Q->rear)   //若队头是队尾	,删除后将rear指向头结点		
		Q->rear==Q->front;
	free(p);
	return 1;			
 } 
 
 
 
/*广度遍历*/ 
void BFSTraverse(AdjMatrix G)
{
 
	int i,j;
	LinkQueue Q;
	for(i=0;i<G.vexnum;i++)
		visited[i]=FALSE;
	InitQueue(Q);          //&的用法??     初始化队列    
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])    //未访问过 该顶点 
		{
			visited[i]=TRUE;
			printf("%c",G.vex[i]);
			EnQueue(Q,i);      //将其入队列 
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);    //将队中元素出队列，赋值给i 
				for(j=0;j<G.vexnum;j++)
				{
					if(G.arcs[i+1][j+1]==1&&!visited[j])      //其他顶点与该顶点存在边   且未访问过 
					{
						visited[j]=TRUE;
						printf("%c",G.vex[j]);
						EnQueue(Q,j);                 //入队列 
					}
					
				} 
			} 
		}
	}
} 
int main()
{
	AdjMatrix g;
	int i,j,k;
	char vex1,vex2;
	char ch;
	int count1,count2;

	scanf("%d",&g.vexnum);
	scanf("%d",&g.arcnum);


	for(i=1;i<=g.vexnum;i++)
		for(j=1;j<=g.vexnum;j++)
			g.arcs[i][j]=0;//把所有边置为0;

	getchar();
	gets(g.vex);

	for(k=1;k<=g.arcnum;k++)
	{
		scanf("%c",&vex1);
		vex2=getchar();
		for(i=1;i<=g.arcnum;i++)
			if(g.vex[i-1]==vex1) break;
		for(j=1;j<=g.arcnum;j++)
			if(g.vex[j-1]==vex2) break;
		g.arcs[i][j]=1;
		getchar();
	}
	
	//统计入度出度和度 
	for(i=1;i<=g.vexnum;i++)
	{
		count1=0;
		count2=0;
		
		for(k=1;k<=g.vexnum;k++)
		{
			if(g.arcs[i][k]==1) count1++;
		}
		
		for(j=1;j<=g.vexnum;j++)
		{
			if(g.arcs[j][i]==1) count2++;
		}
		
		printf("%c %d %d %d\n",g.vex[i-1],count1,count2,(count1+count2));
		
	}
	BFSTraverse(g); 
	return 0;	 
	
} 

