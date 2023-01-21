#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	vector <int> v(N);
	for(int i = 0 ; i < N ; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i = 0 ; i < N ; i++) {
		// cout << v[i] << ' ' << ans << '\n';
		if(i == N-1) {
			ans += v[i];
		}
		else if(v[i] < 0) {
			if(v[i+1] <= 0) {
				ans += v[i] * v[i+1];
				i++;
			} else {
				ans += v[i];
			}
		} else if(v[i] == 0) {
			continue;
		} else {
			if(!((N - i) % 2)) {
				ans += max(v[i] * v[i+1], v[i] + v[i+1]);
				i++;
			} else {
				ans += v[i];
			}
		}
	}
	cout << ans;
    return 0;
}