#include<stdio.h>
int main(void)
{
	char a1[50];
	char a2[50];
	char b1[50];
	char b2[50];
	scanf("%s %s",a1,a2);
	scanf("%s %s",b1,b2);
	int i=1;
	if(a1[0]==a2[0])
	{
		printf("The common prefix is %c",a1[0]);
		while(a1[i]==a2[i])
		{
			printf("%c",a1[i]);
			i++;
		}
	}
	else
	{
		printf("No common prefix");
	}
	printf("\n");
	i=1;
	if(b1[0]==b2[0])
	{
		printf("The common prefix is %c",b1[0]);
		while(b1[i]==b2[i])
		{
			printf("%c",b1[i]);
			i++;
		}
	}
	else
	{
		printf("No common prefix");
	}
 } 
