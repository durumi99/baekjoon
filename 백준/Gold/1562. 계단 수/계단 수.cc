#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000000

long long ans = 0;
long long dp[101][10][1 << 10];
int n;

int main() {
    cin >> n;
    int full = (1 << 10) - 1;
    for(int i = 1; i <= 9 ; i++)
        dp[1][i][1 << i] = 1;
        
    for(int i = 2 ; i <= n ; i++) {
        for(int j = 0 ; j <= 9 ; j++) {
            for(int k = 0 ; k <= full ; k++) {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
                else {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
                }
            }
        }
    }
    for (int j = 0 ; j <= 9; j++)
        ans = (ans + dp[n][j][full]) % mod;
        
    cout << ans;
    return 0;
}