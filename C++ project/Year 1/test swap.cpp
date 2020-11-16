#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j=0,k,n,neg=0;
    cin>>n;
    int a[n];
    for (i=0;i<n;i++){
        cin>>a[i];
        if (a[i]<0){
            neg++;
        }
    };
    sort(a,a+n);
    while (j!=neg){
        for (i=neg;i<n;i++){
            if (a[i]>abs(a[j])){
                break;
            }
            if (a[i]==abs(a[j])){
                cout<<a[j]<<' '<<a[i]<<endl;
            }
        }
        j++;
    }
}
