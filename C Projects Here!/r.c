#include <stdio.h>
#include <string.h>
void innguocchuoi (char *s){
	int i,n=strlen(s);
	for (i=n-1;i>=0;i--){
		printf("%c",s[i]);
	}
}
int main(){
	char*s=(char*)malloc(999*sizeof(char));
	fgets(s,999,stdin);
	innguocchuoi(s);
}
