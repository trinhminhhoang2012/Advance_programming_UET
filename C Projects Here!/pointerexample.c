#include <stdio.h>
int main()
{
	int*a; int*b;
	int i,n,j;
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		scanf("%d",a+i);
	for (i=0;i<n;i++)
		printf("%d ",*(a+i));
}
