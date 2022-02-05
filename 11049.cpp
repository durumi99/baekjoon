#include <iostream>
#include <algorithm>

#define MAX 555
#define INF 1e9
using namespace std;
int n;
int dp[MAX][MAX];
int m[MAX][2];

void input(){
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> m[i][0] >> m[i][1];    
}
void solve(){
    for(int i = 1; i < n ; i++){
        for(int j = 0 ; j + i < n ; j++){
            dp[j][j+i] = INF;
            for(int k = j ; k <= i + j ; k++){
                dp[j][j+i] = min(dp[j][j+i],
                dp[j][k] + dp[k+1][j+i] + m[j][0] * m[k][1] * m[j+i][1]
                );
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}
int main() {
    input();
    solve();
    return 0;
}