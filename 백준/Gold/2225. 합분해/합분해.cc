#include <iostream>
#include <cmath>
#define MOD 1000000000

using namespace std;

long long dp[201][201];
int N, K;

void makeDP() {
	for(int i = 0 ; i <= N ; i++)
		dp[i][1] = 1;

	for (int n = 0; n <= N; n++)
    {
        for (int k = 2 ; k <= K; k++)
        {
            for (int i = 0; i <= n; i++)
            {
                dp[n][k] += dp[i][k-1];
            }
            dp[n][k] %= MOD;
        }
    }
	
}
int main() {
	cin >> N >> K;
	
	makeDP();

	cout << dp[N][K];
	return 0;
}