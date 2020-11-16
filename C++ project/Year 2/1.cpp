#include <bits/stdc++.h>
using namespace std;

const int 
	ni1=30, 
	ni2=70, 
	ni=100, 
	nj=30, 
	ni2New = ni2 + 1;
const double 
	Lmax = 65, 
	L1=10, 
	L2=55, 
	H = 40;
const double 
	alpha=1.5, 
	angle = -5.325, 
	PI = 3.14159265358979323846;
double 
	x[ni+1][nj+1], y[ni+1][nj+1], 
	xCoor1[ni1+1][nj+1], yCoor1[ni1+1][nj+1],
	xCoor2[ni2New+1][nj+1], yCoor2[ni2New+1][nj+1],
	xOld[ni+1][nj+1], yOld[ni+1][nj+1],
	dxi=1/((double)(ni-1)), 
	dxi1=1/((double)(ni1-1)), 
	dxi2=1/((double)(ni2New - 1)), 
	det=1/((double)(nj-1));
int 
	changePoint = 0,
	i=1,
	j=2;
double cb = tan(-angle*PI/180)*65;

double strYH(double eta) {
	double p=1.8;
	double q=10;
	return (p*eta+(1-p)*(1-tanh(q*(1-eta))/tanh(q)));
}

double strY0(double eta) {
	double p=0.1;
	double q=10;
	return (p*eta+(1-p)*(1-tanh(q*(1-eta))/tanh(q)));
}
	
int main() {
	//draw1stSection
	for(i=1; i<=ni1; i++) {
		double xi = dxi1*(i-1);
		yCoor1[i][1] = 0;
		xCoor1[i][1] = L1*xi;
		yCoor1[i][nj] = H;
		xCoor1[i][nj] = xCoor1[i][1];
		
		//xCoor1[i][1] = L1*(1.8*xi+(1-1.8)*(1-tanh(1.6*(1-xi))/tanh(1.6)));
		//xCoor1[i][nj] = xCoor1[i][1];
	}
	
	//draw2ndSection
	for(i=1; i<=ni2New; i++) {
		double xi = dxi2*(i-1);
		yCoor2[i][1] = 0;
		xCoor2[i][1] = L1 + L2*xi;
		yCoor2[i][nj] = H;
		xCoor2[i][nj] = xCoor2[i][1];

		xCoor2[i][1] = L1+L2*(0.1*xi+(1-0.1)*(1-tanh(1.3*(1-xi))/tanh(1.3)));
		xCoor2[i][nj] = xCoor2[i][1];
		
		if(i!=1) {
			//yCoor2[i][1] = xi*L2*tan(angle*PI/180);
			//yCoor2[i][1] = -((double)(65-xi)/65)*cb;
			yCoor2[i][1] = (xCoor2[i][1]-10)*tan(angle*PI/180);
			//cout<<yCoor2[i]
		}
		
	}
	//to create point in the middle of 2 edge (?)
	//edge1
	for(i=1; i<=ni1; i++)
		for(j=2; j<nj; j++) {
			double eta = det*(j-1);
			double dy;
			dy = eta;		
				
			if(eta <= 0.5) {
				double a1 = exp(2*alpha*eta/0.5)-1;
				double a2 = exp(2*alpha)-1;
				dy = 0.5*(a1/a2);
			} /*else {
				double a1=exp(2*alpha*(1-eta)/0.5)-1;
           		double a2=exp(2*alpha)-1;
       			dy=(1-0.5*a1/a2);
			}*/
			
			yCoor1[i][j] = (yCoor1[i][nj]-yCoor1[i][1])*dy+yCoor1[i][1];
			xCoor1[i][j] = (xCoor1[i][nj]-xCoor1[i][1])*dy+xCoor1[i][1];
		}	
	
	//edge2
	for(i=1; i<=ni2+1; i++)
		for(j=2; j<nj; j++) {
			double eta = det*(j-1);
			double dy;
			dy=eta;
	
			if(eta <= 0.5) {
				double a1 = exp(2*alpha*eta/0.5)-1;
				double a2 = exp(2*alpha)-1;
				dy = 0.5*(a1/a2);
			} /*else {
				double a1=exp(2*alpha*(1-eta)/0.5)-1;
           		double a2=exp(2*alpha)-1;
       			dy=(1-0.5*a1/a2);
			}*/
		
			yCoor2[i][j] = (yCoor2[i][nj]-yCoor2[i][1])*dy+yCoor2[i][1];
			xCoor2[i][j] = (xCoor2[i][nj]-xCoor2[i][1])*dy+xCoor2[i][1];
		}
	
	//to joint two section
	for(i=1; i<=ni1; i++)
		for(j=1; j<=nj; j++) {
			x[i][j] = xCoor1[i][j];
			y[i][j] = yCoor1[i][j];
		}
	for(i=ni1+1; i<=ni; i++)
		for(j=1; j<=nj; j++) {
			x[i][j] = xCoor2[i-ni1+1][j];
			y[i][j] = yCoor2[i-ni1+1][j];
		}
	
	//ellipse
	/*for(i=1; i<=ni; i++){
			for(j=1; j<=nj; j++) {
				xOld[i][j] = x[i][j];
				yOld[i][j] = y[i][j];
			}
			for(int count=0; count<100; count ++){
				for(j=2; j<=nj-1; j++) {
					for(i=2; i<=ni-1; i++) {
						double alpha, beta, gamma, a1, a2, c1, c2;
						/////////////////////////
						//dx/dtheta; dy/dtheta
						a1 = (xOld[i][j+1] - x[i][j-1])/2;
						a2 = (yOld[i][j+1] - y[i][j-1])/2;
						//dx/dxi; dy/dxi
						c1 = (xOld[i+1][j] - x[i-1][j])/2; 
						c2 = (yOld[i+1][j] - y[i-1][j])/2;
						//////////////////////////
						alpha = a1*a1 + a2*a2;
						beta = a1*c1 + a2*c2;
						gamma = c1*c1 + c2*c2;
						//////////////////////////
						x[i][j] = (alpha*(xOld[i+1][j] + x[i-1][j]) + gamma*(xOld[i][j+1] + x[i][j-1]) - (beta/2)*(xOld[i+1][j+1] + x[i-1][j-1] - xOld[i-1][j+1] - xOld[i+1][j-1]))/(2*(alpha + gamma));
						y[i][j] = (alpha*(yOld[i+1][j] + y[i-1][j]) + gamma*(yOld[i][j+1] + y[i][j-1]) - (beta/2)*(yOld[i+1][j+1] + y[i-1][j-1] - yOld[i-1][j+1] - yOld[i+1][j-1]))/(2*(alpha + gamma));
						//////////////////////////
						xOld[i][j] = x[i][j];
						yOld[i][j] = y[i][j];
					}
				}
			}
		}*/
	
	ofstream myfile;
	myfile.open ("prandt.tec");
	myfile << "VARIABLES = " << "X " << "Y " << endl;
	myfile << "ZONE  I= "<< ni << ",J= " << nj << ", F=POINT" << endl;
	for(int j=1; j<=nj; j++){
		for(int i=1; i<=ni; i++) {
			myfile << x[i][j] <<'\t'<< y[i][j] << endl;
			cout<<x[i][j] <<'\t'<< y[i][j] << endl;
		}
	}
	myfile.close();
	
	ofstream dat;
	dat.open("dat.dat");
	dat <<ni<<' '<<nj<<endl;
	for(int j=1; j<=nj; j++){
		for(int i=1; i<=ni; i++) {
			dat << x[i][j] <<'\t'<< y[i][j] << endl;
		}
	}
	dat.close();
}
	






