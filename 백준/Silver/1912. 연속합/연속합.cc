#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[1000001];
long long dp[1000001];

int main() {
	// your code goes here
	cin >> N;
	for(int i = 0 ; i < N ; i++)
		cin >> arr[i];
	dp[0] = arr[0];
	long long ans = -1000;
	for(int i = 0 ; i < N ; i++) {
		dp[i] = max(dp[i-1]+arr[i], arr[i]);
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	return 0;
}