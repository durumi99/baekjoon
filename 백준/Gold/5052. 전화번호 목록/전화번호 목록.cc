#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

int n;
vector <string> v;

bool checkConsistency() {
	for(int i = 0 ; i < n - 1 ; i++) {
		int curLen = v[i].length();
		int nextLen = v[i+1].length();
		
		if(curLen >= nextLen)
			continue;
		
		string sub = v[i+1].substr(0, curLen);
		if(sub == v[i]) {
			return false;
		}
	}
	
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
	int tc; cin >> tc;
	while(tc--) {
		v.clear();
		cin >> n;
		for(int i = 0 ; i < n ; i++) {
			string tmp; cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		
		if(checkConsistency()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}