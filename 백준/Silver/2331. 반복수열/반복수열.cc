#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int sumofPow(int n, int p) {
	int tmp = 0;
	while(n) {
		tmp += pow((n%10), p);
		n /= 10;
	}
	return tmp;
}
int main() {
	int a, p; cin >> a >> p;
	vector <int> v;
	v.push_back(a);
	while(true){
		int next = sumofPow(v.back(), p);
		// cout << next << ' ';
		auto idx = find(v.begin(), v.end(), next);
		if(idx != v.end()) {
			cout << idx - v.begin();
			break;
		}
		
		v.push_back(next);
	}
	return 0;
}