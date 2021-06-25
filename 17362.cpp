#include <iostream>
using namespace std;
#define PI 3.141592
int main() {
	int n;
	cin >> n;
	if(n % 8 == 1)
		cout << 1;
	else if(n % 8 == 0 || n % 8 == 2 )
		cout << 2;
	else if(n % 8 == 3 || n % 8 == 7 )
		cout << 3;
	else if(n % 8 == 4 || n % 8 == 6 )
		cout << 4;
	else
		cout << 5;
	return 0;
}