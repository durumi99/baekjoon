#include <iostream>
using namespace std;

int main() {
	int n,w,h,l;
	cin >> n >> w >> h >> l;
	int a;
	a = (w/l)*(h/l);
	cout << min (a,n);
	return 0;
}