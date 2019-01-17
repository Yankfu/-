//一元多项式的表示及相加
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1  
#define OVERFLOW -2

typedef struct    //项的表示，多项式的项作为LinkList的数据元素
{
    float coef;   //系数
    int expn;   //指数
}term, ElemType;   //两个类型名：term用于本ADT，ElemType为LinkList的数据对象名 

typedef struct LNode   //结点类型
{
    ElemType data;
    struct LNode *next;
}LNode, *Link, *Position;

typedef struct   //链表类型
{
    Link head, tail;
    int len;
}LinkList;

typedef LinkList polynomial;   //用带头结点的有序链表表示多项式
typedef int Status;

Status InitList(LinkList *L)  
{  
//     操作结果：构造一个空的线性链表  
    Link p;  
    p = (Link)malloc(sizeof(LNode));  //生成头结点  
    if(p)  
    {  
        p->next = NULL;  
        (*L).head = (*L).tail = p;  
        (*L).len = 0;  
        return OK;  
    }  
    else  
        return ERROR;  
}  

Status MakeNode(Link *p,ElemType e)  
{  
//     操作结果：分配由p指向的值为e的结点，并返回OK；若分配失败。则返回ERROR  
    (*p) = (Link)malloc(sizeof(LNode));  //分配新结点  
    if(!(*p)) return ERROR;              //分配失败  
    (*p)->data = e;  
    return OK;  
}  

Status InsFirst(LinkList *L,Link h,Link s)   //形参增加L,因为需修改L  
{  
//     操作结果：h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前  
    s->next = h->next;  
    h->next = s;  
    if(h==(*L).tail)         //h指向尾结点  
        (*L).tail = h->next; //修改尾指针  
    (*L).len++;  
    return OK;  
}  

Status DelFirst(LinkList *L,Link h,Link *q) //形参增加L,因为需修改L  
{  
//     操作结果：h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。若链表为空(h指向尾结点)，q=NULL，返回FALSE  
    *q = h->next;  
    if(*q)                     //链表非空  
    {  
        h->next = (*q)->next;  
        if(!h->next)           //删除尾结点  
            (*L).tail = h;     //修改尾指针, 此时链表已为空表
        (*L).len--;  
        return OK;  
    }  
    else  
        return FALSE;          //链表空  

}

//置空链表L
Status ClearList(LinkList *L)
{
    Link p, q;

    if(L->head != L->tail)
    {
        p = q = L->head->next;
        L->head->next = NULL;

        while(p != L->tail)
        {
            p = q->next;
            free(q);
            q = p;
        }

        free(q);

        L->tail = L->head;
        L->len = 0;
    }
    return OK;
}

Position GetHead(LinkList *L)
{
    return L->head;
}

Position NextPos(Link p)  
{  
    return p->next;  
}  
Position PriorPos(LinkList L, Link p)
{
    Link q;
    q = L.head;

    while(q->next != p)
    {
        q = q->next;
    }
    return q;

}

void FreeNode(Link *p)
{
    free((*p));
    (*p) = NULL;
}

Status ListEmpty(LinkList L)  
{  
// 若线性链表L为空表，则返回TRUE，否则返回FALSE  
    return L.len==0;  
}  

ElemType GetCurElem(Link p)  
{  
//已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值  
    return p->data;  
}  

Status Append(LinkList *L,Link s)  
{  
//将指针s(s->data为第一个数据元素)所指(彼此以指针相链,以NULL结尾)的一串结点链接在线性链表L的最后一个结点之后,并改变链表L的尾指针指向新的尾结点  
    int i=1;  
    (*L).tail->next = s;  //s接到L的尾部  
    while(s->next)        //计算s的长度  
    {  
        i++;  
        s = s->next;  
    }  
    (*L).tail = s;        //L的尾指针变成s的尾指针  
    (*L).len+=i;          //增加长度  
    return OK;  
}
//销毁一元多项式P
void DestroyPolyn(LinkList *L)
{
    ClearList(L);          //清空链表  
    FreeNode(&(*L).head);  //释放头结点  
    (*L).tail = NULL;  
    (*L).len = 0;
}

