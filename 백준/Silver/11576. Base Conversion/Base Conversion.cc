#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	// your code goes here
	int A, B; cin >> A >> B;
	int m; cin >> m;
	vector <string> v(m);
	for(int i = 0 ; i < m ; i++) {
		cin >> v[i];
		// cout << v[i] << ' ';
	}
	long long sum = 0;
	for(int i = 0 ; i < m ; i++) {
		sum *= (long long)A;
		long long tmp = stol(v[i]);
		sum += tmp;
	}
	// cout << sum << '\n';
	stack <long long> s;
	while(sum){
		long long tmp = sum % B;
		sum /= B;
		// cout << tmp << ' ';
		s.push(tmp);
	}
	
	while(!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}