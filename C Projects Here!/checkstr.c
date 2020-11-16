#include <stdio.h>
struct p{
	int re;
	int im;
};

void nhap(struct p*i){
	scanf("%d %d",i.re,i.im);
	//printf("%d %d\n",i.re,i.im);
}
void in(struct p i){
	printf("%d %d\n",i.re,i.im);
}
int main(){
	struct p i1,i2,f;
	nhap(i1);
	in (i1);
}
