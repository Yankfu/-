#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define MAXSIZE 50
typedef char ElemType; 
typedef struct BiTNode
{
	char data;
	struct BiTNode *Lchild;
	struct BiTNode *Rchild;
}BiTNode,*BiTree;

int IsEmptyBiTree(BiTree *root) 
{
	if(*root == NULL)
	return 1;
	else
	return 0;
}

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
void LevelOrder_BiTree(BiTree root)
{
    //��һ�����б�������Ϣ,����Ķ��в��õ���˳������е�����ʵ��
    int front = 0;
    int rear = 0;
    BiTree BiQueue[MAXSIZE];
    BiTree tempNode;
    if(!IsEmptyBiTree(&root)){
        BiQueue[rear++] = root;
         
        while(front != rear){
            //ȡ����ͷԪ�أ���ʹ��ͷָ������ƶ�һλ��
            tempNode = BiQueue[front++];
            //�ж����������Ƿ�Ϊ��,��Ϊ�գ��������С�
            if(!IsEmptyBiTree(&(tempNode->Lchild)))
                BiQueue[rear++] = tempNode->Lchild;
             
            if(!IsEmptyBiTree(&(tempNode->Rchild)))
                BiQueue[rear++] = tempNode->Rchild;
             
             printf("%c ",tempNode->data);
        }
    }
}

int main(void)
{
	BiTree root;
	CreateBiTree(&root);
    LevelOrder_BiTree(root);
	return 0;
}
