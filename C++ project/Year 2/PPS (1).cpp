//Lê Ngoc Linh

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
	int ni=100, nj=30;
	double x[ni][nj], y[ni][nj], x1[ni][nj], y1[ni][nj];
	
	double Lmax = 2, Lmin=1.7, H = 1;
	 
	double alpha=1.5; // nén
	
//	double p=0.1; // nén y =0
//	double p=1.8; //nén y=H
//	double p=0.9; //không nén
	double q=2;
	
	double angle = 60;
	const double PI = 3.14159265358979323846;
	
	double dxi=1/((double)(ni-1)), det=1/((double)(nj-1));
	
	int changePoint = 0;
	int i=1, j=2;
	for(i=1; i<=ni; i++) {
		double xi = dxi*(i-1);
		double currentXCoord = Lmax*xi;
		
		y[i][1] = 0;
		x[i][1] = Lmax*xi;
		y[i][nj] = H;
		x[i][nj] = x[i][1];
		
		
		if(currentXCoord<Lmin && currentXCoord+Lmax*dxi>=Lmin) {
			changePoint = i;
		}
		
		if(currentXCoord >= Lmin) {
			y[i][1] = dxi*(i-changePoint)*Lmax*tan(angle*PI/180);
		}

// nén theo x
//		x[i][1] = Lmax*(p*xi+(1-p)*(1-tanh(q*(1-xi))/tanh(q)));
//		x[i][nj] = x[i][1];

	}
	
	
	for(i=1; i<=ni; i++) {
		for(j=2; j<=nj-1; j++) {
			double eta = det*(j-1);
			double dy;
		//không nén y
//			dy = eta;
			
		//	nén theo y
//			dy=(p*eta+(1-p)*(1-tanh(q*(1-eta))/tanh(q)));
			
			//nén giua domain
			if(eta <= H/2) {
				double a1 = exp(2*alpha*(H/2-eta)/0.5)-1;
				double a2 = exp(2*alpha)-1;
				dy = H/2-0.5*(a1/a2);
			} else {
				double a1=exp(2*alpha*(eta-H/2)/0.5)-1;
           		double a2=exp(2*alpha)-1;
       			dy=(H/2+0.5*a1/a2);
			}	
			
			
//			
			//Interpolation Inner Grid Point
			y[i][j] = (y[i][nj]-y[i][1])*dy+y[i][1];
			cout << y[i][j] << endl;
			x[i][j] = (x[i][nj]-x[i][1])*dy+x[i][1];
		}
	}
	
	ofstream myfile;
	myfile.open ("Algebraic_Grid_Generation_Test.tec");
	myfile << "VARIABLES = " << "X " << "Y " << endl;
	myfile << "ZONE  I= "<< ni << ",J= " << nj << ", F=POINT" << endl;
	for(j=1; j<=nj; j++){
		for(i=1; i<=ni; i++) {
			myfile << x[i][j] <<'\t'<< y[i][j] << endl;
		}
	}
}

