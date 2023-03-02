#include <bits/stdc++.h>
using namespace std;

int dp[100000][3];
int solution(vector<int> sticker)
{
    int n = sticker.size();
    if(n < 4){
        return *max_element(sticker.begin(), sticker.end());
    }
    int answer = 0;
    dp[0][0] = sticker[0];
    dp[1][1] = sticker[1];
    dp[2][2] = sticker[2];
    dp[2][0] = sticker[0] + sticker[2];
    
    for(int i = 3 ; i < n; i++) {
        for(int j = 0 ; j < 3 ; j++)
            dp[i][j] = max(dp[i-2][j], dp[i-3][j]) + sticker[i];
    }
    answer = max(max(max(dp[n-2][0], dp[n-2][1]), max(dp[n-1][1], dp[n-1][2])), dp[n-3][0]);

    return answer;
}