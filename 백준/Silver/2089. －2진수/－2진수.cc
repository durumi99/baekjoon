#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
	int n; cin >> n;
	stack <int> s;
	if (n == 0 ){
		s.push(0);
	}
	while (n != 0) {
		if(n % -2 == 0) {
			s.push(0);
			n /= -2;
		} else {
			s.push(1);
			n = (n-1) / -2;
		}
	}
	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}