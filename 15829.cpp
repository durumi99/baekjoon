#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int l;
	unsigned long long res = 0, mul = 1;
	int r = 31, m = 1234567891;
	string str;
	cin >> l;
	cin >> str;
	
	for(int i = 0 ; i < l ; i++){
		res = (res+(str[i]- 'a'+1)*mul) % m;
		mul = (mul*r) % m;
	}
	cout << res;
	return 0;
}