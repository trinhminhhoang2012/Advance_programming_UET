#include <stdio.h>
#include <string.h>
void chuanhoaten(char*s)
{
	int i,n=strlen(s);
	if ((s[0]>='a')&&(s[0]<='z')){
		s[0]=s[0]-32;
	}
	for (i=1;i<n;i++){
		if ((s[i-1]==' ')&&(s[i]>='a')&&(s[i]<='z')){
			s[i]=s[i]-32;
		}
		if ((s[i-1]!=' ')&&(s[i]>='A')&&(s[i]<='Z')){
			s[i]=s[i]+32;
		}
	}
}
int main(){
	char*s=(char*)malloc(1000*sizeof(char));
	fgets(s,1000,stdin);
	chuanhoaten(s);
	printf("%s",s);
}
