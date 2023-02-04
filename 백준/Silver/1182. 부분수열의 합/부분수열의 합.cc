#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int N, S;
int num[20];
int ans = 0;
string s = "";

void backT(int idx, int sum) {
	if(idx == N) {
		if(sum == S) {
			ans++;
		}
		return;
	}
	
	backT(idx+1, sum+num[idx]);
	backT(idx+1, sum);
	
}
int main() {
	cin >> N >> S;
	for(int i = 0 ; i < N ; i++)
		cin >> num[i];
	sort(num, num+N);
	
	backT(0, 0);
	
	if(S == 0)
		ans--;
	cout << ans;
	return 0;
}