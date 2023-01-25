#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	string a,b,c,d; cin >> a >> b >> c >> d;
	
	a += b;
	c += d;
	// cout << a << ' ' << c << '\n';
	cout << stol(a) + stol(c);
	return 0;
}