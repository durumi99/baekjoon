#include <string>
#include <vector>
#include <bits/stdc++.h>

#define MAX 20001
using namespace std;

vector <int> v[MAX];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxDist = -1;
    for(int i = 0 ; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int visited[MAX] = {0, };
    visited[1] = 1;
    
    queue <int> q;
    q.push(1);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 0 ; i < v[cur].size(); i++) {
            int next = v[cur][i];
            if(visited[next]) {
                continue;
            }
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
    
    for(int i = 1 ; i <= n ; i++) {
        if(visited[i] > maxDist) {
            maxDist = visited[i];
            answer = 1;
        } else if(visited[i] == maxDist) {
            answer++;
        }
    }
    return answer;
}