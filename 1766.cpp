#include <iostream>
#include <vector>
#include <queue>

#define MAX 33333
using namespace std;
int n,m;
vector < vector<int> >g(MAX);
int degree[MAX];
void solve(){
    priority_queue <int,vector<int>, greater<int> > pq;
    
    for(int i = 1 ; i <= n ; i++){
        if(!degree[i])
            pq.push(i);
    }
    
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        
        for(int i = 0 ; i < g[cur].size();i++){
            degree[g[cur][i]]--;
            if(!degree[g[cur][i]])
                pq.push(g[cur][i]);
        }
    }
}
void input(){
    cin >> n >> m;
    int a,b;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        g[a].push_back(b);
        degree[b]++;
    }
}
int main() {
    input();
    solve();
    return 0;
}