#include <iostream>

using namespace std;
const int MN = 101;
const int MK = 101010;
int n,k;
int w[MN];
int cost[MK];
int dp[MN][MK];

int main() {
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
        cin >> w[i] >> cost[i];
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= k ; j++){
            if(j < w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + cost[i]);
        }
    }  
    cout << dp[n][k];
    return 0;
}