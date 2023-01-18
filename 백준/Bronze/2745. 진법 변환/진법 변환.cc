#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string s;
	int n;
	cin >> s >> n;
	long long ans = 0;
	for(int i = 0 ; i < s.length() ; i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			ans += s[i] - 'A' + 10;
		} else {
			ans += s[i] - '0' ;
		}
		ans *= n;
	}
	cout << ans / n;
	return 0;
}