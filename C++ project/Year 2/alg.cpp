#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
	int ni=100, nj=30;
	double x[ni][nj], y[ni][nj], x1[ni][nj], y1[ni][nj];
	
	double L=1, H=0.2;
	 
	double alpha=2, p=0.1, q=3;
	
	double dxi=1/((double)(ni-1)), det=1/((double)(nj-1));
	
	cout << dxi << ", " << det;
	
	int i=1, j=2;
	for(i=1; i<=ni; i++) {
		double xi = dxi*(i-1);
		y[i][1] = 0;
		x[i][1] = L*xi;
		y[i][nj] = H;
		x[i][nj] = x[i][1];
		
		x[i][1] = L*(p*xi+(1-p)*(1-tanh(q*(1-xi))/tanh(q)));
		x[i][nj] = x[i][1];
	}
	
	
	for(i=1; i<=ni; i++) {
		for(j=2; j<=nj-1; j++) {
			double eta = det*(j-1);
			double dy;
			//Uniform Grid
//			dy = eta;
			
			//Stretching Grid
//			dy=(p*eta+(1-p)*(1-tanh(q*(1-eta))/tanh(q)));
			
			//Stretching Grid y = 0 và y = H 
			if(eta <= 0.5) {
				double a1 = exp(2*alpha*eta/0.5)-1;
				double a2 = exp(2*alpha)-1;
				dy = 0.5*(a1/a2);
			} else {
				double a1=exp(2*alpha*(1-eta)/0.5)-1;
           		double a2=exp(2*alpha)-1;
       			dy=(1-0.5*a1/a2);
			}
			
			//Interpolation Inner Grid Point
			y[i][j] = (y[i][nj]-y[i][1])*dy+y[i][1];
			x[i][j] = (x[i][nj]-x[i][1])*dy+x[i][1];
		}
	}
	
	ofstream myfile;
	myfile.open ("Algebraic_Grid_Generation_Test.tec");
	myfile << "VARIABLES = " << "X " << "Y " << endl;
	myfile << "ZONE  I= "<< ni << ",J= " << nj << ", F=POINT" << endl;
	cout << ni << " " << nj << endl;
	for(j=1; j<=nj; j++){
		for(i=1; i<=ni; i++) {
			myfile << x[i][j] <<'\t'<< y[i][j] << endl;
			cout << x[i][j] <<'\t'<< y[i][j] << endl;
		}
	}
}

