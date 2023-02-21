#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

int N;
map <string, int> m;

bool cmp(pair<string, int>  a, pair<string, int>  b) {
	if(a.second == b.second) {
		return a.first < b.first;
	}
	
	return a.second > b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
	cin >> N;
	for(int i = 0 ; i < N ; i++) {
		string tmp; cin >> tmp;
		m[tmp]++;
	}
	vector < pair<string, int> > v (m.begin(), m.end());
	// sort(v.begin(), v.end(), cmp);
	
	cout << min_element(v.begin(), v.end(), cmp)->first << '\n';
	// cout << v[0].first;
	
    return 0;
}