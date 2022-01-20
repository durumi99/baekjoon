#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 111
#define INF 1e9
using namespace std;
int n,m,r;
int item[111];
int answer = 0;
vector<pair<int,int>> g[MAX];
priority_queue<pair<int,int>> pq;
int dijkstra(int start){
    vector <int> dist(MAX,INF);
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[cur] < cost) 
            continue;
        for(int i = 0 ; i < g[cur].size(); i++){
            int next = g[cur][i].first;
            int nCost = g[cur][i].second + cost;
            if(dist[next] > nCost){
                dist[next] = nCost;
                pq.push({-nCost,next});
            }
        }
    }
    int maxItem = 0;
    for(int i = 1 ; i <= n ; i++){
        if(dist[i] <= m)
            maxItem += item[i];
    }
    return maxItem;
}
void input(){
    cin >> n >> m >> r;
    for(int i = 1 ; i <= n ; i++){
        cin >> item[i];
    }
    int a,b,l;
    for(int i = 1 ; i <= r ; i++){
        cin >> a >> b >> l;
        g[a].push_back({b,l});
        g[b].push_back({a,l});
    }
}
void result(){
    for(int i = 1 ; i <= n ; i++)
        answer = max(answer,dijkstra(i));
    cout << answer << '\n';
}
int main() {
    input();
    result();
    return 0;
}