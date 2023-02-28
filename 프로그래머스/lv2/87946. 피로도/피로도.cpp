#include <bits/stdc++.h>

using namespace std;

int visited[10];
int answer = 0;

void dfs(int k, vector<vector<int>> dungeons, int cnt) {
    if(k < 0) {
        answer = max(cnt, answer);
        return;
    }
    
    for(int i = 0 ; i < dungeons.size() ; i++) {
        if(visited[i])
            continue;
        if(k < dungeons[i][0])
            continue;
        visited[i] = 1;
        dfs(k - dungeons[i][1], dungeons, cnt + 1);
        visited[i] = 0;
    }
    answer = max(cnt, answer);
}
int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, dungeons, 0);
    return answer;
}