#include <iostream>
#define mod 10007
using namespace std;
int dp[1001][1001];
void setDP(){
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2 ; i <= 1000 ; i++){
        dp[i][0] = dp[i][i] = 1; 
        for(int j = 1; j <= i ; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
    }
}
int n,k;

int main() {
    cin >> n >> k;
    setDP();
    cout << dp[n][k];
    return 0;
}