#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
const int INF = 1e9 + 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int N; cin >> N;
	vector < pair<int, int> > v;
	for(int i = 0 ; i < N ; i++) {
		int x, y; cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	int tmp = 0;
	int ans = 0;
	int l = -INF, r = -INF;
	
	for(int i = 0 ; i < N ; i++) {
		if(v[i].first < r) {
			r = max(r, v[i].second);
		} else {
			ans += r-l;
			l = v[i].first;
			r = v[i].second;
		}
		
	}
	ans += r - l;
	cout << ans;
	return 0;
}