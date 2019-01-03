#include<stdio.h>

#define MAXSIZE 1000
typedef int KeyType;
typedef struct
{
	KeyType key;
	int data;
}RecordType;
typedef struct
{	
	RecordType r[MAXSIZE+1];
	int length;
}RecordList;
RecordList L;

void InsertSort(RecordList l)
{
	for(i=2;i<=L.length;i++)
	{
		L.r[0]=L.r[i];
		for(j=i-1;L.r[0].key<L.r[j].key;j--)
			L.r[j+1]=L.r[j];
		L.r[j+1]=L.r[0];
	}
}

void InsertSort(RecordList l)
{
	for(i=2;i<=L.length;i++)
	{
		if(L.r[i].key<L.r[i-1].key)
		{
			L.r[0]=L.r[i];
			for(j=i-1;L.r[0].key<L.r[j].key;j--)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0];
		}
	}
}

void BiInsertSort(RecordList L)
{
	for(i=2;i<=L.length;i++)
	{
		if(L.r[i].key<L.r[i-1].key)
		{
			L.r[0]=L.r[i];
			low=1;
			high=i-1;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(L.r[0].key<L.r[mid].key) high=mid-1;
				else low=mid+1;
			}
			for(j=i-1;j>=low;j--)
			{
				L.r[j+1]=L.r[j];
			}
			L.r[low]=L.r[0];
		}
	}
}

void ShellInsert(RecordList L,int dk)
{
	for(i=dk+1;i<=L.length;i++)
		if(L.r[i].key<L.r[i-dk].key)
		{
			L.r[0]=L.r[i];
			for(j=i-dk;j>0&&(L.r[0].key<L.r[j].key);j-=dk)
				L.r[j+dk]=L.r[j];
			L.r[j+dk]=L.r[0];
		}
}

void ShellSort(RecordList L,int dlta[],int t)
{
	for(k=0;k<L.length;t++)
		ShellInsert(L,dlta[k]);
		
}


void BubbleSort(RecordList L)
{
	for(i=1;i<=L.length-1;i++)
		for(j=1;j<=L.length-i;j++)
			if(L.r[j].key>L.r[j+1].key)
			{
				t=L.r[j];
				L.r[j]=L.r[j+1];
				L.r[j+1]=t;
			}
}

void BubbleSort(RecordList L)
{
	flag=1;
	for(i=1;i<=L.length-1;i++)
	{
		flag=0;
		for(j=1;j<=L.length-i&&flag;j++)
			if(L.r[j].key>L.r[j+1].key)
			{
				t=L.r[j];
				L.r[j]=L.r[j+1];
				L.r[j+1]=t;
				flag=1;
			}
	}
}

int QKpass(RecordList L,int low,int high)
{
	L.r[0]=L.r[low];
	while(low<high)
	{
		while(low<high&&L.r[high].key>=L.r[0].key) --high;
		L.r[low]=L.r[high];
		while(Low<high&&L.r[low].key<L.r[0].key) ++low;
		L.r[high]=L.r[low];
	}
	L.r[low]=L.r[0];
	return low;
}
void QKSort(RecordList L,int low,int high)
{
	if(low<high)
	{
		pos=QKpass(L,low,high);
		QKSort(L,low,pos-1);
		QKSort(L,pos+1,high);
	}
}

void SelectSort(RecordList L)
{
	for(i=1;i<=L.length-1;i++)
	{
		k=i;
		for(j=i+1;j<=L.length-1;j++)
		{
			if(L.r[j].key<L.r[k].key)
				k=j;
		}
		if(k!=i)
		{
			t=L.r[i];
			L.r[i]=L.r[k];
			L.r[k]=t;
		}
	}
}

void HeapAdjust(RecordList L,int s,int m)
{
	t=L.r[s];
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m&&L.r[j].key>L.r[j+1].key)
			j++;
		if(t.key<=L.r[j].key)
			break;
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=t;
}
void CreakHeap(RecordList L)
{
	for(i=L.length/2;i>=1;i++)
		HeapAdjust(L,i,L.length);
}
void HeapSort(RecordList L)
{
	CreatHeap(L);
	for(i=L.length;i>=2;i--)
	{
		L.r[0]=L.r[1];
		L.r[1]=L.r[i];
		L.r[i]=L.r[0];
		HeapAdjust(L,1,i-1);
	}
}

int main(void)
{
	
}
