#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> friends[30001];
vector<pair<int, int>> groupCandy;

int candy[30001];
int visited[30001];
int dp[3001];


pair<int, int> dfs(int idx) {
    // visited[idx] = 1;
    // pair<int, int> result;
    // for(int i = 0 ; i < friends[idx].size() ; i++) {
    //     if(!visited[friends[idx][i]]) {
    //         result = dfs(friends[idx][i]);
    //     }
    // }
    // result.first += candy[idx];
    // result.second ++;
    // return result;
    
    int s = 1;
    int c = candy[idx];
    visited[idx] = 1;
    
    for(int i = 0 ; i < friends[idx].size() ; i++) {
        if(!visited[friends[idx][i]]) {
            auto result = dfs(friends[idx][i]);
            s += result.first;
            c += result.second;
        }
    }
    return {s, c};
}
int main() {
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++)    
        cin >> candy[i];
    for(int i = 0 ; i < m ; i++) {
        int a, b; cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }   
    for(int i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            auto tmp = dfs(i);
            groupCandy.push_back(tmp);
        }
    }
    
    int maxCandy = 0;
    dp[0] = 0;
    for(auto gc : groupCandy) {
        for(int i = k - 1 ; i >= 0 ; i--) {
            if(i - gc.first >= 0) {
                dp[i] = max(dp[i], dp[i - gc.first] + gc.second);
                maxCandy = max(maxCandy, dp[i]);
            }
        }
    }
    cout << maxCandy;
    return 0;
}