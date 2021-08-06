#include <iostream>
using namespace std;
long long dp[101010][4] ;
void setDP(){
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int i = 4 ; i <= 100000 ; i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % 1000000009;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % 1000000009;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % 1000000009;
    }
}
int main() {
    setDP();
    int tc,tmp; cin >> tc;
    for(int i = 0 ; i < tc ; i++){
        cin >> tmp;
        cout << (dp[tmp][1] + dp[tmp][2] + dp[tmp][3]) % 1000000009 << '\n';
    }
    return 0;
}