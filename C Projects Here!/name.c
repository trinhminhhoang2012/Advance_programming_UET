#include <stdio.h>
#include <string.h>
int check(char s[]){
	if (s[0]=='L'){
		if (s[1]=='y'){
			return 1;
		}
		if (s[1]=='e'){
			return 3;
		}
	}
	if (s[0]=='T'){
		if ((s[1]=='r')&&(s[2]=='a')&&(s[3]=='n')){
			return 2;
		}
	}
	if (s[0]=='N'){
		if ((s[1]=='g')&&(s[2]=='u')&&(s[3]=='y')&&(s[3]=='e')&&(s[3]=='n')){
			return 4;
		}
	}
}

int main(){
	char s[100][100];
	int i,n; static int ho[5];
	scanf("%d\n",&n);
	for (i=0;i<n;i++){
		fgets(s[i],100,stdin);
		s[i][strlen(s[i])-1]='\0';
		ho[check(s[i])]++;
	}
		printf("Ly %d\n Tran %d\n Le%d\n Nguyen%d\n",ho[1],ho[2],ho[3],ho[4]);
}
