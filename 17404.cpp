#include <iostream>
#include <algorithm>

#define MAX 1001
#define INF 10000001
using namespace std;
int n;
int RGB[MAX][3];
int ans = INF;
void input(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < 3 ; j++)
            cin >> RGB[i][j];
}
void solve(){
    for(int start  = 0 ; start < 3 ; start++){
        int dp[MAX][3];
        for(int i = 0 ; i < 3 ; i++){
            if(i == start )
                dp[0][start] = RGB[0][start];
            else
                dp[0][i] = INF;
        }
        
        for(int i = 1 ; i < n ; i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + RGB[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + RGB[i][1];
            dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + RGB[i][2];
        }
        
        for(int i = 0 ; i < 3 ; i++){
            if(i == start)
                continue;
            ans = min(ans,dp[n-1][i]);
        }
    }
    
    cout << ans << '\n';
}
int main() {
    input();
    solve();
    return 0;
}