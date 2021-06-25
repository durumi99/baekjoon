#include <iostream>
using namespace std;

int main() {
	int s,k,h;
	cin >> s >> k >> h;
	if(s+k+h >= 100)
		cout << "OK";
	else{
		if(s == min(s,min(k,h)))
			cout << "Soongsil";
		else if(k == min(s,min(k,h)))
			cout << "Korea";
		else
			cout << "Hanyang";
	}
	return 0;
}