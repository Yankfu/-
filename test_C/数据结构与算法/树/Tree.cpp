#include<stdio.h>

#define N 6
#define M 2*N-1
#define MAX 100


typedef struct
{
	char SqBiTree[MAX+1];
	int nodemax;
}Bitree;


typedef struct Node
{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree;


typedef struct
{
	int weight;
	int parent,Lchild,Rchild;
}HTNode,HuffmanTree[M+1];


//先序递归遍历二叉树
void PreOrder(BiTree root)
{
	if(root)
	{
		Visit(root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
 } 
  
//中序递归遍历二叉树
void InOrder(BiTree root)
{
	if(root)
	{
		InOrder(root->Lchild);
		Visit(root->data);
		InOrder(root->Rchild);
	}
 } 

//后序递归遍历二叉树
void PostOrder(BiTree root)
{
	if(root)
	{
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		Visit(root->data);
	}
 } 

//先序非递归遍历二叉树 
void PreOrder(BiTree root)
{
	SeqStack *S;
	BiTree p;
	InitStack(S);
	p=root;
	while(p!=NULL || !IsEmpty(S))
	{
		while(p!=NULL)
		{
			Visit(p->data);
			Push(S,p);
			p=p->Lchild;
		}
		if(!IsEmpty(S))
		{
			Pop(S,&p);
			p=p->Rchild;
		}
	}
}

//中序非递归遍历二叉树 


//二叉树的层次遍历
void LevelOrder(BiTree root)
{
	SeqQueue *Q;
	BiTree p;
	InitQueue(Q);
	EnterQueue(Q,root);
	while(!IsEmpty(Q))
	{
		DeleteQueue(Q,&p);
		visit(p->data);
		if(p->Lchild!=NULL)
			EnterQueue(Q,p->Lchild);
		if(p->Rchild!=NULL)
			EnterQueue(Q,p->Rchild);
	}
 } 

//先序扩展序列创建二叉树
BiTree CreateBiTree()
{
	char ch;
	BiTree *s;
	ch=getchar()
	if(ch=='#')
		return NULL;
	else
	{
		s=(BiTree *s)malloc(sizeof(BiTreeNode));
		s->data=ch;
		s->Lchild=CreateBiTree();
		s->Rchild=CreateBiTree();
		return s;
	 } 
 }
  
//建立哈夫曼树 
void CrtHuffmanTree(HuffmanTree ht,int w[],int n)
{
	m=2*n-1;
	for(i=1;i<=n;i++)
	{
		ht[i].weight=w[i];
		ht[i].Lchild=0;
		ht[i].Rchild=0;
		ht[i].parent=0;	
	}
	for(i=n+1;i<=m;i++)
	{
		ht[i].weight=0;
		ht[i].Lchild=0;
		ht[i].Rchild=0;
		ht[i].parent=0;	
	}
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].Lchild=s1;
		ht[i].Rchild=s2;
		ht[s1].parent=i;
		ht[s2].parent=i;
	}
}

void select(HuffmanTree ht,int i,int *j,int *k)
{
	while(ht)
}




int main(void) 
{
	HuffmanTree ht;
	int weight[6];
	int i=0;
	for(i=0;i<=6;i++)
	{
		scanf("%d",weight[i]);
	}
	CrtHuffmanTree(ht,weight[6],6);
	
}
