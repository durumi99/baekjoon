#include <iostream>
using namespace std;

int main() {
	int a,b,c,d,p;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> p;
	int feeA = a*p;
	int feeB = p < c ? b : (b+(p-c)*d);
	cout << min(feeA,feeB);
	return 0;
}