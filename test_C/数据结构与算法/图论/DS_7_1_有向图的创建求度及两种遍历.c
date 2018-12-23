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
	printf("请输入无向网中的顶点数和边数：\n");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
			G->arcs[i][j]=INFINITY;
	printf("请输入无向网中%d个顶点：\n",G->vexnum);
	for(i=1;i<=G->vexnum;i++)
	{
		printf("No.%d个顶点：顶点V",i);
		scanf("%d",&G->vex[i]); 
	}
	printf("请输入无向网中%d条边：\n",G->arcnum);
	for(k=0;k<G->arcnum;k++)
	{
		printf("\nNo.%d条边：\n     顶点V",k+1);
		scanf("%c",&vex1);
		printf("<---->顶点V");
		scanf("%c",&vex2);
		printf("权值：");
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
