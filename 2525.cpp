#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b;
	cin >> c;
	a += c / 60;
	b += c % 60;
	if(b > 59){
		b -= 60;
		a += 1;
	}
	if(a >23){
		a -= 24;
	}
	cout << a << ' ' << b;
	return 0;
}