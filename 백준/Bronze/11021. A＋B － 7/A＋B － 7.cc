#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int TC; cin >> TC;
	for(int i = 1 ; i <= TC ; i++){
	    int a, b; cin >> a >> b;
	    cout << "Case #" << i << ": ";
	    cout << a + b << '\n';
	}
	return 0;
}