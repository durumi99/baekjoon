#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n ;
	cin >> n;
	vector< pair<int,int> > v(n);
	vector<int> ans(n);
	for(int i = 0 ; i < n ; ++i){
		cin >> v[i].first;
        v[i].second = i;
	}
	sort(v.begin(),v.end());

	int cnt = 0;
	for(int i = 0 ; i < n ; ++i){
		int idx = v[i].second;
		int tmp = cnt;
		
		ans[idx] = tmp;
		cnt++;
		
		while(i < n && v[i].first == v[i+1].first){
			i++;
			idx = v[i].second;
			ans[idx] = tmp;
		}
	}
	for(int i = 0 ; i <  n ; i ++){
			cout << ans[i] << ' ';
	}
}