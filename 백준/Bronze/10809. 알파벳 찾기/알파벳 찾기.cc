#include <iostream>
#include <string>
using namespace std;

int main() {
	int apb[26];
	for(int i = 0 ; i < 26 ; i++){
		apb[i] = -1;
	}
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++){
		if(apb[s[i] - 'a'] == -1)
			apb[s[i] - 'a'] = i;
	}
	for(int i = 0 ; i < 26 ; i++){
		cout << apb[i] << ' ';
	}
 	return 0;
}