#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int l,a,b,c,d,tmpA,tmpB;
	cin >> l;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	if(a % c == 0)
		tmpA = a/c;
	else
		tmpA = a/c+1;
	if(b % d == 0)
		tmpB = b/d;
	else
		tmpB = b/d+1;
	cout << l-max(tmpA,tmpB);
	return 0;
}