//依e1的指数的值<,=,>e2的指数值， 分别返回-1,0,1 ，此为升序
int cmp(term e1, term e2)
{
    if(e1.expn == e2.expn) return 0;
    if(e1.expn < e2.expn) return -1;
    return 1;
}

//若有序链表L中存在于e满足判定函数compare()取值为0的元素，则q指示L中第一个值为e
//的结点的位置， 并返回TRUE；否则q指示第一个与e满足判定函数compare()取值>0的元素的前驱的位置，并返回FALSE
Status LocateElem(LinkList L, ElemType e, Position *q, int (*compare)(ElemType, ElemType))
{
    Link p, pp;
    p = L.head;
    do
    {
        pp = p;
        p = p->next;
    }while(p && compare(p->data, e) < 0);   //找到第一个大于等于e的位置

    if(!p || compare(p->data, e) >0)   //到表尾或者找到的位置的值并不相等
    {
        (*q) = pp;   //使q指示第一个大于e的结点的直接前驱
        return FALSE;
    }
    else   //找到相等
    {
        (*q) = p;
        return TRUE;
    }
}

//按有序判定函数compare()的约定，将值为e的结点插入到有序链表的L适当位置
Status OrderInsert(LinkList *L, ElemType e, int(*compare)(ElemType, ElemType))
{
    Position q, s;
    if(LocateElem(*L, e, &q, compare))
    {
        q->data.coef += e.coef;   //改变当前结点系数的值

        if(!q->data.coef)   //系数为0，删除多项式L中的当前结点
        {
            s = PriorPos(*L, q);
            if(!s)   //q无前驱
                s = L->head;
            DelFirst(L, s, &q);
            FreeNode(&q);
        }
        return OK;
    }
    else
    {
        if(MakeNode(&s, e))
        {
            InsFirst(L, q, s);
            return OK;
        }

        return ERROR;
    }
}

void CreatPolyn(polynomial *P, int m)
{
    //输入m项的系数和指数，建立表示一元多项式系数的有序链表P
    Position q, s;
    int i;
    term e;

    InitList(P);    //初始化P

    printf("请输入%d个系数，指数：\n", m);
    for(i = 1; i <= m; i++)
    {
        scanf("%f %d", &e.coef, &e.expn);
        if(!LocateElem(*P, e, &q, cmp))   //当前链表中不存在该指数项。cmp是实参
        {
            if(MakeNode(&s, e))   //生成结点并插入链表
                InsFirst(P, q, s);   //将s插入到q的后一个结点
        }
    }
}

//打印输出一元多项式P
void PrintPolyn(polynomial P)
{
    Link q;
    q = P.head->next;   //q指向第一个结点
    printf("系数  指数\n");

    while(q)
    {
        printf("%.2f  %d\n", q->data.coef, q->data.expn);
        q = q->next;
    }
}

//返回一元多项式P中的项数
int PolynLength(polynomial P)
{
    Link q;
    int i;

    q = P.head;
    i = 0;

    while(q != P.tail)
    {
        q = q->next;
        i++;
    }
    return i;
}

//完成多项式相加运算：Pa = Pa + Pb,并销毁一元多项式
void AddPolyn(polynomial *Pa, polynomial *Pb)
{
    Position ha, hb, qa, qb;
    term a, b;

    ha = GetHead(Pa);
    hb = GetHead(Pb);
    qa = NextPos(ha);
    qb = NextPos(hb);
    while(!ListEmpty(*Pa) && !ListEmpty(*Pb) && qa)
    {
        a = GetCurElem(qa);
        b = GetCurElem(qb);
        switch(cmp(a, b))
        {
        case -1:   //Pa中的值较小
            ha = qa;
            qa = NextPos(qa);   //ha和qa均向后移动一个结点
            break;
        case 0:   //Pa和Pb中指数相等
            qa->data.coef += qb->data.coef;
            if(qa->data.coef)
            {
                ha = qa;
            }
            else   //为0则删除多项式Pa中当前结点
            {
                DelFirst(Pa, ha, &qa);
                FreeNode(&qa);
            }
            DelFirst(Pb, hb, &qb);
            FreeNode(&qb);
            qa = NextPos(ha);
            qb = NextPos(hb);
            break;
        case 1:   //多项式Pb中当前结点系数小
            DelFirst(Pb, hb, &qb);
            InsFirst(Pa, ha, qb);
            qb = NextPos(hb);
            ha = NextPos(ha);  
        }
    }
    if(!ListEmpty(*Pb))
    {
        Pb->tail = hb;   //使Pb的指向尾结点的指针指向头结点
        Append(Pa, qb);
    }
    DestroyPolyn(Pb);
}

