#include <stdio.h>
#include <math.h>
int nt(int n)
{
	int i,check=1;
	for (i=2;i<ceil(sqrt(n));i++)
	{
		if (n%i==0)
		{
			check=0;
			break;
		}
	}
	if (check==1) return 1; else return 0;
}

int main()
{
	int i=1,j,n;
	scanf("%d",&n);
	while (i!=n/2)
	{
		i++;
		if (nt(i)==1)
		{
			j=n-i;
			if (nt(j)==1)
			{
				printf("%d %d",i,j);
				break;
			}
		}
	}
}
