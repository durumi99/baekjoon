#include <iostream>
using namespace std;

int main() {
	int a=300,b=60,c=10;
	int n;
	cin >> n;
	if(n % c)
		cout << -1;
	else{
		cout << n / a << " ";
		n %= a;
		cout << n / b << " ";
		n %= b;
		cout << n / c;
	}
	return 0;
}