void Oppsite(polynomial *Pa)
{
    Position p;
    p = Pa->head->next;
    while(p)
    {
        p->data.coef *= -1;
        p = p->next;
    }
}

//（方法一）完成多项式相减运算，即：Pa = Pa - Pb， 并销毁一元多项式Pb
void SubtractPolyn(polynomial *Pa, polynomial *Pb)
{
    Position ha, hb, qa, qb, qqb;
    term a, b;
    ha = GetHead(Pa);
    hb = GetHead(Pb);
    qa = NextPos(ha);
    qb = NextPos(hb);
    while(!ListEmpty(*Pa) && !ListEmpty(*Pb) && qa)
    {
        a = GetCurElem(qa);
        b = GetCurElem(qb);

        switch(cmp(a, b))
        {
        case -1:
            ha = qa;
            qa = NextPos(qa);
            break;
        case 0:
            qa->data.coef -= qb->data.coef;

            if(qa->data.coef)
            {
                ha = qa;
            }
            else
            {
                DelFirst(Pa, ha, &qa);
                FreeNode(&qa);
            }

            DelFirst(Pb, hb, &qb);   //不管a-b的结果如何都要删除此时pb所指结点
            FreeNode(&qb);
            qb = NextPos(hb);
            qa = NextPos(ha);

            break;
        case 1:
            qb->data.coef *= -1;
            DelFirst(Pb, hb, &qb);
            InsFirst(Pa, ha, qb);   //如果b>a就把此时pb所指元素插入到pa所指元素之前
            qb = NextPos(hb);
            ha = ha->next;
            break;
        }
    }

    if(!ListEmpty(*Pb))
    {
        qqb = qb;   
        while(qqb)
        {
            qqb->data.coef *= -1;
            qqb = qqb->next;
        }

        Pb->tail = hb;
        Append(Pa, qb);
    }
    DestroyPolyn(Pb);

}

//（方法二）完成多项式相减运算，即：Pa = Pa - Pb， 并销毁一元多项式Pb
void SubtractPolyn_N(polynomial *Pa, polynomial *Pb)
{
    Oppsite(Pb);
    AddPolyn(Pa, Pb);;

}

//多项式乘法：Pa = Pa * Pb，并销毁一元多项式Pb
void MultipyPolyn(polynomial *Pa, polynomial *Pb)
{
    polynomial Pc;
    Position qa, qb;
    term a, b, c;
    InitList(&Pc);
    qa = GetHead(Pa);
    qa = qa->next;
    while(qa)
    {
        a = GetCurElem(qa);
        qb = GetHead(Pb);
        qb = qb->next;
        while(qb)   //Pa的当前项与Pb的每一项相乘
        {
            b = GetCurElem(qb);
            c.coef = a.coef * b.coef;
            c.expn = a.expn + b.expn;
            OrderInsert(&Pc, c, cmp);   //将结点c添加到多项式Pc中
            qb = qb->next;
        }
        qa = qa->next;
    }

    DestroyPolyn(Pb);
    ClearList(Pa);
    Pa->head = Pc.head;
    Pa->tail = Pc.tail;
    Pa->len = Pc.len;
}

int main(void) 
{
    polynomial p, q;
    int m;
    printf("请输入一个一元多项式的非零项的个数：");
    scanf("%d", &m);
    CreatPolyn(&p, m);
    PrintPolyn(p);

    printf("请输入一个一元多项式的非零项的个数：");
    scanf("%d", &m);
    CreatPolyn(&q, m);
    PrintPolyn(q);


//  AddPolyn(&p, &q);
    //SubtractPolyn_N(&p, &q);
    MultipyPolyn(&p, &q);
    PrintPolyn(p);
    DestroyPolyn(&p); 
}
