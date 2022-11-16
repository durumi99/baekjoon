#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

#define INF 9999999
#define MAX 202

using namespace std;
// int map[222][222] = {0,};
vector < pair <int,int> > vertex[MAX];
vector < pair <int,int> > floydMap[MAX];
int visited[222] = {0,};
int N, A, B;
int answer = INF;
int dp[MAX];

void setMap (vector< vector<int> > fares) {
    for(int i = 0 ; i < fares.size() ; i++){
        int u = fares[i][0];
        int v = fares[i][1];
        int w = fares[i][2];
        vertex[u].push_back({v,w});
        vertex[v].push_back({u,w});
    }
}

int getRemainDists (int start) {
    priority_queue < pair <int,int> > pq;
    int dist[MAX];
    for(int i = 1 ; i <= N ; i++)
        dist[i] = INF;
    
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < vertex[cur].size(); i++){
            int next = vertex[cur][i].first;
            int ncost = vertex[cur][i].second;
            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({-dist[next],next});
            }
        }
    }
    
    return dist[A] + dist[B];
}
void dfs (int cur, int curDist) {
    int remainDist = getRemainDists(cur);
    int distSum = curDist + remainDist;
    answer = answer > distSum ? distSum : answer;
    
    for (int i = 0 ; i < vertex[cur].size() ; i++) {
        int next = vertex[cur][i].first;
        int ncost = vertex[cur][i].second;
        if (visited[next]) {
            continue;
        }
        visited[next] = 1;
        dfs(next, curDist + ncost);
        visited[next] = 0;
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    A = a;
    B = b;
    setMap(fares);
    visited[s] = 1;
    
    priority_queue < pair <int,int> > pq;
    int dist[MAX];
    for(int i = 1 ; i <= N ; i++)
        dist[i] = INF;
    
    pq.push({0, s});
    dist[s] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < vertex[cur].size(); i++){
            int next = vertex[cur][i].first;
            int ncost = vertex[cur][i].second;
            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({-dist[next],next});
            }
        }
    }
    
    for (int i = 1 ; i <= N ; i++) {
        // cout << dist[i] << ' ';
        int distSum = dist[i] + getRemainDists(i);
        answer = answer > distSum ? distSum : answer;
    }
    return answer;
}