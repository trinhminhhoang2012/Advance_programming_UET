#include <stdio.h>
#include <math.h>
int main(){
	float a[100],k;
	int i,n,position;
	position=0;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%f",&a[i]);
	}
	scanf("%f",&k);
	
	if (a[0]>=k){
		printf("1");
		printf("%.1f ",k);
		for (i=0;i<n;i++){
			printf("%.1f ",a[i]);
		}
	}
	
	if (a[n-1]<=k){
		printf("%.1f",a[n-1]);
		for (i=0;i<n;i++){
			printf("%.1f ",a[i]);
		}
		printf("%.1f",k);
	}
	
	if ((a[0]<=k)&&(a[n-1]>=k)){
	for (i=0;i<n-1;i++){
		if ((a[i]<=k)&&(a[i+1]>=k)){
			position=i+1;
			break;
		}
	}
	for (i=0;i<position;i++){
		printf("%.1f ",a[i]);
	}
	printf("%.1f ",k);
	for (i=position;i<n;i++){
		printf("%.1f ",a[i]);
	}
}
}
