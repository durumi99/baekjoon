#include <iostream>
using namespace std;

int main() {
	int a,b;
	string s;
	cin >> s;
	if(s.size() == 2){
		a = s[0]-48;
		b = s[1]-48;
	}
	else if(s.size() == 4)
		a = b =10;
	else {
		if(s[1] == '0'){
			a = 10;
			b = s[2]-48;
		}
		else{
			a = s[0]-48;
			b = 10;
		}
	}
	cout << a+b;
	return 0;
}