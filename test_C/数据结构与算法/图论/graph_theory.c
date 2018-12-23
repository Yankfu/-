 
//代码可直接运行
#include <stdio.h>
#include <stdlib.h>
 
#define maxsize 100
 
typedef struct ArcNode {
    int num;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode{
    ArcNode *firstarc;
}VNode;
typedef struct Graph {
    VNode VNodeList[maxsize];
    int n,e;
}Graph;
 
void bulidGraph(Graph *g);
 
int visitdfs[maxsize];
void DFS(Graph *g ,int v);
void dfs(Graph *g);
 
int visit[maxsize];
void bfs(Graph *g);
void BFS(Graph *g ,int v);
 
int main()
{
    Graph *g;
    g=(Graph *) malloc(sizeof(Graph));
    bulidGraph(g);
 
    dfs(g);
    printf("\n");
    bfs(g);
    return 0;
}
 
void DFS(Graph *g ,int v)
{
    ArcNode *p=g->VNodeList[v].firstarc;
    visitdfs[v]=1;
    printf("%d",v);
    while (p!=NULL){
        if(visitdfs[p->num]==0)
        DFS(g,p->num);
        p=p->next;
    }
}
void dfs(Graph *g){
	int i;
    for(i=0;i<g->n;i++){
        if(visitdfs[i]==0)
            DFS(g,i);
    }
}
 
void BFS(Graph *g,int v){
    ArcNode *p ;
    int que [maxsize], top=0,rear=0;
    int j;
    printf("%d",v);
    visit[v]=1;
    rear =(rear+1)%maxsize;
    que[rear]=v;
    while(top!=rear){
        top =(top+1)%maxsize;
        j=que[top];
        p=g->VNodeList[j].firstarc;
        while (p!=NULL){
            if(visit[p->num]==0){
                printf("%d",p->num);
                visit[p->num]=1;
                rear=(rear+1)%maxsize;
                que[rear]=p->num;
 
                }
                p=p->next;
        }
    }
}
void bfs(Graph *g){
	int i;
    for(i=0;i<g->n;i++){
        if(visit[i]==0)
            BFS(g,i);
    }
}
 
void bulidGraph(Graph *g){
    g->n=6;
    g->e=7;
 
    VNode v0,v1 ,v2, v3 ,v4 ,v5,v6;
    ArcNode *v01,*v03,*v04,*v14,*v12,*v20,*v32,*v56;
 
    v01=(ArcNode *) malloc(sizeof(ArcNode));
    v01->num=1;
    v03=(ArcNode *) malloc(sizeof(ArcNode));
    v03->num=3;
    v04=(ArcNode *) malloc(sizeof(ArcNode));
    v04->num=4;
    v14=(ArcNode *) malloc(sizeof(ArcNode));
    v14->num=4;
    v12=(ArcNode *) malloc(sizeof(ArcNode));
    v12->num=2;
    v20=(ArcNode *) malloc(sizeof(ArcNode));
    v20->num=0;
    v32=(ArcNode *) malloc(sizeof(ArcNode));
    v32->num=2;
    v56=(ArcNode *) malloc(sizeof(ArcNode));
    v56->num=6;
 
    v0.firstarc=v01;
    v1.firstarc=v14;
    v2.firstarc=v20;
    v3.firstarc=v32;
    v4.firstarc=NULL;
    v5.firstarc=v56;
    v6.firstarc=NULL;
 
    v01->next=v03;
    v03->next=v04;
    v14->next=v12;
    v32->next=NULL;
    v20->next=NULL;
    v12->next=NULL;
    v04->next=NULL;
    v56->next=NULL;
 
    g->VNodeList[0]=v0;
    g->VNodeList[1]=v1;
    g->VNodeList[2]=v2;
    g->VNodeList[3]=v3;
    g->VNodeList[4]=v4;
    g->VNodeList[5]=v5;
    g->VNodeList[6]=v6;
 
}

