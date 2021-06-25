#include <iostream>
using namespace std;

int main() {
	int a,b,c,d;
	cin >> a >> b >> c;
	cin >> d;
	a += d / 3600;
	d %= 3600;
	b += d / 60;
	c += d % 60;
	if(c > 59){
		c -= 60;
		b += 1;
	}
	if(b > 59){
		b -= 60;
		a += 1;
	}
	if(a > 23){
		a %= 24;
	}
	cout << a << ' ' << b << ' ' << c;
	return 0;
}