#include <bits/stdc++.h>

#define MAX 1e9
using namespace std;

int dp[501][501];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = MAX;
    int goalAlp = alp;
    int goalCop = cop;
    
    vector <int> tmp[2];
    tmp[0].push_back(0);
    tmp[0].push_back(0);
    tmp[0].push_back(1);
    tmp[0].push_back(0);
    tmp[0].push_back(1);
    tmp[1].push_back(0);
    tmp[1].push_back(0);
    tmp[1].push_back(0);
    tmp[1].push_back(1);
    tmp[1].push_back(1);
    problems.push_back(tmp[0]);
    problems.push_back(tmp[1]);
    
    for(auto problem : problems) {
        goalAlp = max(goalAlp, problem[0]);
        goalCop = max(goalCop, problem[1]);
    }
    
    for(int i = alp ; i <= goalAlp ; i++) {
        for(int j = cop ; j <= goalCop ; j++) {
            dp[i][j] = MAX;
        }
    }
    
    dp[alp][cop] = 0;
    
    for(int i = alp ; i <= goalAlp ; i++) {
        for(int j = cop ; j <= goalCop ; j++) {
            // if(i + 1 <= 300)
            //     dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            // if(j + 1 <= 300)    
            //     dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            
            for(auto problem : problems) {
                int alp_req = problem[0];
                int cop_req = problem[1];
                int alp_rwd = problem[2];
                int cop_rwd = problem[3];
                int cost = problem[4];
                
                if(i >= alp_req && j >= cop_req) {
                    int tmpAlpRwd = i + alp_rwd;
                    int tmpCopRwd = j + cop_rwd;
                    tmpAlpRwd = min(tmpAlpRwd, goalAlp);
                    tmpCopRwd = min(tmpCopRwd, goalCop);
                    dp[tmpAlpRwd][tmpCopRwd] = min(dp[tmpAlpRwd][tmpCopRwd], dp[i][j] + cost);
                    // dp[i + alp_rwd][j + cop_rwd] = min(dp[i + alp_rwd][j + cop_rwd], dp[i][j] + cost);
                    
                }
            }
        }
    }
    answer = dp[goalAlp][goalCop];
    return answer;
}