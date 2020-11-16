#include <bits/stdc++.h>
using namespace std;

int main() {
	int ni=100, nj=30;
	double x[ni][nj], y[ni][nj], x1[ni][nj], y1[ni][nj];
	double L1 = 65, L2 = 10, H = 40;
	 
	//double a = 0.3; // do nen
	double a = 10;	
	double p = 0.1; // nen luoi tai y=0
	//double p = 0.9; // nen luoi deu
	//double p = 1.8; //nen luoi tai y=H
	
	//double q = 2; //q tang => luoi nen manh them
	double q = 2;
//	double alpha = 10; 
//	double alpha = 30;
	double alpha = -5.325;
	const double PI = 3.14159265358979323846;
	
	double dxi=1/((double)(ni-1)), det=1/((double)(nj-1));
	
	int changePoint = 0;
	int i=1, j=2;
	for(i=1; i<=ni; i++) {
		double xi = dxi*(i-1);
		double currentXCoord = L1*xi;
		y[i][1] = 0;
		x[i][1] = L1*xi;
		y[i][nj] = H;
		x[i][nj] = x[i][1];
		if(currentXCoord<L2 && currentXCoord+L1*dxi>=L2) {
			changePoint = i;
		}
		if(currentXCoord >= L2) {
			y[i][1] = dxi*(i-changePoint)*L1*tan(alpha*PI/180);
		}

		 //nén theo x
		x[i][1] = L1*(p*xi+(1-p)*(1-tanh(q*(1-xi))/tanh(q)));
		x[i][nj] = x[i][1];

	}
	
	
	for(i=1; i<=ni; i++) {
		for(j=2; j<=nj-1; j++) {
			double eta = det*(j-1);
			double dy;
			dy=eta;
			//nen bao tren+duoi
			/*if(eta <= 0.5) {
				double a1 = exp(2*a*eta/0.5)-1;
				double a2 = exp(2*a)-1;
				dy = 0.5*(a1/a2);
			} else {
				double a1=exp(2*a*(1-eta)/0.5)-1;
           		double a2=exp(2*a)-1;
       			dy=(1-0.5*a1/a2);
			}/*
			
			//nén theo y
			//dy=(p*eta+(1-p)*(1-tanh(q*(1-eta))/tanh(q)));
			
			//nén giua domain
			/*if(eta <= H/2) {
				double a1 = exp(2*a*(H/2-eta)/0.5)-1;
				double a2 = exp(2*a)-1;
				dy = H/2-0.5*(a1/a2);
			} else {
				double a1=exp(2*a*(eta-H/2)/0.5)-1;
           		double a2=exp(2*a)-1;
       			dy=(H/2+0.5*a1/a2);
			}*/
			
			//Interpolation Inner Grid Point
			y[i][j] = (y[i][nj]-y[i][1])*dy+y[i][1];
			cout << y[i][j] << endl;
			x[i][j] = (x[i][nj]-x[i][1])*dy+x[i][1];
		}
	}
	
	ofstream myfile;
	myfile.open ("nen_bao_tren_duoi.tec");
	myfile << "VARIABLES = " << "X " << "Y " << endl;
	myfile << "ZONE  I= "<< ni << ",J= " << nj << ", F=POINT" << endl;
	for(j=1; j<=nj; j++){
		for(i=1; i<=ni; i++) {
			myfile << x[i][j] <<'\t'<< y[i][j] << endl;
		}
	}
}

