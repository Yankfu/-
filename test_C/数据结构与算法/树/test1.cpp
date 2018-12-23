#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OVERFLOW 0
typedef struct Node
{
    char data;
    struct Node *lchild,*rchild;
    //Node(){data = 0;lchild = rchild = NULL;}
}Node,*BiTree;
 
char PreString[30],InString[30];//先序和中序遍历字符串
 
BiTree Build(char *PreString,char *InString,int s1,int e1,int s2,int e2)
{
//    BiTree T = (BiTree)malloc(sizeof(Node));
//    if(T == NULL)
//    {
//        exit(OVERFLOW);
//    }
    BiTree T = new Node();
    T -> data = PreString[s1];
    int rootIdx;//根结点所在序号
    for(int i = s2;i <= e2;i++)
    {
        if(PreString[s1] == InString[i])
        {
            rootIdx = i;
            break;
        }
    }
    int llen = rootIdx - s2;
    int rlen = e2 - rootIdx;
    if(llen != 0)
    {
        T -> lchild = new Node();
        T -> lchild = Build(PreString,InString,s1 + 1,s1 + llen,s2,s2 + llen - 1);
    }
    else
        T -> lchild = NULL;
    if(rlen != 0)
    {
        T -> rchild = new Node();
        T -> rchild = Build(PreString,InString,e1 - rlen + 1,e1,e2 - rlen + 1,e2);
    }
    else
    {
        T -> rchild = NULL;
    }
    return T;
}
 
void PostOrder(BiTree T)//后序遍历
{
    if(T != NULL)
    {
        PostOrder(T -> lchild);
        PostOrder(T -> rchild);
        printf("%c",T -> data);
    }
}
 
int main()
{
    scanf("%s",PreString);
    scanf("%s",InString);
    BiTree T = NULL;
    T = Build(PreString,InString,0,strlen(PreString)-1,0,strlen(InString)-1);
    PostOrder(T);
    printf("\n");
    return 0;
}

