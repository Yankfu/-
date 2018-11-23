#include<stdio.h>
#define MAXVEX 20
#define INFINITY 32767
typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
 } AdjMatrix;
 
//用邻接矩阵创建无向网
void Create(AdjMaTrix *G)
{
	int i,j,k,weight;
	char vex1,vex2;
	printf("请输入无向网中的顶点数和边数：");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
			G->arcs[i][j]=INFINITY;
	printf("请输入无向网中%d个顶点：\n"，G->vexnum);
	for(i=1;i<=G->vexnum;i++)
	{
		printf("No.%d个顶点：顶点v",i);
		scanf("%d",&G->vex[i]);
	 } 
	printf("请输入无向网中%d条边：\n"，G->arcnum);
	for(k=0;k<G->arcnum;k++)
	{
		printf("\nNo.%d条边：\n     顶点V",k+1);
		scanf("%c",&vex1);
		printf("<--->顶点V");
		scanf("%c",&vex2);
		printf("权值：");
		scanf("%d",&weight);
		i=LocateVex(G,vex1);                //????????????????????????????????????
		j=LocateVex(G,vex2);
		G->arcs[i][j]=weight;
		G->arcs[j][i]=weight;
	}
 } 
int LocateVex(AdiMatrix *G,char v)
{
	int i;
	for(i=1;i<=G->vexnum;i++)
		if(G->vex[i]==v)
			return i;
	return 0;
}
 
 
int main(void)
{
	AdjMaTrix *G;
	Create(G);
	return 0;
}
