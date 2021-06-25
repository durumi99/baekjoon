#include <iostream>
using namespace std;

int main() {
	int hr,min,tmp;
	cin >> hr >> min;
	tmp = hr * 60 + min;

	if(tmp < 45)
		tmp += 24 * 60;
	tmp -= 45;
	hr = tmp / 60;
	min = tmp % 60;
	cout << hr << ' ' << min << endl;
	return 0;
}