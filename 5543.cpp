#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3],b[2];
	cin >> a[0];
	cin >> a[1];
	cin >> a[2];
	cin >> b[0];
	cin >> b[1];
	
	sort(a,a+3);
	sort(b,b+2);
	cout << a[0]+b[0]-50;
	return 0;
}