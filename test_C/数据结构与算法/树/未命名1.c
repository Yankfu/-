#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6
#define M 2*N-1
#define MAXINT 32767
#define ch 30
#define NUM 100
typedef char numcode[NUM];
typedef char charcode[ch];
typedef char* HuffmanCode[N] ;
typedef struct{
    int weight;
    int parent;
    int lchild;
    int rchild; 
}HTNode,HuffmanTree[M]; 



void select(HuffmanTree ht,int pos,int *s1,int *s2);

void CrtHuffmanTree(HuffmanTree ht,int w[],int n)
{
    int i,s1,s2,m;
    m=2*n-1;
    for(i=0;i<n;i++)
	{
        ht[i].weight=w[i];ht[i].parent=-1;
        ht[i].lchild=-1;ht[i].rchild=-1;
    }
    for(i=n;i<m;i++){
        ht[i].weight=0;ht[i].parent=-1;
        ht[i].lchild=-1;ht[i].rchild=-1;
    }
    /*选择 合并*/
    for(i=n;i<m;i++) {
        select(ht,i-1,&s1,&s2);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
    }
}
void select(HuffmanTree ht,int pos,int *s1,int *s2){
    int i,j,m1,m2;/*m1存放最小权值，s1是m1在数组的下标*/
    m1=m2=MAXINT;/*m2存放次小权值，s2是m2在数组的下标*/ 
    for(j=0;j<=pos;j++) {
        if(ht[j].weight<m1&&ht[j].parent==-1){
            m2=m1;*s2=*s1;
            *s1=j;m1=ht[j].weight;
        }
        else if(ht[j].weight<m2&&ht[j].parent==-1){
            m2=ht[j].weight;
            *s2=j;
        }
    }
    /*if(*s1>*s2){//使s1小于s2
        i=*s1;*s1=*s2;*s2=i;        
    }*/
}

void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n){
    char *cd;int start,c,p,i;
    cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';   
    for(i=0;i<n;i++){
        start=n-1;c=i;
        p=ht[i].parent;
        while(p!=-1){
            --start;
            if(ht[p].lchild==c) cd[start]='0';
            else    cd[start]='1';
            c=p;p=ht[p].parent;
        }
        hc[i]=(char*)malloc((n-start)*sizeof(char));        
        //printf("%s\n",&cd[start]);
        strcpy(hc[i],&cd[start]);

    }
    free(cd);
}

void printcode(char s[],HuffmanCode hc){
    //printf("\n----%s----\n",hc[0]);
    int i;
    for(i=0;i<N;i++){
        printf("%c:",s[i]);
        printf("%s\n",hc[i]);

    }
}
void chartocode(charcode c,char s[],HuffmanCode hc){
    char *p=c;  
    int j;
    while(*p!='\0'){    
        for(j=0;j<N;j++){
            if(*p==s[j])
                printf("%s",hc[j]);
        }
        p++;
    }
    printf("\n");   
}
void  numtochar(numcode ns,HuffmanTree ht,char s[]){
    char *p=ns;
	int key;
	HTNode g;
    while(*p!='\0')
	{
        g=ht[M-1];
        //printf("\nht[M-1]=%d\n",g.weight);                
        while(g.lchild!=-1&&g.rchild!=-1&&(*p!='\0'))
		{
            switch(*p)
			{              
            case '0':key=g.lchild;g=ht[g.lchild];break;
            case '1':key=g.rchild;g=ht[g.rchild];break;
            }
            p++;
            //printf("P++=%c\n",*p);
        }
        printf("%c",s[key]);


    }
}
int main(){ 
    HuffmanTree ht;HuffmanCode hc;charcode c;numcode ns;
    char s[N]={'A','B','C','D','E','F'};
    int  w[N];
    int i;
    for(i=0;i<N;i++){
        scanf("%d",&w[i]) ;
    } 
    scanf("%s",&c);
    scanf("%s",&ns);
    printf("\n") ;
    for(int i=0;i<N;i++)
	{
      printf("%d",w[i]) ;
    } 
  	printf("\n") ;

    CrtHuffmanTree(ht,w,6);


    CrtHuffmanCode(ht,hc,6);
    printcode(s,hc);
//    chartocode(c,s,hc); 
//
//    numtochar(ns,ht,s);
}
