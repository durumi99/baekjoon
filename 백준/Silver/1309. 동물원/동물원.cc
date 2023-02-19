#include <bits/stdc++.h>

#define MOD 9901
#define MAX 100001

using namespace std;

int N;
int dp[MAX][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    dp[1][0] = 1; // ox
    dp[1][1] = 1; // x0
    dp[1][2] = 1; // xx
    for(int i = 2 ; i <= N ; i++){
    	dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
    	dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
    	dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
    }
    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;
    return 0;
}