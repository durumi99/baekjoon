#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int dp[31];

int main() {
	// your code goes here
	cin >> N;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	for(int i = 4 ; i <= N ; i++){
		dp[i] = dp[i-2];
		for(int j = i - 2 ; j >= 0 ; j -= 2)
			dp[i] += dp[j] * 2;
	}
	cout << dp[N];
	return 0;
}