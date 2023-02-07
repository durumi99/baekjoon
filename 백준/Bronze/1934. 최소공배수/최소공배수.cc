#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
		
	int tc; cin >> tc;
	while(tc--) {
	    int a, b; cin >> a >> b;
	    cout << lcm(a, b) << '\n';
	}
	
	return 0;
}