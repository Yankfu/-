//һԪ����ʽ�ı�ʾ�����
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1  
#define OVERFLOW -2

typedef struct    //��ı�ʾ������ʽ������ΪLinkList������Ԫ��
{
    float coef;   //ϵ��
    int expn;   //ָ��
}term, ElemType;   //������������term���ڱ�ADT��ElemTypeΪLinkList�����ݶ����� 

typedef struct LNode   //�������
{
    ElemType data;
    struct LNode *next;
}LNode, *Link, *Position;

typedef struct   //��������
{
    Link head, tail;
    int len;
}LinkList;

typedef LinkList polynomial;   //�ô�ͷ�������������ʾ����ʽ
typedef int Status;

Status InitList(LinkList *L)  
{  
//     �������������һ���յ���������  
    Link p;  
    p = (Link)malloc(sizeof(LNode));  //����ͷ���  
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
//     ���������������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܡ��򷵻�ERROR  
    (*p) = (Link)malloc(sizeof(LNode));  //�����½��  
    if(!(*p)) return ERROR;              //����ʧ��  
    (*p)->data = e;  
    return OK;  
}  

Status InsFirst(LinkList *L,Link h,Link s)   //�β�����L,��Ϊ���޸�L  
{  
//     ���������hָ��L��һ����㣬��h����ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ  
    s->next = h->next;  
    h->next = s;  
    if(h==(*L).tail)         //hָ��β���  
        (*L).tail = h->next; //�޸�βָ��  
    (*L).len++;  
    return OK;  
}  

Status DelFirst(LinkList *L,Link h,Link *q) //�β�����L,��Ϊ���޸�L  
{  
//     ���������hָ��L��һ����㣬��h����ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء�������Ϊ��(hָ��β���)��q=NULL������FALSE  
    *q = h->next;  
    if(*q)                     //����ǿ�  
    {  
        h->next = (*q)->next;  
        if(!h->next)           //ɾ��β���  
            (*L).tail = h;     //�޸�βָ��, ��ʱ������Ϊ�ձ�
        (*L).len--;  
        return OK;  
    }  
    else  
        return FALSE;          //�����  

}

//�ÿ�����L
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
// ����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE  
    return L.len==0;  
}  

ElemType GetCurElem(Link p)  
{  
//��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ  
    return p->data;  
}  

Status Append(LinkList *L,Link s)  
{  
//��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ������,��NULL��β)��һ�������������������L�����һ�����֮��,���ı�����L��βָ��ָ���µ�β���  
    int i=1;  
    (*L).tail->next = s;  //s�ӵ�L��β��  
    while(s->next)        //����s�ĳ���  
    {  
        i++;  
        s = s->next;  
    }  
    (*L).tail = s;        //L��βָ����s��βָ��  
    (*L).len+=i;          //���ӳ���  
    return OK;  
}
//����һԪ����ʽP
void DestroyPolyn(LinkList *L)
{
    ClearList(L);          //�������  
    FreeNode(&(*L).head);  //�ͷ�ͷ���  
    (*L).tail = NULL;  
    (*L).len = 0;
}

//��e1��ָ����ֵ<,=,>e2��ָ��ֵ�� �ֱ𷵻�-1,0,1 ����Ϊ����
int cmp(term e1, term e2)
{
    if(e1.expn == e2.expn) return 0;
    if(e1.expn < e2.expn) return -1;
    return 1;
}

//����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ�أ���qָʾL�е�һ��ֵΪe
//�Ľ���λ�ã� ������TRUE������qָʾ��һ����e�����ж�����compare()ȡֵ>0��Ԫ�ص�ǰ����λ�ã�������FALSE
Status LocateElem(LinkList L, ElemType e, Position *q, int (*compare)(ElemType, ElemType))
{
    Link p, pp;
    p = L.head;
    do
    {
        pp = p;
        p = p->next;
    }while(p && compare(p->data, e) < 0);   //�ҵ���һ�����ڵ���e��λ��

    if(!p || compare(p->data, e) >0)   //����β�����ҵ���λ�õ�ֵ�������
    {
        (*q) = pp;   //ʹqָʾ��һ������e�Ľ���ֱ��ǰ��
        return FALSE;
    }
    else   //�ҵ����
    {
        (*q) = p;
        return TRUE;
    }
}

