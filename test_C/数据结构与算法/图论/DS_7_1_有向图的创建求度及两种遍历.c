#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 20
#define INFINITY 32767
typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;

void Create(AdjMatrix *G)
{
	int i,j,k,weight;
	char vex1,vex2;
	printf("�������������еĶ������ͱ�����\n");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
			G->arcs[i][j]=INFINITY;
	printf("��������������%d�����㣺\n",G->vexnum);
	for(i=1;i<=G->vexnum;i++)
	{
		printf("No.%d�����㣺����V",i);
		scanf("%d",&G->vex[i]); 
	}
	printf("��������������%d���ߣ�\n",G->arcnum);
	for(k=0;k<G->arcnum;k++)
	{
		printf("\nNo.%d���ߣ�\n     ����V",k+1);
		scanf("%c",&vex1);
		printf("<---->����V");
		scanf("%c",&vex2);
		printf("Ȩֵ��");
		scanf("%d",&weight);
		i=LocateVex(G,vex1);
		j=LocateVex(G,vex2);
		G->arcs[i][j]=weight;
		G->arcs[j][i]=weight; 
	}
 } 
 
void Print(AdjMatrix *G)
{
	int i=0;
	int j=0;
	for(i=0;i<G->arcnum;i++)
	{
		for(j=0;j<G->arcnum;j++)
		{
			printf("%d",G->arcs[i][j]);
		}
 		printf("\n");
	}
 } 

int main(void)
{
	AdjMatrix G;
	Create(&G);
	Print(&G); 
}
