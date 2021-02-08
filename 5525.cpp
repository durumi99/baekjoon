#include <iostream>
#include <string>
using namespace std;
int main() {
	int n,m,cnt = 0;
	string s;
	string str("I");
	cin >> n >> m >> s;
	for(int i = 0 ; i < n ; i++)
		str.append("OI");
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i+1] == 'O' && s[i+2] == 'I'){
			int O = 0;
			while(s[i] == 'I' && s[i+1] == 'O'){
				i+=2;
				O++;
				if(s[i] == 'I' && O == n){
					O--;
					cnt++;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}