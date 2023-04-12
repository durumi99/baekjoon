#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    int cur = 0;
    while(n){
		cur++;
		if(to_string(cur).find("666") != -1){
			n--;
		}
	}
	cout << cur;
    return 0;
}