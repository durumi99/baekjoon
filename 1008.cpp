#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double n,m;
	cin >> n >> m;
	cout.setf(ios::fixed);	
	cout.precision(9);
	cout << n / m;
	
	return 0;
}