#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

double fy(double x, double y, double z);
double fz(double x, double y, double z);


int main(){
    double x, y, z;

    double d_y1, d_y2, d_y3, d_y4;
    double d_z1, d_z2, d_z3, d_z4;

    double h = 0.1;
    double end = 0.4;
    int time = 0;

    x = 0;
    y = 1;
    z = 0.5;


    cout << "Time" << '\t' << "dy1" << '\t' << "dy2" << '\t' << "dy3" << '\t' << "dy4" << '\t' << "dz1" << '\t' << "dz2" << '\t' << "dz3" << '\t' << "dz4" << '\t' << "yn" << '\t' << "zn" <<endl;
    	//cout << time << fixed << setprecision(4)<<'\t' << x << '\t' << y << '\t' << z;
    	d_y1 = fy(x, y, z);
        d_z1 = fz(x, y, z);

        d_y2 = fy(x+h/2, y+d_y1/2, z+d_z1/2);
        d_z2 = fz(x+h/2, y+d_y1/2, z+d_z1/2);

        d_y3 = fy(x+h/2, y+d_y2/2, z+d_z2/2);
        d_z3 = fz(x+h/2, y+d_y2/2, z+d_z2/2);

        d_y4 = fy(x+h/2, y+d_y3, z+d_z3);
        d_z4 = fz(x+h/2, y+d_y3, z+d_z3);

        y = y + (d_y1 + 2*d_y2 + 2*d_y3 + d_y4)/6;
        z = z + (d_z1 + 2*d_z2 + 2*d_z3 + d_z4)/6;
        x = x + h;

        cout << time << fixed << setprecision(4)<<'\t'<< d_y1 << '\t' <<d_y2 << '\t' <<d_y3 << '\t' <<d_y4 << '\t' <<d_z1 << '\t' <<d_z2 << '\t' <<d_z3 << '\t' <<d_z4 << '\t' << y << '\t' << z << endl;

    while(x <= end){
        time++;
		
        //cout << time << fixed << setprecision(4)<<'\t' << x << '\t' << y << '\t' << z;
        
        d_y1 = fy(x, y, z);
        d_z1 = fz(x, y, z);

        d_y2 = fy(x+h/2, y+d_y1/2, z+d_z1/2);
        d_z2 = fz(x+h/2, y+d_y1/2, z+d_z1/2);

        d_y3 = fy(x+h/2, y+d_y2/2, z+d_z2/2);
        d_z3 = fz(x+h/2, y+d_y2/2, z+d_z2/2);

        d_y4 = fy(x+h/2, y+d_y3, z+d_z3);
        d_z4 = fz(x+h/2, y+d_y3, z+d_z3);

        y = y + (d_y1 + 2*d_y2 + 2*d_y3 + d_y4)/6;
        z = z + (d_z1 + 2*d_z2 + 2*d_z3 + d_z4)/6;
        
		x = x+h;
        cout << time << fixed << setprecision(4)<<'\t'<<d_y1 << '\t' <<d_y2 << '\t' <<d_y3 << '\t' <<d_y4 << '\t' <<d_z1 << '\t' <<d_z2 << '\t' <<d_z3 << '\t' <<d_z4 << '\t' << y << '\t' << z << endl;
    }

    return 0;
}

double fy(double x, double y, double z){
    return sin(2*(y*y)) + x + z;
}

double fz(double x, double y, double z){
    return x + y -2*(z*z) + 1;
}