//�������ж�����compare()��Լ������ֵΪe�Ľ����뵽���������L�ʵ�λ��
Status OrderInsert(LinkList *L, ElemType e, int(*compare)(ElemType, ElemType))
{
    Position q, s;
    if(LocateElem(*L, e, &q, compare))
    {
        q->data.coef += e.coef;   //�ı䵱ǰ���ϵ����ֵ

        if(!q->data.coef)   //ϵ��Ϊ0��ɾ������ʽL�еĵ�ǰ���
        {
            s = PriorPos(*L, q);
            if(!s)   //q��ǰ��
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
    //����m���ϵ����ָ����������ʾһԪ����ʽϵ������������P
    Position q, s;
    int i;
    term e;

    InitList(P);    //��ʼ��P

    printf("������%d��ϵ����ָ����\n", m);
    for(i = 1; i <= m; i++)
    {
        scanf("%f %d", &e.coef, &e.expn);
        if(!LocateElem(*P, e, &q, cmp))   //��ǰ�����в����ڸ�ָ���cmp��ʵ��
        {
            if(MakeNode(&s, e))   //���ɽ�㲢��������
                InsFirst(P, q, s);   //��s���뵽q�ĺ�һ�����
        }
    }
}

//��ӡ���һԪ����ʽP
void PrintPolyn(polynomial P)
{
    Link q;
    q = P.head->next;   //qָ���һ�����
    printf("ϵ��  ָ��\n");

    while(q)
    {
        printf("%.2f  %d\n", q->data.coef, q->data.expn);
        q = q->next;
    }
}

//����һԪ����ʽP�е�����
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

//��ɶ���ʽ������㣺Pa = Pa + Pb,������һԪ����ʽ
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
        case -1:   //Pa�е�ֵ��С
            ha = qa;
            qa = NextPos(qa);   //ha��qa������ƶ�һ�����
            break;
        case 0:   //Pa��Pb��ָ�����
            qa->data.coef += qb->data.coef;
            if(qa->data.coef)
            {
                ha = qa;
            }
            else   //Ϊ0��ɾ������ʽPa�е�ǰ���
            {
                DelFirst(Pa, ha, &qa);
                FreeNode(&qa);
            }
            DelFirst(Pb, hb, &qb);
            FreeNode(&qb);
            qa = NextPos(ha);
            qb = NextPos(hb);
            break;
        case 1:   //����ʽPb�е�ǰ���ϵ��С
            DelFirst(Pb, hb, &qb);
            InsFirst(Pa, ha, qb);
            qb = NextPos(hb);
            ha = NextPos(ha);  
        }
    }
    if(!ListEmpty(*Pb))
    {
        Pb->tail = hb;   //ʹPb��ָ��β����ָ��ָ��ͷ���
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

//������һ����ɶ���ʽ������㣬����Pa = Pa - Pb�� ������һԪ����ʽPb
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

            DelFirst(Pb, hb, &qb);   //����a-b�Ľ����ζ�Ҫɾ����ʱpb��ָ���
            FreeNode(&qb);
            qb = NextPos(hb);
            qa = NextPos(ha);

            break;
        case 1:
            qb->data.coef *= -1;
            DelFirst(Pb, hb, &qb);
            InsFirst(Pa, ha, qb);   //���b>a�ͰѴ�ʱpb��ָԪ�ز��뵽pa��ָԪ��֮ǰ
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

//������������ɶ���ʽ������㣬����Pa = Pa - Pb�� ������һԪ����ʽPb
void SubtractPolyn_N(polynomial *Pa, polynomial *Pb)
{
    Oppsite(Pb);
    AddPolyn(Pa, Pb);;

}

//����ʽ�˷���Pa = Pa * Pb��������һԪ����ʽPb
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
        while(qb)   //Pa�ĵ�ǰ����Pb��ÿһ�����
        {
            b = GetCurElem(qb);
            c.coef = a.coef * b.coef;
            c.expn = a.expn + b.expn;
            OrderInsert(&Pc, c, cmp);   //�����c��ӵ�����ʽPc��
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
    printf("������һ��һԪ����ʽ�ķ�����ĸ�����");
    scanf("%d", &m);
    CreatPolyn(&p, m);
    PrintPolyn(p);

    printf("������һ��һԪ����ʽ�ķ�����ĸ�����");
    scanf("%d", &m);
    CreatPolyn(&q, m);
    PrintPolyn(q);


//  AddPolyn(&p, &q);
    //SubtractPolyn_N(&p, &q);
    MultipyPolyn(&p, &q);
    PrintPolyn(p);
    DestroyPolyn(&p); 
}
