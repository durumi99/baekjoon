#include <iostream>
#include <cmath>
using namespace std;
long long miro[1001][1001];
long long dp[1001][1001];
int n,m;
void setDP(){
   for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + miro[i][j]; 
        }
   }
   
   return;
}
int main() {
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> miro[i][j];
    setDP();
    cout << dp[n][m];
    return 0;
}