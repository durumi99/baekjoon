#include <iostream>
using namespace std;
long long dp[44];
int vip[44];
int main() {
    int n,m ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        cin >> vip[i];
    }
    
    dp[0] = dp[1] = 1;
    for(int i = 2 ; i <= n ; i++ )
        dp[i] = dp[i-1] + dp[i-2];
        
    int ans = 1; 
    for(int i = 1 ; i <= m ; i++){   
        ans *= dp[vip[i]-vip[i-1]-1];
    }
    ans *= dp[n-vip[m]];
    cout << ans;
    return 0;
}