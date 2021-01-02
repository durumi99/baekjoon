#include <iostream>

using namespace std;

int main() {
	int tc;
	string s;
	cin >> tc;
	for(int i = 0 ; i < tc ; i++ ){
		int grade = 0,tmp = 0;
		cin >> s;
		for(int j = 0 ; j < s.size(); j++){
			if(s[j] == 'O'){
				tmp++;
				grade += tmp;
			}
			else
				tmp = 0;
		}
		cout << grade << endl;
	}
	return 0;
}