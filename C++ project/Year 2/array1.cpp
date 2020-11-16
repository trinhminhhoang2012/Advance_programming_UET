#include <iostream>			// De su dung cin cout
#include <fstream>			// De doc ghi file		
#include <cstdlib>			// De su dung cac thu vien cua he thong
#include <ctime>			// De dem thoi gian

#include <algorithm>		// De su dung cac thuat toan co ban
	
#include <vector>			// Cau truc du lieu vector
#include <string>			// Cau truc du lieu string

using namespace std;

int gcd(int a, int b) {
	return (b == 0)?(a):gcd(b,a%b);
}

int main() {
	// De do thoi gian
	clock_t thoigian_batdau = clock();
	
	int N = 100;
	int X = 6;
	int K = 1000;
	vector<int> A;
	
	int seed = 1;
	srand(seed);
	
		
	// Khoi tao A co N phan tu
	A.assign(N, 0);
	for (int i = 0; i < N; i++) A[i] = rand() % K;
	
	string output_file = "day1.in";
	
	// Mo file day1.in de ghi ket qua
	ofstream fout(output_file.c_str());
	fout << N << ' ' << X <<endl;
	for (int i = 0; i < N; i++) 
		if (i < N-1) {
			fout << A[i] << " ";
		}
		else {
			fout << A[i] << endl;
		}
	fout.close();	// Dong file
	
	// De do thoi gian
	clock_t thoigian_chayxong = clock();
	// CLOCKS_PER_SEC la thoi gian doi tu` dong ho cua chip sang giay
	double thoigian_chay = double(thoigian_chayxong - thoigian_batdau) / CLOCKS_PER_SEC;		
	cout << "Thoi gian chay: " << thoigian_chay << endl;
	 	
	return 0;
}
