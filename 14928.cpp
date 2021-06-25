#include <iostream>
using namespace std;

int main() {
	string n;
	cin >> n;
	int tmp=0;
	for(int i = 0 ; i < n.length(); i++)
		tmp = (tmp * 10 +(n[i]-'0'))% 20000303;
	cout << tmp;
}