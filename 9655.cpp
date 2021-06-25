#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n ;
	if((n-1)% 4 == 0 || (n-3) % 4 ==0)
		cout << "SK";
	else
		cout << "CY";
	return 0;
}