#include <iostream>

using namespace std;

int dp[33][33];
void f(){
    for(int i = 1 ; i <= 30 ; i++){
        dp[i][1] = i;
        dp[i][i] = 1;
    }
    for(int i = 2 ; i <= 30 ; i++){
        for(int j = 2 ; j < i ; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
}
int main() {
    int tc; cin >> tc;
    f();
    for(int i = 0 ; i < tc; i++){
        int n,m; cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
    return 0;
}