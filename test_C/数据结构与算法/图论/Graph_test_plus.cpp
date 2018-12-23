#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define MAX 21
#define INFINITY 32767
#define TRUE 1
#define FALSE 0
 
typedef int Boole;  //�������� �洢TRUE FALSE
Boole visited[MAX];    //���ʱ�־���� 
 
typedef int QElemType;    //�����е��������� 
typedef int Status; 
 
 
/*�ڽӾ���ṹ*/ 
typedef struct
{
	char vex[MAX];   //����� 
	int arcs[MAX][MAX];   //�ڽӾ��� �ɿ����߱�   
	int vexnum,arcnum;   //�������ͱ��� 
}AdjMatrix;
 
/*���нṹ*/
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
 
typedef struct
{
	QueuePtr front,rear;  //��ͷ��βָ�� 
}LinkQueue;
 
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
 
 
 
/*��ȱ���*/ 
void BFSTraverse(AdjMatrix G)
{
 
	int i,j;
	LinkQueue Q;
	for(i=0;i<G.vexnum;i++)
		visited[i]=FALSE;
	InitQueue(Q);          //&���÷�??     ��ʼ������    
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])    //δ���ʹ� �ö��� 
		{
			visited[i]=TRUE;
			printf("%c",G.vex[i]);
			EnQueue(Q,i);      //��������� 
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);    //������Ԫ�س����У���ֵ��i 
				for(j=0;j<G.vexnum;j++)
				{
					if(G.arcs[i+1][j+1]==1&&!visited[j])      //����������ö�����ڱ�   ��δ���ʹ� 
					{
						visited[j]=TRUE;
						printf("%c",G.vex[j]);
						EnQueue(Q,j);                 //����� 
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
	
	//ͳ����ȳ��ȺͶ� 
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

