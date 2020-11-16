#include<bits/stdc++.h>
using namespace std;
int mystrlen(char s[]){
	int i=0;
	do{
		i++;
	}while(s[i]);
	return i-1;	
}
char* mystrcpy(int a, int b, char s[]){
	int i,f=0;
	char*k;
	for (i=a;i<=b;i++){
		k[f]=s[i];
		f++;
	};
	return k;
}
char* mystrcat(char s[], char k[]){
	char*f;
	int o=0;
	for (int j=0;j<strlen(s);j++){
		f[j]=s[o];
		o++;
	}
	int l=0;
	for (int i=strlen(s);i<strlen(k);i++){
		f[i]=k[l];
		l++;
	}
	return f;
}
int main(){
	char s[1000], p[1000];
	fgets(s,1000,stdin);
	fgets(p,1000,stdin);
	s[strlen(s)-1]='\0';
	p[strlen(p)-1]='\0';
	//cout<<s<<endl;
	//cout<<p<<endl;
	//cout<<mystrlen(s);
	//char*k=mystrcpy(2,4,s);
	//cout<<k<<endl;
	char*l=strcat(s,p);
	cout<<l;
}

