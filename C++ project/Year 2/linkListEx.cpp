#include <bits/stdc++.h>
using namespace std;
/*void thirdLargest(int arr[], int arr_size) 
{ 
    int first = arr[0]; 
    for (int i = 1; i < arr_size ; i++) 
        if (arr[i] > first) 
            first = arr[i]; 
  
    int second = INT_MIN; 
    for (int i = 0; i < arr_size ; i++) 
        if (arr[i] > second && arr[i] < first) 
            second = arr[i]; 
  
    int third = INT_MIN; 
    for (int i = 0; i < arr_size ; i++) 
        if (arr[i] > third && arr[i] < second) 
            third = arr[i]; 
    if (third!=INT_MIN){
        cout<<third;
    } else {
        cout<<second;
    }
     
} */
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    if ((n>=3)&&(n<=1000000)){
        int a[n+1];
        bool stat=true;
        for (int i=0; i<n;i++){
            cin>>a[i];
            if (a[i]>1000000000){
                stat=false;
                break;
            }
        }
        if (stat==true){
            sort(a, a+n);
            cout<<a[n-3];
        }
        return 0;
    } 
}

