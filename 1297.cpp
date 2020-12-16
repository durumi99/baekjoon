#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int r,x,y,a,b;
	cin >> r >> x >> y;
	a = r * x / sqrt(pow(x,2)+pow(y,2));
	b = r * y / sqrt(pow(x,2)+pow(y,2));
	cout << a << " " << b;
	
	return 0;
}