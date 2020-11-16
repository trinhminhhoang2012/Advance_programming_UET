#include <iostream>			// De su dung cin cout
#include <fstream>			// De doc ghi file		
#include <cstdlib>			// De su dung cac thu vien cua he thong
#include <ctime>			// De dem thoi gian

#include <algorithm>		// De su dung cac thuat toan co ban
	
#include <vector>			// Cau truc du lieu vector
#include <string>			// Cau truc du lieu string

using namespace std;

int main() {
	// De do thoi gian
	clock_t thoigian_batdau = clock();
	
	//---------------------------------------------------------------
	string input_file = "day1.in"; 		// Ten file input
	int N;
	int X;									// Do day day so
	vector<int> A;							// Day so
	
	//---------------------------------------------------------------
	// Mo file va doc du lieu
	ifstream fin(input_file.c_str());	
	fin >> N >> X;
	A.assign(N, 0);				// Khoi tao day A co N phan tu, moi phan tu co gia tri = 0
	for (int i = 0; i < N; i++) fin >> A[i];	
	// Dong file
	fin.close();
	//---------------------------------------------------------------

	// YOUR CODE
	//BAI_2_B
	/*int min=A[0];
	for (int i=0; i< N; i++){
		if (A[i] < min){
			min=A[i];
		}
	};
	cout << "so min: "<<min<<endl;;*/
	
	//BAI_3 do_phuc_tap: O(N)
	/*int minSum = A[0];
	int maxSum = A[0];
	int min = A[0];
	int max = A[0];
	for (int i=1;i<N;i++){
		if (A[i]<min){
			min=A[i];
			minSum=A[i];
		} else if (A[i]==min){
			minSum+=A[i];
		}

		if (A[i]>max){
			max=A[i];
			maxSum=A[i];
		} else if (A[i]==max) {
			maxSum+=A[i];
		}
	}
	if (max==min){
		
		cout<<"tong: "<<maxSum;
	} else {
		int maxMin = maxSum + minSum;
		cout<<"tong: "<<maxMin;
	}*/
	
	//BAI_4
		bool isAppear = false;
		for (int i=0;i<N;i++){
			if (A[i]==X){
				cout<<i<<endl;
				isAppear = true;
				break;
			}
		}
		if (isAppear == false){
			cout<<"NO"<<endl;
		}
	

	

	//---------------------------------------------------------------
	// In ra man hinh, can than voi N co gia tri lon
	cout << "Day so vua duoc doc vao la:" << endl;
	cout << "N = " << N << endl;
	for (int i = 0; i < N; i++) cout << "A[" << i << "] = " << A[i] << endl;
	
	//---------------------------------------------------------------
	
	// De do thoi gian
	clock_t thoigian_chayxong = clock();
	// CLOCKS_PER_SEC la thoi gian doi tu` dong ho cua chip sang giay
	double thoigian_chay = double(thoigian_chayxong - thoigian_batdau) / CLOCKS_PER_SEC;		
	cout << "Thoi gian chay: " << thoigian_chay << endl;
	 	
	return 0;
}
