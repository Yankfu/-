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
 
//���ڽӾ��󴴽�������
void Create(AdjMaTrix *G)
{
	int i,j,k,weight;
	char vex1,vex2;
	printf("�������������еĶ������ͱ�����");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
			G->arcs[i][j]=INFINITY;
	printf("��������������%d�����㣺\n"��G->vexnum);
	for(i=1;i<=G->vexnum;i++)
	{
		printf("No.%d�����㣺����v",i);
		scanf("%d",&G->vex[i]);
	 } 
	printf("��������������%d���ߣ�\n"��G->arcnum);
	for(k=0;k<G->arcnum;k++)
	{
		printf("\nNo.%d���ߣ�\n     ����V",k+1);
		scanf("%c",&vex1);
		printf("<--->����V");
		scanf("%c",&vex2);
		printf("Ȩֵ��");
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
