#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
YEU CAU: Hay cai dat thuat toan Dijkstra bang cach hoan thien not ham dijkstra() duoi day
Duoc phep khai bao them cac bien can thiet
Do thi trong bai tap nay la do thi don (simple), co huong (directed), canh co trong so duong (weighted edge)
Do thi trong bai tap nay co toi da 100 dinh
*/

int n; // so luong dinh cua do thi, cac dinh duoc gan nhan tu 0 toi n-1
int weight[100][100]; 
bool sptSet[100]; //shortest Path tree set
// weight[i][j] = 0 neu khong co canh noi tu i->j
// Nguoc lai, 0 < weight[i][j] <= 100 se luu trong so cua canh noi tu i toi j


// source la dinh xuat phat
// sau ham dijkstra() nay duoc goi xong, dist[i] phai luu gia tri do dai duong di ngan nhat tu dinh source toi dinh i
// neu khong ton tai duong di tu source toi i, dist[i] phai duoc gan gia tri -1
int minDistance(int dist[], bool sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int i = 0; i < n; i++) 
        if (sptSet[i] == false && dist[i] <= min) 
            min = dist[i], min_index = i; 
  
    return min_index; 
} 

void dijkstra(int source, int dist[]) {
	int min_path = 0;
	for (int i=0; i<n; i++){
		dist[i] = INT_MAX, sptSet[i]=false;
	}
	dist[source]=0;
	for (int count = 0; count < n - 1; count++) { 
        int u = minDistance(dist, sptSet); 
        sptSet[u] = true; 
   
        for (int i = 0; i < n; i++) 
  
            if (!sptSet[i] && weight[u][i] && dist[u] != INT_MAX 
                && dist[u] + weight[u][i] < dist[i]){
                	dist[i] = dist[u] + weight[u][i]; 
				}
    } 
    for (int i=0; i<n; i++){
    	if (dist[i]==INT_MAX){
    		dist[i]=-1;
	}
}
}

/*
KHONG DUOC PHEP SUA HAM MAIN()
Ham main() da hoan thien cac cong viec: doc input, ghi output san roi

De kiem tra chuong trinh co dung hay khong, hay chay thu test vi du sau:

Input:
5 5
0 1 1
0 2 4
1 2 2
1 3 3
2 3 1
0
Output dung:
0 1 3 4 -1
 
*/

int main() {
    cin >> n; // doc n la so luong dinh cua do thi
    int m; cin >> m; // doc m la so luong canh cua do thi
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // doc canh u->v voi trong so w
        weight[u][v] = w; // luu y day la canh co huong nen chung ta khong gan weight[v][u] = w
    }
    
    int source; cin >> source; // doc dinh xuat phat
    int *dist = new int[n]; // yeu cau may tinh cap phat bo nho cho 1 mang so nguyen int co n phan tu
    
    // goi thuat toan dijkstra
    dijkstra(source, dist);
    
    // in khoang cach ngan nhat tu dinh source toi moi dinh khac
    for(int i = 0; i < n; ++i) cout << dist[i] << " "; 
    cout << "\n";
    
    // chuong trinh den day la ket thuc, giai phong bo nho dong dung cho bien dist[]   
    delete [] dist; 
}

