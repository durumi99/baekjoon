#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	string s;
	while(getline(cin, s)){
	    cout << s << '\n';
	}
	return 0;
}