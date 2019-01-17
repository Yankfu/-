#include <stdio.h>
#include <stdlib.h>
#define INFINTE 65535
#define MAXSIZE 100
#include "queue.c"

typedef char VertexType;                //��������Ӧ���û�����
typedef int EdgeType;                   //���ϵ�Ȩֵ����Ӧ���û�����

typedef struct graph{
    VertexType vexs[MAXSIZE];            //�����
    EdgeType   arc[MAXSIZE][MAXSIZE];       //�ڽӾ���
    int numNodes, numEdges;
}Graph;

int visited[200];

void CreateGraph(Graph* graph); //����ͼ
VertexType* FirstAdjVex(Graph graph, VertexType data);  //��ȡ��һ�ڽӵ�
VertexType* NextAdjVex(Graph graph, VertexType data, VertexType adj);   //��ȡ��һ�ڽӵ�
void DFSTraversal(Graph graph); //������ȱ���
void BFSTraversal(Graph graph); //������ȱ���
void DFS(Graph graph, VertexType data); //�����������
void BFS(Graph graph, VertexType data); //�����������

int main(){
    int i, j;
    Graph graph;
    CreateGraph(&graph);
    //��ӡ�ڽӾ���
    for (i = 0; i < graph.numNodes; ++i){
        for (j = 0; j < graph.numNodes; ++j){
            printf("%d ", graph.arc[i][j]);
        }
        printf("\n");
    }

    VertexType* adj = FirstAdjVex(graph, 'A');
    VertexType x = *adj;
    printf("%c ", x);
    adj = NextAdjVex(graph, 'A', x);
    x = *adj;
    printf("%c ", x);
    x = *adj;
    adj = FirstAdjVex(graph, 'D');
    printf("%c\n", *adj);
    for (i = 0; i < 200; ++i){
        visited[i] = 0;
    }
    BFSTraversal(graph);
    printf("\n");
    for (i = 0; i < 200; ++i){  //���������ÿ�
        visited[i] = 0;
    }
    DFSTraversal(graph);
    return 0;
}

void CreateGraph(Graph* graph){
    int i, j;
    //�Ȱ�ͼ���ڽӾ�����Ϊ0(0��ʾû�ߣ�1��ʾ�б�)
    for (i = 0; i < graph->numNodes; ++i){
        for (j = 0; j < graph->numNodes; ++j){
            graph->arc[i][j] = 0;
        }
    }
    //printf("�����붥����, ������");
    //scanf("%d %d", &graph->numNodes, &graph->numEdges);
    //getchar();
    graph->numNodes = 6;
    graph->numEdges = 6;
    /*
    for (i = 0; i < graph->numNodes; ++i){
        printf("�����붥�㣺");
        scanf("%c", &graph->vexs[i]);
        getchar();  //�����հ׷�
    }
    */
    graph->vexs[0] = 'A';
    graph->vexs[1] = 'B';
    graph->vexs[2] = 'C';
    graph->vexs[3] = 'D';
    graph->vexs[4] = 'E';
    graph->vexs[5] = 'F';
    VertexType start, end;
    /*
    for (i = 0; i < graph->numEdges; ++i){
        printf("��������㣬 �յ㣺");
        scanf("%c %c", &start, &end);
        getchar();  //�����հ׷�
        int startIndex, endIndex;
        for (j = 0; j < graph->numNodes; ++j){  //�ҵ���ʼ��,�յ�
            if (start == graph->vexs[j]){
                startIndex = j;
            }
            if (end == graph->vexs[j]){
                endIndex = j;
            }
        }
        graph->arc[startIndex][endIndex] = 1;
        //���������ͼ����Ҫ˫�򱣴�
        graph->arc[endIndex][startIndex] = 1;
    }
    */
    graph->arc[0][2] = 1;
    graph->arc[0][3] = 1;
    graph->arc[3][1] = 1;
    graph->arc[2][4] = 1;
    graph->arc[3][5] = 1;
    graph->arc[4][5] = 1;
    //���������ͼ����Ҫ����������
    /*
    graph->arc[2][0] = 1;
    graph->arc[3][0] = 1;
    graph->arc[1][3] = 1;
    graph->arc[4][2] = 1;
    graph->arc[5][3] = 1;
    graph->arc[5][4] = 1;
    */

}


VertexType* FirstAdjVex(Graph graph, VertexType vex){
    //���ҵ�data������
    int i, j;
    for (i = 0; i < graph.numNodes; ++i){
        if (graph.vexs[i] == vex){
            for (j = 0; j < graph.numNodes; ++j){
                if (graph.arc[i][j] == 1){  //�ҵ���һ���ڽӵ�
                    return &(graph.vexs[j]);
                }
            }
        }
    }
    return NULL;    //�ⲽ˵��û�ҵ�
}


VertexType* NextAdjVex(Graph graph, VertexType vex, VertexType adj){
    int vexIndex, adjIndex, i;
    for (i = 0; i < graph.numNodes; ++i){
        if (graph.vexs[i] == vex){
            vexIndex = i;
        }
        if (graph.vexs[i] == adj){
            adjIndex = i;
        }
    }
    for (i = adjIndex + 1; i < graph.numNodes; ++i){  //�ӵ�ǰ�ڽӵ�ĺ���Ѱ��
        if (graph.arc[vexIndex][i] == 1){
            return &(graph.vexs[i]);
        }
    }
    return NULL;    //�ⲽ˵��û�ҵ�
}

/* ������ȱ��� */
void DFSTraversal(Graph graph){
    int i;
    for (i = 0; i < graph.numNodes; ++i){
        if (visited[graph.vexs[i]] != 1) {
            DFS(graph, graph.vexs[i]);
        }
    }
}

/* ������ȱ��� */
void BFSTraversal(Graph graph){
    int i;
    for (i = 0; i < graph.numNodes; ++i){
        if (visited[graph.vexs[i]] != 1) {
            DFS(graph, graph.vexs[i]);
        }
    }
}

/*
    �����������
*/
void BFS(Graph graph, VertexType vetex){
    Queue queue;
    InitQueue(&queue);
    EnQueue(&queue, vetex);
    VertexType adj;
    VertexType *p;
    visited[vetex] = 1;
    while (!IsEmpty(&queue)){
        DeQueue(&queue, &vetex);
        printf("%c ", vetex);
        for (p = FirstAdjVex(graph, vetex); p != NULL; p=NextAdjVex(graph, vetex, adj)){
            adj = *p; //Ӧ�ÿ���д��*p�����ǲ���
            if (visited[adj] != 1){
                EnQueue(&queue, adj);
                visited[adj] = 1;
            }
        }
    }
}

/*
    �����������
*/
void DFS(Graph graph, VertexType vex){
    visited[vex] = 1;
    printf("%c ", vex);
    VertexType *p;
    VertexType x;
    for (p = FirstAdjVex(graph, vex); p != NULL; p=NextAdjVex(graph, vex, x)){
        x = *p;
        if (visited[x] != 1){    //û���ʹ�
            DFS(graph, x);
        }
    }
}
