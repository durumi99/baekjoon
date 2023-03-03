#include <bits/stdc++.h>

#define MAX 1000001
using namespace std;

int dp[MAX][3];

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    if(n < 4){
        return *max_element(money.begin(), money.end());
    }
    dp[0][0] = money[0];
    dp[1][1] = money[1];
    dp[2][2] = money[2];
    dp[2][0] = money[0] + money[2];
    
    for(int i = 3 ; i < money.size() ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            dp[i][j] = max(dp[i-2][j], dp[i-3][j]) + money[i];
        }
    }
   
     answer = max(max(max(dp[n-2][0], dp[n-2][1]), max(dp[n-1][1], dp[n-1][2])), dp[n-3][0]);
    
    return answer;
}