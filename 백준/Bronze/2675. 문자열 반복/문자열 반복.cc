#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc,r;
	string s;
	cin >> tc;
	for(int i = 0 ; i < tc ; i++){
		cin >> r >> s;
		for(int j = 0 ; j < s.size(); j++){
			for(int k = 0 ; k < r ; k++)
				cout << s[j];
		}
		cout << endl;
	}
	return 0;
}