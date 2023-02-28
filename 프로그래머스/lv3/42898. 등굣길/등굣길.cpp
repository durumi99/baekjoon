#include <bits/stdc++.h>

#define MAX 101
#define MOD 1000000007
using namespace std;

int arr[MAX][MAX];
int dp[MAX][MAX];

int dy[2] = {1, 0};
int dx[2] = {0, 1};

void makeDP(int m, int n) {
    dp[1][0] = 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            if(arr[i][j] == 1)
                continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(auto puddle : puddles) {
        arr[puddle[1]][puddle[0]] = 1;
    }
    makeDP(m, n);
    // for(int i = 1 ; i <= n ; i++) {
    //     for(int j = 1 ; j <= m ; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    answer = dp[n][m];
    return answer;
}