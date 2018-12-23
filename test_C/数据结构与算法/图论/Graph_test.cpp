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
typedef int QElemType;    //�����е��������� 
typedef int Status;
typedef int Boole;  //�������� �洢TRUE FALSE
Boole visited[21];    //���ʱ�־����
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
	QueuePtr front,rear;  //��ͷ��βָ�� 
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
			g.arcs[i][j]=0;//�����б���Ϊ0;

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
	
//	//ͳ����ȳ��ȺͶ� 
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
	visited[i]=TRUE;   //�����ʵı�� 
//	printf("%c",G.vex[i]);
	for(j=1;j<=G.vexnum;j++)
	{
		if(G.arcs[i+1][j]==1&&!visited[j])   //��(i,j)������j����δ�����ʣ��ݹ� 
			DFS(G,j-1);
	} 
}
//������ȱ���
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
//�����ն���
Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(0);
	Q.front->next=NULL;
	return 1;	
} 
 
//�����
//��s��Ϊ��Ԫ�ؼ����β 
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
 
//�����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q)
{
	if(Q.front->next==NULL)
		return 0;
	else
		return 1;	
 } 
 
//������
Status DeQueue(LinkQueue *Q,int *i)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return 0;
	p=Q->front->next;     //��д��ֵ����ȶ
						//�൱��p�����һ�����
	*i=p->data;
	Q->front->next=p->next;
	
	if(p==Q->rear)   //����ͷ�Ƕ�β	,ɾ����rearָ��ͷ���		
		Q->rear==Q->front;
	free(p);
	return 1;			
 } 
 
 
 
///*��ȱ���*/ 
//void BFSTraverse(AdjMatrix G)
//{
// 
//	int i,j;
//	LinkQueue Q;
//	for(i=0;i<G.vexnum;i++)
//		visited[i]=FALSE;
//	InitQueue(Q);          //&���÷�??     ��ʼ������    
//	for(i=0;i<G.vexnum;i++)
//	{
//		if(!visited[i])    //δ���ʹ� �ö��� 
//		{
//			visited[i]=TRUE;
//			printf("%c",G.vex[i]);
//			EnQueue(Q,i);      //��������� 
//			while(!QueueEmpty(Q))
//			{
//				DeQueue(&Q,&i);    //������Ԫ�س����У���ֵ��i 
//				for(j=1;j<=G.vexnum;j++)
//				{
//					if(G.arcs[i+1][j]==1&&!visited[j])      //����������ö�����ڱ�   ��δ���ʹ� 
//					{
//						visited[j]=TRUE;
//						printf("%c",G.vex[j-1]);
//						EnQueue(Q,j-1);                 //����� 
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
	printf("����i:%d,����j��%d������g.vexnum:%d \n",i,j,g.vexnum);
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
	printf("����i������%d \n",i);
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
