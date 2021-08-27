#include <iostream>

using namespace std;

int main() {
    int T ; cin >> T;
    for(int tc = 0 ; tc < T ; tc++){
        int n ; cin >> n;
        int coin[n];
        for(int i = 0 ; i < n ; i++)
            cin >> coin[i];
        int m ; cin >> m;
        int dp[m+1] = {0,};
        dp[0] = 1;
        for(int i = 0 ; i < n ; i++)
            for(int j = coin[i] ; j <= m ; j++)
                dp[j] += dp[j-coin[i]];
        cout << dp[m] << '\n';
    }
    return 0;
}