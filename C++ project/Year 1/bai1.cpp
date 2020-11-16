#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n,f,dc=0,dl=0;
	cin>>n;
	int a[n], b[n], c[n];
	for (i=0;i<n;i++){
		cin>>f;
		if (f%2==0){
			a[dc]=f;
			dc++;
		}
		else{
			b[dl]=f;
			dl++;
		}
	}
	sort(a,a+dc);
	sort(b,b+dl);
	for (i=0;i<dc;i++){
		cout<<a[i]<<' ';
	}
	for (j=dl-1;j>=0;j--){
		cout<<b[j]<<' ';
	}
}
