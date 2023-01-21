#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// cout << 5266 % 15 << ' ' << 5266 % 28 << ' ' << 5266 % 19;
	int E, S, M; cin >> E >> S >> M;
	int year = 1;
	
	while(E != S || E != M) {
		if(E <= S && E <= M) {
			E += 15;
		} else if(S <= M && S <= E) {
			S += 28;
		} else {
			M += 19;
		}
		// cout << E << ' ' << S << ' ' << M << '\n';	
	}
	cout << E;
    return 0;
}