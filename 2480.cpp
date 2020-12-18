#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3,greater <int>());
	if(a[0] == a[2])
		cout << 10000+a[0]*1000;
	else if (a[0] == a[1] && a[1] != a [2])
		cout << 1000+a[0]*100;
	else if (a[1] == a[2] && a[0] != a [1])
		cout << 1000+a[1]*100;
	else
		cout << a[0]*100;
	return 0;
}