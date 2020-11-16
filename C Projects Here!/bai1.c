#include <stdio.h>
int main()
{
	int i,j,k,l,n,cd,sg,cc;
	scanf("%d",&n);
	cd=n;
	sg=1;
	cc=n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=cd;j++)
		{
			printf(".");
		}
		for (k=1;k<=sg;k++)
		{
			printf("*");
		}
		for (l=1;l<=cc;l++)
		{
			printf(".");
		}
		cd=cd-1;
		sg=sg+2;
		cc=cc-1;
		printf("\n");
	}
	
	for (i=1;i<=n*2+1;i++)
	{
		printf("*");
	}
	printf("\n");
}
