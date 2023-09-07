#include <iostream>
#include <bits/stdc++.h>
#define llu unsigned long long 

using namespace std;
int n;
int nums[101];
int rightN;
llu dp[101][101][21];
llu ans;

int main() {
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++) {
        cin >> nums[i];    
        dp[i][i][nums[i]] = 1;
    }
    cin >> rightN;
    for(int i = 0 ; i < n - 2; i++) {
        for(int j = i + 1 ; j < n - 1 ; j++) {
            for(int k = 0 ; k <= 20 ; k++) {
                if(dp[i][j-1][k] == 0)
                    continue;
                if(k + nums[j] <= 20) {
                    dp[i][j][k + nums[j]] += dp[i][j-1][k];
                }
                if(k - nums[j] >= 0) {
                    dp[i][j][k - nums[j]] += dp[i][j-1][k];
                }
            }
        }
    }
    
    cout << dp[0][n-2][rightN];
    return 0;
}