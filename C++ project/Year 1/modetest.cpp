#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,max,d,type,k=0,stat;
    cin>>n;
    int a[n+1],b[n][2];
    for (i=0;i<n;i++){
        cin>>a[i];
    }
    for (i=0;i<n;i++){
    	for (j=0;j<2;j++){
    		b[i][j]=0;
		}
	}
	a[n]=-1;
    max=0; d=-1;
    for (i=0;i<=n;i++){
        stat=0;
        for (j=0;j<=d;j++){
        	//cout<<'/';
            if (b[j][0]==a[i]){
                stat=1;
                b[j][1]++;
                if (b[j][1]>max){
                    max=b[j][1];
                };
                break;
            }
        }
            //cout<<stat<<' ';
            if (stat==0){
                d++;
                b[d][0]=a[i];
                b[d][1]=1;
                if (b[j][1]>max){
                    max=b[j][1];
                };
            }
    }
    //cout<<max<<'|';
    //cout<<d;
    for (i=0;i<d;i++){
        if (b[i][1]==max){
            cout<<b[i][0]<<' ';
        }
    }
}
