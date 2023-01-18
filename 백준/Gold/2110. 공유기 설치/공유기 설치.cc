#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

bool check(int dist, vector <int> v) {
	int cnt = C;
	int cur = v[0];
	cnt--;
	for(int i = 1 ; i < N ; i++) {
		if(v[i] - cur >= dist) {
			cur = v[i];
			cnt--;
			if(cnt == 0)
				return true;
		}
	}
	return false;
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> N >> C;
    vector <int> v(N);
    for(int i = 0 ; i < N ; i ++) {
    	cin >> v[i];
    }
    sort(v.begin(), v.end());
    int end = v.back() - v.front()+1;
    int start = end;
    for(int i = 0 ; i < v.size()-1 ; i++) {
    	start = min(v[i+1] - v[i], start);
    }
    
    // cout << start << ' ' << end << '\n';
    while(start + 1 < end) {
    	int mid = (start + end) / 2;
    	
    	if(check(mid, v)) {
    		start = mid;
    	} else {
    		end = mid;
    	}
    }
    // cout << start << ' ' << end << '\n';
    cout << start;
    return 0;
}