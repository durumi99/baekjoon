#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9
#define MAX 888

using namespace std;

vector <pair<int,int>> v[MAX];

int n,e,v1,v2;
long long int answer = -1;
long long int dijkstra(int start, int end){
    priority_queue<pair<int,int>> pq;
    vector<int> dist(MAX,INF);
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[cur] < cost) continue;
        for(int i = 0 ; i < v[cur].size() ; i++){
            int next = v[cur][i].first;
            int nCost = v[cur][i].second + cost;
            if(dist[next] > nCost){
                dist[next] = nCost;
                pq.push({-nCost,next});
            }
        }
    }
    return dist[end];
}
int main() {
    cin >> n >> e;
    int a,b,c;
    for(int i = 0 ; i < e ; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin >> v1 >> v2;
    answer = min( dijkstra(1,v1) + dijkstra(v2,n), dijkstra(1,v2) + dijkstra(v1,n) ) + dijkstra(v1,v2);
    if(answer >= INF || answer < 0)
        cout << -1 << '\n';
    else
        cout << answer << '\n';
    return 0;
}