#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if( n == 1){
		cout << 1;
		return 0;
	}
	if (n >= 2 && n <= 7){
		cout << 2;
		return 0;
	}
	long long tmp = (n-2) / 6;
	long long k = 2;
	while(k++){
		long long left = (k-1)*(k-2)/2;
		long long right = k*(k-1)/2-1;
		if(left <= tmp && tmp <= right){
			cout << k;
			break;
		}
	}
	return 0;
}