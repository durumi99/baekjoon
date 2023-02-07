#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	string s; cin >> s;
	for(int i = 0 ; i < s.length() ; i++) {
	    cout << s[i];
	    if((i+1) % 10 == 0)
	        cout << '\n';
	}
	return 0;
}