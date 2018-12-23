#include <iostream>
using namespace std;
#define MAX_VERTEX 20

int visited[MAX_VERTEX] = { 0 };
typedef struct {
	int vertexnum;
	int arcnum;
	int arcs[MAX_VERTEX][MAX_VERTEX];
	char vertex[MAX_VERTEX];
}AdjMatrix;

void creatGragh(AdjMatrix *G)
{
	//cout << "输入图的顶点数和边数：" << endl;
	cin >> G->vertexnum >> G->arcnum;

	//cout << "输入顶点信息：" << endl;
	for (int i = 1; i <= G->vertexnum; i++)
	{
		cin >> G->vertex[i];
	}

	for (int i = 1; i <= G->vertexnum; i++)
	{//初始化邻接矩阵
		for (int j = 1; j <= G->vertexnum; j++)
		{
			G->arcs[i][j] = 0;
		}
	}

	//cout << "输入头和尾结点：" << endl;
	for (int i = 0; i < G->arcnum; i++)
	{
		int head = 0; int tail = 0;
		char chead; char ctail;
		cin >> chead >> ctail;
		for (int j = 1; j <= G->vertexnum; j++)
		{
			if (G->vertex[j] == chead)
			{
				head = j;
				for (int k = 1; k <= G->vertexnum; k++)
				{
					if (G->vertex[k] == ctail)
						tail = k;
				}
			}
		}
		G->arcs[head][tail] = 1;
		G->arcs[tail][head] = 1;
	}

}

void DFS(AdjMatrix *G, int start)
{
	//cout << G->vertex[start];
	visited[start] = 1;
	for (int i = 1; i <= G->vertexnum; i++)
	{
		if (G->arcs[start][i] == 1 && visited[i] == 0)
			DFS(G, i);
	}
}

int DFSTraverse(AdjMatrix *G)
{
	int count = 0;
	for (int i = 1; i <= G->vertexnum; i++)
		visited[i] = 0;
	for (int i = 1; i <= G->vertexnum; i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
			count++;
		}
	}
	return count;
}

int main() {
	AdjMatrix *G;
	G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	creatGragh(G);
	//showGragh(G);
	cout << DFSTraverse(G) << endl;
	return 0;
}
