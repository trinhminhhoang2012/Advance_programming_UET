#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	
	char mssv[10];
	char name[20];
	char dob[10];
	char math[4];
	char phy[4];
	char chem[4];
	float avg;
} student;

float change(char s[]){
	float f;
	f=atof(s);
	return f;
}

void insert(student*a, int n){
	int i;
	char ins[1000];
	for (i=0;i<n;i++){
		fgets(ins,1000,stdin);
		strcpy(a[i].mssv,strtok(ins,","));
		strcpy(a[i].name,strtok(NULL,",")+1);
		strcpy(a[i].dob,strtok(NULL,",")+1);
		strcpy(a[i].math,strtok(NULL,",")+1);
		strcpy(a[i].phy,strtok(NULL,",")+1);
		strcpy(a[i].chem,strtok(NULL,","));
		a[i].avg=(change(a[i].math)+change(a[i].phy)+change(a[i].chem))/3;
	}
}

void output(student*a,int n){
	printf("in\n");
	int i;
	    printf("NUM\tNAME\tDOB\t\t\tMATH\tPHY\tCHEM\tAVG  \n");
	for (i=0;i<n;i++){
		printf("%s\t%s\t%s\t\t%.1f\t%.1f\t%.1f\t%.1f\n",a[i].mssv,a[i].name,a[i].dob,change(a[i].math),change(a[i].phy),change(a[i].chem),a[i].avg);
	}
}

void sort(student*a,int n){
	printf("sap xep ten theo gpa giam dan\n");
	int i,j,d,b[n+1];
	float c,e[n+1];
	for (i=0;i<n;i++){
		b[i]=i;
		e[i]=a[i].avg;
	}
	
	for (i=0;i<n-1;i++)
	for (j=i+1;j<n;j++){
		if (e[j]>=e[i]){
			c=e[j]; d=b[j];
			e[j]=e[i]; b[j]=b[i];
			e[i]=c; b[i]=d;
		}
	}
	
	for (i=0;i<n;i++){
		printf("- %s\n",a[b[i]].name);
	}
}
int main(){
	int n;
	scanf("%d\n",&n);
	student a[n+1];
	insert(a,n);
	output(a,n);
	sort(a,n);
}
