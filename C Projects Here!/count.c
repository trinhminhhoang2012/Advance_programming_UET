#include <stdio.h>
#include <string.h>
int main(){
	char*s=(char*)malloc(1000*sizeof(char));
	fgets(s,1000,stdin);
	int i=0,d;
	if ((s[0])!=' '){
		d=1;
	}
	else{
		d=0;
	}
	if (s[strlen(s)-1]==' '){
		d=d-1;
	}
	while (s[i]!='\0'){
		//printf("%c %c %d\n",s[i],s[i+1],d);
		if ((s[i]!=' ')&&(s[i+1]==' ')){
			d++;
			i++;
		}
		else{
			i++;
		}
		
	}
	printf("%d",d);
}
