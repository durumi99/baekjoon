#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a[4],b[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	cin >> b[0] >> b[1] >> b[2] >> b[3];
	int s=0,t=0;
	for(int i = 0 ; i < 4 ; i++){
		s+=a[i];
		t+=b[i];
	}
	cout << max(s,t);
	return 0;
}