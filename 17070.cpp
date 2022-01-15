#include <iostream>

using namespace std;
int n;
int map[20][20];
int dp[20][20][20][20];

int main() {
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> map[i][j];
    dp[1][1][1][2] = 1;
    
    for(int i = 1; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++){
            if(map[i][j] == 1)
                continue;
            // 가로
            if(j-2 >= 1){
                dp[i][j-1][i][j] += dp[i][j-2][i][j-1];
                if(i-1 >= 1)
                    dp[i][j-1][i][j] += dp[i-1][j-2][i][j-1];
            }
            // 세로
            if(i-2 >= 1){
                dp[i-1][j][i][j] += dp[i-2][j][i-1][j];
                if(j-1 >= 1)
                    dp[i-1][j][i][j] += dp[i-2][j-1][i-1][j];
            }
            // 대각선
            
            if(map[i-1][j] == 0 && map[i][j-1] == 0){    
                if(i-1 >= 1 && j-2 >= 1)
                    dp[i-1][j-1][i][j]  += dp[i-1][j-2][i-1][j-1];
                if(i-2 >= 1 && j-1 >= 1)
                    dp[i-1][j-1][i][j]  += dp[i-2][j-1][i-1][j-1];
                if(i-2 >= 1 && j-2 >= 1)
                    dp[i-1][j-1][i][j]  += dp[i-2][j-2][i-1][j-1];
            }
        }
    cout << dp[n-1][n][n][n] + dp[n][n-1][n][n] + dp[n-1][n-1][n][n] << '\n'; 
    
    return 0;
}