#include <iostream>
using namespace std;
#define MOD 10007
int N;

long long dp[1001][10];
int main() {
	// your code goes here
	cin >> N;

	for(int i = 0; i <= 9 ; i++)
		dp[1][i] = 1;
	for(int i = 2; i <= N ; i++) {
		for(int j = 0 ; j <= 9 ; j++) {
			for(int k = 0 ; k <= j ; k++){
				dp[i][j] += dp[i-1][k] % MOD;
			}
		}
	}
	long long ans = 0;
	for(int i = 0 ; i <= 9 ; i++){
		ans += dp[N][i] % MOD;
	}
	cout << ans % MOD;
	
	return 0;
}