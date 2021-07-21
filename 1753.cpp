#include <iostream>
#include <queue>
#include <vector>

#define MAX 20010
#define INF 987654321

using namespace std;

int vv,e,start,u,v,w;
int dist[MAX];
vector < pair <int,int> > vertex[MAX];
priority_queue < pair <int,int> > pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> vv >> e >> start;
    for(int i = 0 ; i < e ; i++){
        cin >> u >> v >> w;
        vertex[u].push_back({v,w});
    }
    for(int i = 1 ; i <= vv ; i++)
        dist[i] = INF;
        
    pq.push({0,start});
    dist[start] = 0;
    
    while(pq.empty() == 0){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < vertex[cur].size();i++){
            int next = vertex[cur][i].first;
            int ncost = vertex[cur][i].second;
            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({-dist[next],next});
            }
        }
    }
    
    for(int i = 1 ; i <= vv ;i++){
        if(dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    return 0;
}