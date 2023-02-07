#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double getDist(double Ax, double Ay, double Cx, double Cy) {
    return sqrt(pow(Ax - Cx,2) + pow(Ay - Cy,2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
		
	double  Ax, Ay, Bx, By, Cx, Cy, Dx, Dy; cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy ;
	double minDist;
	
	double mid1, mid2;
	int t = 100;
	
	while(t--) {
	    mid1 = getDist(Ax, Ay, Cx, Cy);
	    mid2 = getDist(Bx, By, Dx, Dy);
	    
	    if(mid1 >= mid2) {
	        Ax = Ax + (Bx - Ax) / 3;
	        Ay = Ay + (By - Ay) / 3;
	        Cx = Cx + (Dx - Cx) / 3;
	        Cy = Cy + (Dy - Cy) / 3;
	    } else if(mid1 < mid2) {
	        Bx = Bx - (Bx - Ax) / 3;
	        By = By - (By - Ay) / 3;
	        Dx = Dx - (Dx - Cx) / 3;
	        Dy = Dy - (Dy - Cy) / 3;
	    } else {
	        break;
	    }
	 }
	 
	minDist = min(mid1, mid2);
	printf("%.6f", minDist);
	
	return 0;
}