#include <stdio.h>
typedef struct{
	float toan;
	float ly;
	float hoa;
}diem;

typedef struct{
	int d;
	int m;
	int y;
}nam;

typedef struct{
	int id;
	char ten[50];
	nam namsinh;
	char tr[10];
	diem diemthi; 
}sinhvien;

void ngaysinh(nam*a){
	printf("\nNgay sinh:");
	scanf("%d/%d/%d",&a->d,&a->m,&a->y);
}

/*void diemt(sinhvien*a){
    printf("\nDiem toan:"); scanf("%d",&a.diemthi.toan);
    printf("\nDiem ly:"); scanf("%d",&a.diemthi.ly);
    printf("\nDiem hoa:"); scanf("%d",&a.diemthi.hoa);
}*/

void insert(sinhvien*a,int n){
	int i;
	for (i=1;i<=n;i++){
		printf("Nhap sinh vien thu %d\nHo ten:",i);
		fflush(stdin);gets(a[i].ten);
		ngaysinh(&(a->namsinh));
		//printf("Ngay sinh:"); scanf("%d/%d/%d",&a[i].namsinh.d,&a[i].namsinh.m,&a[i].namsinh.y);
		printf("Truong:");fflush(stdin);gets(a[i].tr);
		printf("So bao danh:");scanf("%d",&a[i].id);
		printf("Diem toan:"); scanf("%f",&a[i].diemthi.toan);
        printf("Diem ly:"); scanf("%f",&a[i].diemthi.ly);
        printf("Diem hoa:"); scanf("%f",&a[i].diemthi.hoa);
        printf("\n");
	}
}

void print(sinhvien*a,int i){
	
	{
		printf("%s \t\t%d-%d-%d \t\t%s \t\t%d \t\t%f\n",a[i].ten,a[i].namsinh.d,a[i].namsinh.m,a[i].namsinh.y,a[i].tr,a[i].id,(a[i].diemthi.toan+a[i].diemthi.hoa+a[i].diemthi.ly));
		
	}
}

int main(){
int n,i; printf("Nhap so sinh vien:"); scanf("%d",&n);
sinhvien a[n+1];
insert(a,n);
printf("\n------------------------------------------------------------------\n");
	printf("                       DANH  SACH SINH VIEN                       \n");
	printf("HOTEN \t\tNGAYSINH \t\tTRUONG \t\tSOBAODANH \t\tDIEM  \n");
	printf("\n------------------------------------------------------------------\n");
for (i=1;i<=n;i++){
	if (a[i].diemthi.toan+a[i].diemthi.ly+a[i].diemthi.hoa>=15){
		print(a,i);
	}
}
}
