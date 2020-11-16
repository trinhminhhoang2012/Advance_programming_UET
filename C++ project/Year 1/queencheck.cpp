#include <bits/stdc++.h>
using namespace std;
void expand(int**a, int x, int y, int size){
	int n=size,i,j,k=1,e=n-y,f=x,g=y;
	//main cross k
	for (i=n-y;i<=n;i++){
		if ((!a[i][k])&&(a[i][k]!=2)){
			*(*(a+i)+k)=1;
		}
		k++;
		
	};
	//second cross e
	for (i=1;i<=n;i++){
		if ((!a[i][e])&&(a[i][e]!=2)){
			*(*(a+i)+e)=1;
		}
		e--;
		if ((!a[y][i])&&(a[y][i]!=2)){
			*(*(a+y)+i)=1;
		}
		if ((!a[i][f])&&(a[i][f]!=2)){
			*(*(a+i)+f)=1;
		}
	}
	//row cross f
	/*for (i=1;i<=n;i++){
		if ((!a[y][i])&&(a[y][i]!=2)){
			*(*(a+y)+i)=1;
		}
	}
	//column cross g
	for (i=1;i<=n;i++){
		if ((!a[i][f])&&(a[i][f]!=2)){
			*(*(a+i)+f)=1;
		}
	}*/
}
int main(){
	int i,j,n=10,x,y,f,stat=1;
	cin>>n;
	int**a; a = (int**)malloc(n*sizeof(int*));
	for (i=1;i<=n;i++){
		*(a+i)=(int*)malloc(n*sizeof(int));
		for (j=1;j<=n;j++){
			*(*(a+i)+j)=0;
		}
	}
	//memset(a,0,sizeof(a)*n*n);
	for (f=1;f<=n;f++){
		cin>>x>>y;
		if (a[y][x]==1){
			cout<<"yes";
			stat=0;
			break;
		} else{
			*(*(a+y)+x)=2;
			expand(a,x,y,n);
			for (i=1;i<=n;i++){
				for (j=1;j<=n;j++){
					cout<<*(*(a+j)+i)<<' ';
				}
				cout<<endl;
			}
		}
	}
	/*for (i=1;i<=n;i++){
				for (j=1;j<=n;j++){
					cout<<*(*(a+j)+i)<<' ';
				}
				cout<<endl;
			}*/
	if (stat==1){
		cout<<"no";
	}
	
}
