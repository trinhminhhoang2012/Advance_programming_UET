#include <stdio.h>
typedef struct{
	float chieudai;
	float chieurong;
} HCN;

void insert(HCN*hcn,int n){
	int i;
	for (i=0;i<n;i++){
		scanf("%f %f",&hcn[i].chieudai,&hcn[i].chieurong);
	}
}

float square(float a, float b){
	float s=a*b;
	return s;
}	

float out(HCN*hcn,int n){
	int i;
	for (i=0;i<n;i++){
		printf("%.2f %.2f\n",hcn[i].chieudai,hcn[i].chieurong);
	}
}
int main(){
	int n,i,pos=0; float max=0; scanf("%d\n",&n);
	HCN hcn[n];
	insert(hcn,n);
	out(hcn,n);
	for (i=0;i<n;i++){
		if (square(hcn[i].chieudai,hcn[i].chieurong)>=max){
			max=square(hcn[i].chieudai,hcn[i].chieurong);
			pos=i;
		}
	}
	printf("hinh chu nhat thu %d: dai %f, rong %f",pos+1,hcn[pos].chieudai,hcn[pos].chieurong);
		
	}
