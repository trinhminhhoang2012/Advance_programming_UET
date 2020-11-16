#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,a,b;
    int x,y;
    scanf("%d %d",&x,&y);
    a=x;b=y;i=0;j=0;
    int m[100]; int n[100];
    while (a!=0)
    {
        i=i+1;
        m[i]=a%2;
        a=a/2;
        
    }
    while (b!=0)
    {
        j=j+1;
        n[j]=b%2;
        b=b/2;
    }
    int re,p;
    re=abs(i-j);
    p=i-j;
    int k;
    for (k=j;k>=1;k--)
    if (n[k-p]!=m[k])
    {
        re=re+1;
    }
    return p;
}
   
