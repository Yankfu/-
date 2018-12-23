#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 54
#define M 2*N-1
#define MAXINT 32767
#define ch 3000
#define NUM 10000
typedef char numcode[NUM];
typedef char charcode[ch];
typedef char* HuffmanCode[N] ;
typedef struct{
    int weight;
    int parent;
    int Lchild;
    int Rchild; 
}HTNode,HuffmanTree[M]; 
void CrtHuffmanTree(HuffmanTree ht,int n)
{
    int i,s1,s2,m;
    m=2*n-1;
    for(i=0;i<n;i++)
	{
        ht[i].parent=-1;
        ht[i].Lchild=-1;
		ht[i].Rchild=-1;
    }
    for(i=n;i<m;i++)
	{
        ht[i].weight=0;
		ht[i].parent=-1;
        ht[i].Lchild=-1;
		ht[i].Rchild=-1;
    }
    for(i=n;i<m;i++) 
	{
        select(ht,i-1,&s1,&s2);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].Lchild=s1;
        ht[i].Rchild=s2;
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
}
void tongjicishu(HuffmanTree ht,charcode c)
{
	int i=0;
	while(c[i]!='#')
	{
	switch(c[i])
	{
		case ' ':
			ht[0].weight++;
			break;
		case '.':
			ht[1].weight++;
			break;
		case 'A':
			ht[2].weight++;
			break;
		case 'B':
			ht[3].weight++;
			break;
		case 'C':
			ht[4].weight++;
			break;
		case 'D':
			ht[5].weight++;
			break;
		case 'E':
			ht[6].weight++;
			break;
		case 'F':
			ht[7].weight++;
			break;
		case 'G':
			ht[8].weight++;
			break;
		case 'H':
			ht[9].weight++;
			break;
		case 'I':
			ht[10].weight++;
			break;
		case 'J':
			ht[11].weight++;
			break;
		case 'K':
			ht[12].weight++;
			break;
		case 'L':
			ht[13].weight++;
			break;
		case 'M':
			ht[14].weight++;
			break;
		case 'N':
			ht[15].weight++;
			break;
		case 'O':
			ht[16].weight++;
			break;
		case 'P':
			ht[17].weight++;
			break;
		case 'Q':
			ht[18].weight++;
			break;
		case 'R':
			ht[19].weight++;
			break;
		case 'S':
			ht[20].weight++;
			break;
		case 'T':
			ht[21].weight++;
			break;
		case 'U':
			ht[22].weight++;
			break;
		case 'V':
			ht[23].weight++;
			break;
		case 'W':
			ht[24].weight++;
			break;
		case 'X':
			ht[25].weight++;
			break;
		case 'Y':
			ht[26].weight++;
			break;
		case 'Z':
			ht[27].weight++;
			break;
		case 'a':
			ht[28].weight++;
			break;
		case 'b':
			ht[29].weight++;
			break;
		case 'c':
			ht[30].weight++;
			break;
		case 'd':
			ht[31].weight++;
			break;
		case 'e':
			ht[32].weight++;
			break;
		case 'f':
			ht[33].weight++;
			break;
		case 'g':
			ht[34].weight++;
			break;
		case 'h':
			ht[35].weight++;
			break;
		case 'i':
			ht[36].weight++;
			break;
		case 'j':
			ht[37].weight++;
			break;
		case 'k':
			ht[38].weight++;
			break;
		case 'l':
			ht[39].weight++;
			break;
		case 'm':
			ht[40].weight++;
			break;
		case 'n':
			ht[41].weight++;
			break;
		case 'o':
			ht[42].weight++;
			break;
		case 'p':
			ht[43].weight++;
			break;
		case 'q':
			ht[44].weight++;
			break;
		case 'r':
			ht[45].weight++;
			break;
		case 's':
			ht[46].weight++;
			break;
		case 't':
			ht[47].weight++;
			break;
		case 'u':
			ht[48].weight++;
			break;
		case 'v':
			ht[49].weight++;
			break;
		case 'w':
			ht[50].weight++;
			break;
		case 'x':
			ht[51].weight++;
			break;
		case 'y':
			ht[52].weight++;
			break;
		case 'z':
			ht[53].weight++;
			break;
	}
	i++;
	}
}
void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
{
    char *cd;int start,c,p,i;
    cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';   
    for(i=0;i<n;i++){
        start=n-1;c=i;
        p=ht[i].parent;
        while(p!=-1){
            --start;
            if(ht[p].Lchild==c) cd[start]='0';
            else    cd[start]='1';
            c=p;p=ht[p].parent;
        }
        hc[i]=(char*)malloc((n-start)*sizeof(char));        
        //printf("%s\n",&cd[start]);
        strcpy(hc[i],&cd[start]);

    }
    free(cd);
}
void printcode(char s[],HuffmanCode hc)
{
    //printf("\n----%s----\n",hc[0]);
    int i;
    for(i=0;i<N;i++){
        printf("%c:",s[i]);
        printf("%s\n",hc[i]);

    }
}
void chartocode(charcode c,char s[],HuffmanCode hc)
{
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
void  numtochar(numcode ns,HuffmanTree ht,char s[])
{
    char *p=ns;
	int key;
	HTNode g;
    while(*p!='\0')
	{
        g=ht[M-1];            
        while(g.Lchild!=-1&&g.Rchild!=-1&&(*p!='\0'))
		{
            switch(*p)
			{              
            case '0':key=g.Lchild;g=ht[g.Lchild];break;
            case '1':key=g.Rchild;g=ht[g.Rchild];break;
            }
            p++;
        }
        printf("%c",s[key]);
    }
}
int main(void) 
{
	HuffmanTree ht;
	HuffmanCode hc;
	charcode c;
	numcode ns;
	char cha[200];
	int i=0;
//	for(i=0;i<200;i++)
//	{
//		cha[i]='6';
//	}
//	int w[N]; 
	char s[N]={' ','.','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//	do
//	{
//		scanf("%c",&cha[i]);
//		i++;
//	}while(cha[i]!='#');
//	for(i=0;i<200;i++)
//	{
//		printf("%c",cha[i]);
//	}
	gets(c);
	for(i=0;i<54;i++)
	{
		ht[i].weight=0;
	}
	tongjicishu(ht,c);
	CrtHuffmanTree(ht,54);
	for(i=0;i<2*54-1;i++)
	{
		if(i<54) printf("%c   ",s[i]);
		printf("%-5d",i);
		printf("%-10d %-10d %-10d %-10d\n",ht[i].weight,ht[i].parent,ht[i].Lchild,ht[i].Rchild);
	}
	CrtHuffmanCode(ht,hc,54);
//	printcode(s,hc);
	chartocode(c,s,hc);
	scanf("%s",&ns);
	numtochar(ns,ht,s);
}

