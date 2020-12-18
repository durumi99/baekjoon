#include <iostream>
using namespace std;

int main() {
	int sum, dif,a,b;
	cin >> sum >> dif;
	if((sum+dif) % 2 || dif > sum)
		cout << -1;
	else {
		a = (sum+dif) / 2;
		b = (sum-dif) / 2;
		cout << a << " " << b;
	}
	return 0;
}