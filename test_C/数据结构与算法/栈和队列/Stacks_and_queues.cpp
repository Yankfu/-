#include<stdio.h>
#define MAXSIZE <50/*栈的最大元素*/>
typedef struct
{
	int data[MAXSIZE];
	int top;
 } SeqStack;
int main(void)
{
	return 0;
}
SeqStack *Init_SeqStack()
{
	SeqStack *s;
	s=malloc(sizeof(SeqStack));
	s->top=-1;
	return s;
}
int Empty_SeqStack(SeqStack *s)
{
	if (s->top==-1) return 1;
	else return 0;
}
int Push_SeqStack(SeqStack *s,int *x)
{
	if (s->top==MAXSIZE-1) return 0;
	else
	{
		s->top++;
		s->data[s->top]=x;
		return 1;
	}
}
int Pop_SeqStack(SeqStack *s,int *x)
{
	if(Empty_SeqStack(s)) return 0;
	else
	{
		*x=s->data[s->top];
		s->top--；
		return 1; 
	}
}
int Top_SeqStack(SeqStack *s)
{
	if(Empty_SeqStack(s)) return 0;
	else return (s->data[s->top]);
}
