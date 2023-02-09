#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int ans;
vector <int> v(8);
int visited[8];
int getSum(vector <int> tmp) {
	int sum = 0;
	for(int i = 0 ; i < N-1 ; i++) {
		sum += abs(tmp[i]- tmp[i+1]);
	}
	return sum;
}
void BT(vector <int> tmp, int idx) {
	if(idx == N) {
		ans = max(ans, getSum(tmp));
		return;
	}
	for(int i = 0 ; i < N ; i++) {
		if(!visited[i]) {
			tmp.push_back(v[i]);
			visited[i] = 1;
			BT(tmp, idx+1);
			visited[i] = 0;
			tmp.pop_back();
		}
	}
}
int main() {
	cin >> N;
	
	for(int i = 0 ; i < N ; i++) {
		cin >> v[i];
	}
	vector <int> tmp;
	BT(tmp, 0);
	cout << ans;
	return 0;
}