#include <iostream>
#include <vector>
#include <queue>
//프림 알고리즘
#define MAX 11111
using namespace std;

bool visited[MAX];
vector < pair<int,int> > g[MAX];

void prim(int start){
    visited[start] = true;
    priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;
    
    for(int i = 0 ; i < g[start].size() ; i++){
        int next = g[start][i].first;
        int nCost = g[start][i].second;
        pq.push({nCost,next});
    }
    
    int ans = 0;
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int cCost = pq.top().first;
        pq.pop();
        if(visited[cur] == true)
            continue;
        visited[cur] = true;
        
        ans += cCost;
        
        for(int i = 0 ; i < g[cur].size() ; i++){
            int next = g[cur][i].first;
            int nCost = g[cur][i].second;
            pq.push({nCost,next});
        }
    }
    cout << ans << '\n';
}
void input(){
    int v,e,a,b,c;
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
}
int main() {
    input();
    prim(1);
    return 0;
}