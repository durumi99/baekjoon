#include <bits/stdc++.h>
using namespace std;


int calLocation(int x1 ,int y1, int r2, int x2,int y2,int r1) {
	double rSum = abs(r1+r2);
	double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	
	if(dist == 0) {
		if(r1 == r2) {
			return -1;
		}
		return 0;
	}
	
	if(dist > rSum || dist+r1 < r2 || dist+r2 < r1) {
		 return 0;
	}  
	if(dist == rSum || dist+r1 == r2 || dist+r2 == r1) {
		 return 1;
	} 
	
	return 2;
}
int main() {
	// your code goes here
	int TC; cin >> TC;
	int x1 ,y1, x2, y2, r1, r2;
	while(TC--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << calLocation(x1 ,y1, r1, x2, y2, r2) << '\n';
	}
	return 0;
}