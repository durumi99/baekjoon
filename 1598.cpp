#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int tmp1,tmp2,dis;
	cin >> tmp1 >> tmp2;
	dis += abs( (tmp1-1) % 4 - (tmp2-1) % 4);
	dis += abs( (tmp1-1) / 4 - (tmp2-1) / 4);
	cout << dis << endl;
	return 0;
}