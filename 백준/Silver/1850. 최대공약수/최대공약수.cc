#include <iostream>
#include <algorithm>
#include <numeric>

#define llu unsigned long long

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
		
	// llu A, B;
	llu a, b; cin >> a >> b;
	
	for (int i = 0 ; i < gcd(a, b) ; i++)
	    cout << 1;
	return 0;
}