#include<stdio.h>
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
int main(void) 
