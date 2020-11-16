#include <stdio.h>
#include <string.h>
int cs(char c){
	if ((c=='a')||(c=='A')) return 1;
	if ((c=='b')||(c=='B')) return 2;
	if ((c=='c')||(c=='C')) return 3;
	if ((c=='d')||(c=='D')) return 4;
	if ((c=='e')||(c=='E')) return 5;
	if ((c=='f')||(c=='F')) return 6;
	if ((c=='g')||(c=='G')) return 7;
	if ((c=='h')||(c=='H')) return 8;
	if ((c=='i')||(c=='I')) return 9;
	if ((c=='j')||(c=='J')) return 10;
	if ((c=='k')||(c=='K')) return 11;
	if ((c=='l')||(c=='L')) return 12;
	if ((c=='m')||(c=='M')) return 13;
	if ((c=='n')||(c=='N')) return 14;
	if ((c=='o')||(c=='O')) return 15;
	if ((c=='p')||(c=='P')) return 16;
	if ((c=='q')||(c=='Q')) return 17;
	if ((c=='r')||(c=='R')) return 18;
	if ((c=='s')||(c=='S')) return 19;
	if ((c=='t')||(c=='T')) return 20;
	if ((c=='u')||(c=='U')) return 21;
	if ((c=='v')||(c=='V')) return 22;
	if ((c=='w')||(c=='W')) return 23;
	if ((c=='x')||(c=='X')) return 24;
	if ((c=='y')||(c=='Y')) return 25;
	if ((c=='z')||(c=='Z')) return 26;
}

int main(){
	char *s=(char*)malloc(999*sizeof(char));
	fgets(s,999,stdin);
	static int a[27],i,n=1;
	for (i=0;i<strlen(s);i++){
		a[cs(s[i])]++;
	}
	for (i=97;i<=122;i++){
		if (a[n]!=0){
		printf("%c %d\n",i,a[n]);
	}
	    n++;
	}
}
