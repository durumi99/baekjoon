#include <string>
#include <vector>
#include <queue>
#include <utility>

#define INF 9999999
#define MAX 202

using namespace std;
vector < pair <int,int> > vertex[MAX];
int N, A, B;
int distFromStart[MAX];

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

void setMinDistFromStart (int s) {
    priority_queue < pair <int,int> > pq;

    for(int i = 1 ; i <= N ; i++)
        distFromStart[i] = INF;
    
    pq.push({0, s});
    distFromStart[s] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < vertex[cur].size(); i++){
            int next = vertex[cur][i].first;
            int ncost = vertex[cur][i].second;
            if(distFromStart[next] > cost + ncost){
                distFromStart[next] = cost + ncost;
                pq.push({-distFromStart[next],next});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    N = n;
    A = a;
    B = b;
    setMap(fares);
    setMinDistFromStart(s);
    
    for (int i = 1 ; i <= N ; i++) {
        int distSum = distFromStart[i] + getRemainDists(i);
        answer = answer > distSum ? distSum : answer;
    }
    
    return answer;
}
