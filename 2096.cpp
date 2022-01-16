#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int n;
int num[100000][3];
pair<int,int> dp[3];
int main() {
    cin >> n;
    for(int i = 0 ; i < 3 ; i++){
        cin >> num[0][i];
        dp[i].first = dp[i].second = num[0][i];
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < 3 ; j++)
            cin >> num[i][j];
        pair<int,int> tmp[3];
        // 0
        tmp[0].first = max(dp[0].first,dp[1].first) + num[i][0];
        tmp[0].second = min(dp[0].second,dp[1].second) + num[i][0];
        // 1
        tmp[1].first = max( max(dp[0].first,dp[1].first),dp[2].first) + num[i][1];
        tmp[1].second = min( min(dp[0].second,dp[1].second),dp[2].second) + num[i][1];
        // 2
        tmp[2].first = max(dp[1].first,dp[2].first) + num[i][2];
        tmp[2].second = min(dp[1].second,dp[2].second) + num[i][2];
        
        for(int j = 0 ; j < 3 ; j++)
        	dp[j] = tmp[j];
    }  
    int maxScore = max( max(dp[0].first,dp[1].first),dp[2].first);
    int minScore = min( min(dp[0].second,dp[1].second),dp[2].second);
        
    cout << maxScore << ' ' << minScore << '\n';
    
    return 0;
}