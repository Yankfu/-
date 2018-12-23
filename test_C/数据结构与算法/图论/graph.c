#define MAXVEX 20
#define INFINITY 32767
typedef struct
{
	int vexnum;
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];//
	int arcnum;
	int visitedBFS[MAXVEX];
	int visitedDFS[MAXVEX]; 
}AdjMatrix;

//7.1
void Create(AdjMatrix *G)
{
	int i,j,k,weight;
	char vex1,vex2;
	printf("请输入无向网中的顶点数和边数：\n");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
			G->arcs[i][j]=INFINITY;
	printf("请输入无向网中%d个顶点：\n".G->vexnum);
	for(i=1;i<=G->vexnum;i++)
	{
		printf("No.%d个顶点：顶点V"，i)；
		scanf("%d",&G->vex[i]); 
	}
	printf("请输入无向网中%d条边：\n"，G->arcnum);
	for(k=0;k<G->arcnum;k++)
	{
		printf("\nNo.%d条边：\n     顶点V",k+1);
		scanf("%c",&vex1);
		printf("<---->顶点V")；
		scanf("%c",&vex2);
		printf("权值：")；
		scanf("%d",&weight);
		i=LocateVex(G,vex1);
		j=LocateVex(G,vex2);
		G->arcs[i][j]=weight;
		G->arcs[j][i]=weight; 
	}
 } 
 
int LocateVex(AdjMatrix *G,char v)
{
	int i;
	for(i=1;i<=G->vexnum;i++)
		if(G->vex[i]==v)
			return i;
	return 0;
}
 

//7.2
int visited[MAXVEX]={0};
void DFS_D(Graph g,int v0)
{
	visit(v0);
	visited[v0]=1;
	w=FirstAdjVex(g,v0);
	while(w!=-1)
	{
		if(!visited[w]) DFS_D(g,w);
		w=NextAdjVex(g,v0,w);
	}
 }  
void TraverseG(Graph g)
{
	for(v=0;v<g.vexnum;v++)
		visited[v]=0;
	for(v=0;v<g.vexnum;v++)
		if(!visited[v]) DFS_D(g,v);
}

void DFS(AdjMatrix G,int i)
{
	SeqStack S;
	S=InitStack();
	Push(S,i);
	int v;
	while(!Empty(S))
	{
		v=Pop(S);
		if(!g.visitedDFS[v])
		{
			printf("%c\n",g.vex[v]);
			g.visitedDFS[v]=1;
		}
		for(i=1;i<=g.vexnum;i++)
		{
			if(g.arcs[v+1][i]==1 && g.visitedDFS[i-1]==0)
			{
				w=i-1;
				break; 
			}
		}
		while(w!=-1)
		{
			if(!g.visitedDFS[w]) Push(S,w);
			w=NextAdjVex(g,v,w);
		}
	}
}

	for(i=1;i<=g.vexnum;i++)
	{
		if(g.arcs[v][i]==1 && g.visitedDFS[i-1]==0)
		{
			w=i-1;
			break;
		}
		else if(g.arcs[v][i]==1 && g.visitedDFS[i-1]==1)
		{
			continue;
		}
	}


//7.5
void BFS(Graph g,int v0)
{
	visit(v0);
	visited[v0]=1;
	InitQueue(&Q);
	EnterQueue(&Q,v0);
	while(!Empty(Q))
	{
		DeletQueue(&Q,&v);
		w=FirstAdjVex(g,v);
		while(w!=-1)
		{
			if(!visited(w))
			{
				visit(w);
				visited[w]=1;
				EnterQueue(&Q,w);
			}
			w=NextAdjVex(g,v,w);
		}
	}
} 

//7.6
void TraverseG(Graph g)
{
	for(v=0;v<g.vexnum;v++)
	{
		visited[v]=0;
	}
	for(v=0;v<g.vexnum;v++)
	{
		if(!visited[v])
			BFS(g.v);
	}
}



//7.7 Prim算法求得最小生成树
void 
