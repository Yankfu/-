#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct BiTNode
{
	char data;
	struct BiTNode *Lchild;
	struct BiTNode *Rchild;
}BiTNode,*BiTree;
//������չ���д���������
//BiTree CreateBiTree()
//{
//	char ch;
//	BiTree *s;
//	ch=getchar();
//	if(ch=='#')
//		return NULL;
//	else
//	{
//		s=(BiTree)malloc(sizeof(BiTNode));
//		s->data=ch;
//		s->Lchild=CreateBiTree();
//		s->Rchild=CreateBiTree();
//		return s;
//	 } 
// } 

void CreateBiTree(BiTree * root)
{
	char ch;
	ch=getchar();
	if(ch=='#') *root=NULL;
	else 
	{
		*root=(BiTree)malloc(sizeof(BiTNode));
		(*root)->data=ch;
		CreateBiTree(&((*root)->Lchild));
		CreateBiTree(&((*root)->Rchild));
	}
}
 
//����ݹ����������
void PreOrder(BiTree root)
{
	if(root)
	{
		printf("%c",root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
 } 

int main(void)
{
	BiTree root;
	CreateBiTree(&root);
	PreOrder(root);
	return 0;
}
