#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define N 55
#define M 2*N-1
#define MAXINT 32767
#define CH 3000
#define NUM 10000

typedef char numcode[NUM];
typedef char charcode[CH];
typedef char* HuffmanCode[N];
typedef struct
{
	int weight;
	int parent;
	int Lchild;
	int Rchild;
 } HTNode,HuffmanTree[M];
 
void CrtHuffmanTree(HuffmanTree ht,int n);
void select(HuffmanTree ht,int pos,int *s1,int *s2);
void tongjicishu(HuffmanTree ht,charcode c);
void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n);
void printcode(char s[],HuffmanCode hc);
void chartocode(charcode c,char s[],HuffmanCode hc);
void numtochar(numcode ns,HuffmanTree ht,char s[]);


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


void select(HuffmanTree ht,int pos,int *s1,int *s2)
{
    int i,j,m1,m2;/*m1存放最小权值，s1是m1在数组的下标*/
    m1=m2=MAXINT;/*m2存放次小权值，s2是m2在数组的下标*/ 
    for(j=0;j<=pos;j++) 
	{
        if(ht[j].weight<m1&&ht[j].parent==-1)
		{
            m2=m1;*s2=*s1;
            *s1=j;m1=ht[j].weight;
        }
        else if(ht[j].weight<m2&&ht[j].parent==-1)
		{
            m2=ht[j].weight;
            *s2=j;
        }
    }
}


void tongjicishu(HuffmanTree ht,charcode c)
{
	int i=0;
	while(c[i]!='\0')
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
		case '\n':
			ht[54].weight++;
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
    for(i=0;i<n;i++)
	{
        start=n-1;c=i;
        p=ht[i].parent;
        while(p!=-1)
		{
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
    for(i=0;i<N;i++)
	{
        printf("%c:",s[i]);
        printf("%s\n",hc[i]);

    }
}


void chartocode(charcode c,char s[],HuffmanCode hc)
{
	FILE *fp;
	char filename[NUM];
	strcpy(filename,"huffman_code.txt");
	fp=fopen(filename,"wt");
    char *p=c;
    int j;
    while(*p!='\0')
	{    
        for(j=0;j<N;j++)
		{
            if(*p==s[j])
            {
                printf("%s",hc[j]);
        		fputs(hc[j],fp);
			}
		}
        p++;
    }
    printf("\n");   
    fclose(fp);
    printf("翻译完成！\n"); 
}


void numtochar(numcode ns,HuffmanTree ht,char s[])
{
	printf("请输入要翻译的哈夫曼编码：\n");
	getch(); 
	FILE *fp;
	char filename[50];
	strcpy(filename,"huffman_test_next.txt");
	fp=fopen(filename,"wt");
	
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
        fputc(s[key],fp);
    }
    fclose(fp);
}

int main(int argc,char *argv[])
{
	HuffmanTree ht;//哈夫曼树 
	HuffmanCode hc;//哈夫曼编码
	charcode c;
	numcode ns;
	char cha[200];
	int i=0;
	
	FILE *fp1;
	char filename[50];
	char data[MAXINT]; 
	int fno,fsize;
	char prec;
	printf("请输入要打开的文件的完整路径及文件名：");
//	gets(filename);
	strcpy(filename,"huffman_test.txt");
	fp1=fopen(filename,"wt+");
	if(fp1==NULL)
	{
		printf("\n打开文件失败，%s可能不存在\n",filename);
		exit(1);	
	}
	fno=fileno(fp1);
	printf("\n%s文件打开！",filename);
	i=0; 
	//写文件
	printf("请输入要翻译的哈夫曼编码：\n");
	gets(data);//不能输入回车 
	for(i=0;i<strlen(data);i++) 
	{
		fputc(data[i],fp1);
	}
	fclose(fp1);
	fp1=fopen(filename,"rt"); //重新打开文件，让指针回到头 
	i=0;
	while((prec=fgetc(fp1))!=EOF)//最后用eof作为结尾 
	{
		printf("%c",prec);
		c[i]=prec;
		i++;
	}
	fclose(fp1);
	
	

	char s[N]={' ','.','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\n'};
	for(i=0;i<N;i++)
	{
		ht[i].weight=0;
	}
	
	
	tongjicishu(ht,c);
	CrtHuffmanTree(ht,N);
	
//	for(i=0;i<2*N-1;i++)
//	{
//		if(i<N) printf("%c   ",s[i]);
//		printf("%-5d",i);
//		printf("%-10d %-10d %-10d %-10d\n",ht[i].weight,ht[i].parent,ht[i].Lchild,ht[i].Rchild);
//	}
	
	CrtHuffmanCode(ht,hc,N);
//	printcode(s,hc);
	chartocode(c,s,hc);
	
	
	
	FILE *fp;
	char filename1[100];
	char prenum;
	strcpy(filename1,"huffman_code.txt");
	fp=fopen(filename1,"rt");
	i=0;
	while((prenum=fgetc(fp1))!=EOF)
	{
		ns[i]=prenum;
		i++;
	}
	numtochar(ns,ht,s);
	fclose(fp);
}
