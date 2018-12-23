#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


#define MAXVEX 21
//#define INFINITY 32767
#define TRUE 1
#define FALSE 0


typedef char VertexType;
typedef int EdgeType;
typedef int QElemType;    //链队列的数据类型 
typedef int Status;
typedef int Boole;  //布尔类型 存储TRUE FALSE
Boole visited[21];    //访问标志数组
typedef struct
{
	int vexnum;
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];//
	int arcnum;
}AdjMatrix;


typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
 
typedef struct
{
	QueuePtr front,rear;  //队头队尾指针 
}LinkQueue;

void DFStraverse(AdjMatrix G);
void DFS(AdjMatrix G,int i);

int main(void)
{
	AdjMatrix g;
	int i,j,k;
	char vex1,vex2;
	char ch;
	int a,b;
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
	
//	//统计入度出度和度 
//	for(i=1;i<=g.vexnum;i++)
//	{
//		count1=0;
//		count2=0;
//		
//		for(k=1;k<=g.vexnum;k++)
//		{
//			if(g.arcs[i][k]==1) count1++;
//		}
//		
//		for(j=1;j<=g.vexnum;j++)
//		{
//			if(g.arcs[j][i]==1) count2++;
//		}
//		
//		printf("%c %d %d %d\n",g.vex[i-1],count1,count2,(count1+count2));
//		
//	}

	
//	for(a=1;a<=g.vexnum;a++)
//	{
//		for(b=1;b<=g.vexnum;b++)
//		{
//			printf("%d ",g.arcs[a][b]);
//		}
//		printf("\n");
//	}
	
	DFStraverse(g); 
	printf("\n");
	
	return 0;
}

void DFS(AdjMatrix G,int i)
{
	int j;
	visited[i]=TRUE;   //被访问的标记 
//	printf("%c",G.vex[i]);
	for(j=1;j<=G.vexnum;j++)
	{
		if(G.arcs[i+1][j]==1&&!visited[j])   //边(i,j)存在且j顶点未被访问，递归 
			DFS(G,j-1);
	} 
}
//深度优先遍历
void DFStraverse(AdjMatrix G)
{
	int count=0;
	int i;
	for(i=0;i<G.vexnum;i++)
		visited[i]=FALSE;
	for(i=0;i<G.vexnum;i++)
			if(!visited[i])
			{ 
				DFS(G,i);
				count++;		
			}
	printf("%d",count);
}
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
 
 
 
///*广度遍历*/ 
//void BFSTraverse(AdjMatrix G)
//{
// 
//	int i,j;
//	LinkQueue Q;
//	for(i=0;i<G.vexnum;i++)
//		visited[i]=FALSE;
//	InitQueue(Q);          //&的用法??     初始化队列    
//	for(i=0;i<G.vexnum;i++)
//	{
//		if(!visited[i])    //未访问过 该顶点 
//		{
//			visited[i]=TRUE;
//			printf("%c",G.vex[i]);
//			EnQueue(Q,i);      //将其入队列 
//			while(!QueueEmpty(Q))
//			{
//				DeQueue(&Q,&i);    //将队中元素出队列，赋值给i 
//				for(j=1;j<=G.vexnum;j++)
//				{
//					if(G.arcs[i+1][j]==1&&!visited[j])      //其他顶点与该顶点存在边   且未访问过 
//					{
//						visited[j]=TRUE;
//						printf("%c",G.vex[j-1]);
//						EnQueue(Q,j-1);                 //入队列 
//					}
//					
//				} 
//			} 
//		}
//	}
//}
/*
//int flag=0;
void DFS(AdjMatrix G,int i)
{
//	flag++;
//	printf("%d",flag);
	SeqStack S;
	AdjMatrix g=G;
	S=InitSeqStack();
	int j=0;
	int k=0;
	int a,b,c;
	
	Push(&S,i);
		
	printf("%c\n",g.vex[i]);
	g.visitedDFS[i]=1;

	for(j=1;j<=g.vexnum;j++)
	{
		printf("%d ",g.arcs[i+1][j]);
		if(g.arcs[i+1][j]==1 && g.visitedDFS[j-1]==0)
		{
			printf("%c\n",g.vex[j-1]);
			g.visitedDFS[j-1]=1;
			Push(&S,j-1);
			break;
		}
		else if(g.arcs[i+1][j]==1 && g.visitedDFS[j-1]==1)
		{
			continue;
		}
		else if(g.arcs[i+1][g.vexnum]==0)
		{
			i=Pop(&S);
		}
	}
	i=j;
	j=1;
	printf("这是i:%d,这是j：%d，这是g.vexnum:%d \n",i,j,g.vexnum);
	for(j=1;j<=g.vexnum;j++)
	{
//		printf("%d  ",g.arcs[2][1]);
//		printf("%d  ",g.arcs[2][2]);
//		printf("%d  ",g.arcs[2][3]);
//		printf("%d  ",g.arcs[2][4]);
//		printf("%d  \n",g.arcs[2][5]);
		printf("%d  ",g.arcs[2][j]);
		if(g.arcs[i][j]==1 && g.visitedDFS[j-1]==0)
		{
			printf("%c\n",g.vex[j-1]);
			g.visitedDFS[j-1]=1;
			Push(&S,j-1);
			i=j-1;
			break;
		}
		else if(g.arcs[i][j]==1 && g.visitedDFS[j-1]==1)
		{
			continue;
		}
		else if(g.arcs[i][g.vexnum]==0)
		{
			i=Pop(&S);
		}
		j++;
	}
	printf("这是i：：：%d \n",i);
	for(j=1;j<=g.vexnum;j++)
	{
		printf("%d ",g.arcs[i+1][j]);
		if(g.arcs[i+1][j]==1 && g.visitedDFS[j-1]==0)
		{
			printf("%c\n",g.vex[j-1]);
			g.visitedDFS[j-1]=1;
			Push(&S,j-1);
			i=j-1;
			break;
		}
		else if(g.arcs[i+1][j]==1 && g.visitedDFS[j-1]==1)
		{
			continue;
		}
		else if(g.arcs[i+1][g.vexnum]==0)
		{
			i=Pop(&S);
		}
	}
}
void BFS(AdjMatrix G,int i)
{
	AdjMatrix g=G;
	
}*/
