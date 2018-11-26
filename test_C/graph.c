#define MAXVEX 20
#define INFINITY 32767
typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;

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


