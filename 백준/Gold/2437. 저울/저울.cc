#include <bits/stdc++.h>

#define MAX 1000000001

using namespace std;

int n;
vector <int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	int res = 1;
    for (int i = 0; i < n; i++) {
        if (v[i] > res) {
            break;
        }
        res += v[i];
    }
 
    cout << res;
    return 0;
}