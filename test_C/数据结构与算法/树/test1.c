#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct Node
{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree()
{
	char ch;
	BiTree s;
	ch=getchar();
	if(ch=='#')
		return NULL;
	else
	{
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=ch;
		s->Lchild=CreateBiTree();
		s->Rchild=CreateBiTree();
		return s;
	 } 
 }
 
void exchange(BiTree root)
{
	BiTree p=root;
	BiTree x;
	if(p->Lchild!=NULL||p->Rchild!=NULL)
	{
		exchange(p->Lchild);
		exchange(p->Rchild);
		x->Lchild=p->Lchild;
		p->Lchild=p->Rchild;
		p->Rchild=x->Lchild;
	}
 } 
 
//ÏÈÐòµÝ¹é±éÀú¶þ²æÊ÷
void PreOrder(BiTree root)
{
	if(root)
	{
		printf("%c",root->data);
		Visit(root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
 } 
  
//ÖÐÐòµÝ¹é±éÀú¶þ²æÊ÷
void InOrder(BiTree root)
{
	if(root)
	{
		printf("%c",root->data);
		InOrder(root->Lchild);
		Visit(root->data);
		InOrder(root->Rchild);
	}
 } 

//ºóÐòµÝ¹é±éÀú¶þ²æÊ÷
void PostOrder(BiTree root)
{
	if(root)
	{
		printf("%c",root->data);
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		Visit(root->data);
	}
 } 
 
int main(void)
{
	BiTree root;
	root=CreateBiTree();
	exchange(root);
	PreOrder(root);
	InOrder(root);
	PostOrder(root);
	return 0;
}
