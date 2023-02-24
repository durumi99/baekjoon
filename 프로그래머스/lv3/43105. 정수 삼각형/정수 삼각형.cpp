#include <bits/stdc++.h>

#define MAX 501
using namespace std;

int dp[MAX][MAX];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    dp[0][0] = triangle[0][0];
    
    for(int i = 1 ; i < triangle.size(); i++) {
        for(int j = 0 ; j < triangle[i].size() ; j++) {
            dp[i][j] = triangle[i][j];
            if(j-1 < 0) {
                dp[i][j] += dp[i-1][j];
            } else if(j >= triangle[i-1].size()) {
                dp[i][j] += dp[i-1][j-1];
            } else {
                dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            }
            
        }
    }
    answer = *max_element(dp[height-1], dp[height-1]+height);

    return answer;
}
