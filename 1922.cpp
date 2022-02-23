#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
using namespace std;
int n,m;
vector < pair<int,int> > g[MAX];
bool visit[MAX];

void input(){
    cin >> n >> m;
    int a,b,c;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
}
void solve(){
    visit[1] = true;
    priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;
    
    for(int i = 0; i < g[1].size() ; i++){
        int next = g[1][i].first;
        int nCost = g[1][i].second;
        pq.push({nCost,next});
    }
    
    int ans = 0;
    
    while(!pq.empty()){
        int cCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visit[cur])
            continue;
        visit[cur] = true;
        ans += cCost;
        
        for(int i = 0 ; i < g[cur].size() ; i++){
            int next = g[cur][i].first;
            int nCost = g[cur][i].second;
            pq.push({nCost,next});
        }
    }
    cout << ans <<'\n';
}
int main() {
    input();
    solve();
    return 0;
}