#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char s[100];
	fgets(s,100,stdin);
	printf("%s\n",strtok(s,","));
	printf("%s\n",strtok(NULL,","));
	printf("%s\n",s);
}
