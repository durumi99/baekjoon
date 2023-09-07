#include <iostream>
#include <bits/stdc++.h>
#define llu unsigned long long 

using namespace std;
int n;
int nums[101];
int rightN;
llu dp[101][21];

int main() {
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++) {
        cin >> nums[i];    
        
    }
    cin >> rightN;
    dp[0][nums[0]] = 1;
    
    for(int j = 1 ; j < n - 1 ; j++) {
        for(int k = 0 ; k <= 20 ; k++) {
            if(dp[j-1][k] == 0)
                continue;
            if(k + nums[j] <= 20) {
                dp[j][k + nums[j]] += dp[j-1][k];
            }
            if(k - nums[j] >= 0) {
                dp[j][k - nums[j]] += dp[j-1][k];
            }
        }
    }
    
    
    cout << dp[n-2][rightN];
    return 0;
}