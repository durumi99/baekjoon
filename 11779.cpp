#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 1001
#define INF 2147000000
 
using namespace std;
 
vector<pair<int,int>> g[MAX]; // next,cost
priority_queue<pair<int,int>> pq; //cost,next
vector<int> dist(MAX,INF);
vector<int> ans;
int cityOrder[MAX];
int src,dst;
 
void dijkstra(){
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        int cur=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
 
        if(dist[cur]<cost)continue;
        for(int i=0;i<g[cur].size();i++){
            int next=g[cur][i].first;
            int nCost=g[cur][i].second+cost;
            if(dist[next]>nCost){
                dist[next]=nCost;
                cityOrder[next] = cur;
                //cityOrder[next] = cityOrder[cur]  + to_string(next);
                pq.push({-nCost,next});
            }
        }
    }
    int t = dst;
    while(t){
        ans.push_back(t);
        t = cityOrder[t];
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int N,M,a,b,c;
    cin>>N>>M;
    while(M--){
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    cin>>src>>dst;
    dijkstra();
    cout << dist[dst] << '\n';
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) 
        cout << ans[i] << " ";
}