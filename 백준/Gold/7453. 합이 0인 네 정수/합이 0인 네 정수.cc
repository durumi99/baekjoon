#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int A[4001], B[4001], C[4001], D[4001];
long long cnt = 0;
vector <int> v, vv;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		long long a, b, c, d; cin >> a >> b >> c >> d;
		A[i] = a;
		B[i] = b;
		C[i] = c;
		D[i] = d;
	}
	
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++){
			v.push_back(A[i] + B[j]);
			vv.push_back(C[i] + D[j]);
		}
	}
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	
	for(int i = 0 ; i < v.size() ; i++) {
		int left = lower_bound(vv.begin(), vv.end(), -v[i]) - vv.begin();
		int right = upper_bound(vv.begin(), vv.end(), -v[i]) - vv.begin();
		cnt += right - left;
	}
	
	cout << cnt;
	
	return 0;
}