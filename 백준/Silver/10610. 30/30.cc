#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s; cin >> s;
	bool check = false;
	int tmp = 0;
	for(int i = 0 ; i < s.length(); i++) {
		if(!check && s[i] == '0') {
			check = true;
		}
		tmp = (tmp + (s[i]-'0')) % 3;
	}
	if(tmp != 0 || !check) {
		cout << -1;
	} else {
		sort(s.begin(), s.end(), greater<int> ());
		cout << s;
	}
    return 0;
}