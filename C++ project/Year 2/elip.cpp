//Lê Ngoc Linh

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


const int ni1=80, ni2=40, ni=120, nj=60;
const int ni2New = ni2 + 1;
double x[ni][nj], y[ni][nj];
double xCoor1[ni1][nj], yCoor1[ni1][nj];
double x2[ni2New][nj], y2[ni2New][nj];

double xOld[ni][nj], yOld[ni][nj];

const double Lmax = 2, L1=1.5, L2=0.5, H = 2;

double alpha=1.5;

const double angle = 60;
const double PI = 3.14159265358979323846;

double dxi=1/((double)(ni-1)), dxi1=1/((double)(ni1-1)), dxi2=1/((double)(ni2New - 1)), det=1/((double)(nj-1));

int changePoint = 0;
int i=1, j=2;

void createEdgeBlock1();
void createEdgeBlock2();
void createInnerPointBlock1();
void createInnerPointBlock2();
void joinBlock();
void exportData();
void elipToMesh();
double middleStretching(double eta);
double edgeStretching(double eta);
double strecthingYH(double eta);
double strecthingY0(double eta);
	
	
int main() {
	createEdgeBlock1();
	createEdgeBlock2();
	createInnerPointBlock1();
	createInnerPointBlock2();
	joinBlock();
	elipToMesh();
	exportData();
}

void createEdgeBlock1() {
	for(i=1; i<=ni1; i++) {
		double xi = dxi1*(i-1);

		yCoor1[i][1] = 0;
		xCoor1[i][1] = L1*xi;
		yCoor1[i][nj] = H;
		xCoor1[i][nj] = xCoor1[i][1];

	}
}

void createEdgeBlock2() {
	for(i=1; i<=ni2New; i++) {
		double xi = dxi2*(i-1);
		
		y2[i][1] = 0;
		x2[i][1] = L1 + L2*xi;
		y2[i][nj] = H;
		x2[i][nj] = x2[i][1];
		
	
		if(i!=1) {
			y2[i][1] = xi*L2*tan(angle*PI/180);
		}

	}
}

void createInnerPointBlock1() {
	for(i=1; i<=ni1; i++) 
		for(j=2; j<nj; j++) {
			double eta = det*(j-1);
			double dy;
//		//không nén y
//			dy = eta;	
		//nen hai bien tren, duoi
			dy = edgeStretching(eta);
//		//nen o y=0
//			dy = strecthingY0(eta);
//		//nen o y=H
//			dy = strecthingYH(eta);
//		//nen giua domain
//			dy = middleStretching(eta);
		//Interpolation Inner Grid Point
		yCoor1[i][j] = (yCoor1[i][nj]-yCoor1[i][1])*dy+yCoor1[i][1];
		xCoor1[i][j] = (xCoor1[i][nj]-xCoor1[i][1])*dy+xCoor1[i][1];
		}	
}

void createInnerPointBlock2() {
	for(i=1; i<=ni2+1; i++) 
		for(j=2; j<nj; j++) {
			double eta = det*(j-1);
			double dy;
//		//không nén y
//			dy = eta;	
		//nen hai bien tren, duoi
			dy = edgeStretching(eta);
//		//nen o y=0
//			dy = strecthingY0(eta);
//		//nen o y=H
//			dy = strecthingYH(eta);
//		//nen giua domain
//			dy = middleStretching(eta);	
		//Interpolation Inner Grid Point
		y2[i][j] = (y2[i][nj]-y2[i][1])*dy+y2[i][1];
		x2[i][j] = (x2[i][nj]-x2[i][1])*dy+x2[i][1];
		}	
}

void joinBlock() {
	for(i=1; i<=ni1; i++)
		for(j=1; j<=nj; j++) {
			x[i][j] = xCoor1[i][j];
			y[i][j] = yCoor1[i][j];
		}
	for(i=ni1+1; i<=ni; i++)
		for(j=1; j<=nj; j++) {
			x[i][j] = x2[i-ni1+1][j];
			y[i][j] = y2[i-ni1+1][j];
		}

	cout << x[ni][nj];
	
}

void elipToMesh() {
	for(i=1; i<=ni; i++) 
			for(j=1; j<=nj; j++) {
				xOld[i][j] = x[i][j];
				yOld[i][j] = y[i][j];
			}
		for(int count=0; count<100; count ++){
			for(j=2; j<=nj-1; j++) {
				for(i=2; i<=ni-1; i++) {
					
					double alpha, beta, gamma, a1, a2, c1, c2;
					
					a1 = (xOld[i][j+1] - x[i][j-1])/2;
					a2 = (yOld[i][j+1] - y[i][j-1])/2;
					c1 = (xOld[i+1][j] - x[i-1][j])/2;
					c2 = (yOld[i+1][j] - y[i-1][j])/2;
					
					alpha = a1*a1 + a2*a2;
					beta = a1*c1 + a2*c2;
					gamma = c1*c1 + c2*c2;
					
					x[i][j] = (alpha*(xOld[i+1][j] + x[i-1][j]) + gamma*(xOld[i][j+1] + x[i][j-1]) - (beta/2)*(xOld[i+1][j+1] + x[i-1][j-1] - xOld[i-1][j+1] - xOld[i+1][j-1]))/(2*(alpha + gamma));
					y[i][j] = (alpha*(yOld[i+1][j] + y[i-1][j]) + gamma*(yOld[i][j+1] + y[i][j-1]) - (beta/2)*(yOld[i+1][j+1] + y[i-1][j-1] - yOld[i-1][j+1] - yOld[i+1][j-1]))/(2*(alpha + gamma));
					
					xOld[i][j] = x[i][j];
					yOld[i][j] = y[i][j];
				}
			}
		}
}

double middleStretching(double eta) {
	double dy;
	if(eta <= 0.5) {
		double a1 = exp(2*alpha*(0.5-eta)/0.5)-1;
		double a2 = exp(2*alpha)-1;
		dy = 0.5 - 0.5*(a1/a2);
	} else {
		double a1=exp(2*alpha*(eta-0.5)/0.5)-1;
   		double a2=exp(2*alpha)-1;
		dy=(0.5+0.5*a1/a2);
	}
	return dy	;
}

double edgeStretching(double eta) {
	double dy;
	if(eta <= 0.5) {
		double a1 = exp(2*alpha*eta/0.5)-1;
		double a2 = exp(2*alpha)-1;
		dy = 0.5*(a1/a2);
	} else {
		double a1=exp(2*alpha*(1-eta)/0.5)-1;
   		double a2=exp(2*alpha)-1;
		dy=(1-0.5*a1/a2);
	}
	return dy;
}

double strecthingYH(double eta) {
	double p=1.8;
	double q=2;
	return (p*eta+(1-p)*(1-tanh(q*(1-eta))/tanh(q)));
}

double strecthingY0(double eta) {
	double p=0.1;
	double q=2;
	return (p*eta+(1-p)*(1-tanh(q*(1-eta))/tanh(q)));
}


void exportData() {
	ofstream myfile;
	myfile.open ("elip.tec");
	myfile << "VARIABLES = " << "X " << "Y " << endl;
	myfile << "ZONE  I= "<< ni << ",J= " << nj << ", F=POINT" << endl;
	for(j=1; j<=nj; j++){
		for(i=1; i<=ni; i++) {
			myfile << x[i][j] <<'\t'<< y[i][j] << endl;
		}
	}
}

