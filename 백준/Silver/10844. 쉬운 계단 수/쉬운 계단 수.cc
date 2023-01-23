#include <iostream>
using namespace std;
#define MOD 1000000000
int N;

unsigned long long dp[101][10];
int main() {
	// your code goes here
	cin >> N;
	dp[1][0] = 0;
	for(int i = 1; i <= 9 ; i++)
		dp[1][i] = 1;
	for(int i = 2; i <= N ; i++) {
		dp[i][0] = dp[i-1][1];
		dp[i][9] = dp[i-1][8];
		for(int j = 1 ; j <= 8 ; j++) {
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
		}
	}
	
	long long ans = 0;
	for(int i = 0 ; i <= 9 ; i++){
		ans += dp[N][i] ;
	}
	cout << ans % MOD;
	
	return 0;
}