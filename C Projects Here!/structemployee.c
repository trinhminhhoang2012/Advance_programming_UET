#include <stdio.h>
typedef struct{
	int id;
	char name[100];
	char add[100];
}employee;

void input(employee*a,int n){
	int i;
	for (i=1;i<=n;i++){
		printf("Nhap ma nhan vien thu %d\nMa nhan vien:",i); 
		scanf("%d",&a[i].id);
		printf("Ten:"); fflush(stdin);gets(a[i].name);
		printf("Dia chi:"); fflush(stdin);gets(a[i].add);
		printf("\n"); 
	}
}
void output(employee*a,int n){
	int i;
	printf("\n------------------------------------------------------------------\n");
	printf("                       DANH  SACH NHAN VIEN                       \n");
	printf("MA SO \t\t\t\tHOTEN \t\t\t\tDIACHI \n");
	printf("\n------------------------------------------------------------------\n");
	for (i=1;i<=n;i++){
		printf("%d \t\t\t\t%s \t\t\t\t%s\n",a[i].id,a[i].name,a[i].add);
	}
}

int main(){
	int i,n;
	printf("nhap so nhan vien:"); 
	scanf("%d",&n);
	employee a[n+1];
	input(a,n);
	output(a,n);
}
