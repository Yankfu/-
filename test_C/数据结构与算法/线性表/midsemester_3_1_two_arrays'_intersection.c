#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
	int elem[MAXSIZE];
	int length;
 } seqList;
int main(void)
{
	seqList *A;
	seqList *B;
	seqList *C;
 } 
 
void merge(SeqList *X,SeqList *Y,SeqList *Z)
{
	int i,j,k;
	i=1;
	j=1;
	k=1;
	while(i<=X->length&&j<=Y->length)
	{
		if(X->elem[i]==Y->elem[j])
		{
			Z->elem[k++]=X->elem[i++];
		}
		else if(X->elem[i]>Y->elem[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}
}




int sum(BinTreeNode *node) 
{
	if(node==null||(node->lChild==null&&node->rChild==null)) return 0; 
	else return sum(node->lChild)+sum(node->rChild)+1;
}


typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Node,*SqQueue;

SqQueue QueueInit(SqQueue rear)
{
    rear=(SqQueue)malloc(sizeof(Node));
    if(!rear)
        printf("error");
    else{
        rear->next=rear;
    }
    return rear;
}

SqQueue InsertQueue(SqQueue rear,QElemType e)
{
    SqQueue p;
    p=(SqQueue)malloc(sizeof(Node));
    p->data=e;
    p->next=rear->next;
    rear->next=p;
    rear=p;
    count++;
    return rear;
}

SqQueue OutQueue(SqQueue rear)
{
    int e;
    SqQueue p;
    if(rear==rear->next)
        printf("error");
    else{
        p=rear->next->next;
        e=p->data;
        rear->next->next=p->next;
        if(rear==p)
        {
            rear=rear->next;
        }
        free(p);
    }
    printf("%d",e);
    count--;
    return rear;
}
