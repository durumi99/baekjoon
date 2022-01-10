#include <iostream>
using namespace std;
long long miro[101][101];
long long dp[101][101];
int n;
void setDP(){
    dp[1][1] = 1;
    int tmp;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(miro[i][j] == 0)
                continue;
            tmp = miro[i][j];
            if(j+tmp <= n)
                dp[i][j+tmp] += dp[i][j];
            if(i+tmp <= n)
                dp[i+tmp][j] += dp[i][j]; 
        }
    }
    return;
}
int main() {
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> miro[i][j];
    setDP();
    cout << dp[n][n];
    return 0;
}