#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 1010
using namespace std;

int n,k,w;
long long delay[MAX];
int degree[MAX];
long long dp[MAX];
vector < vector <int> > g(MAX);

void solve(int w){
    queue <int> q;
    for(int i = 1 ; i <= n ; i++){
        if(i == w)
            continue;
        if(!degree[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        if(cur == w)
            break;
        q.pop();
        for(int i = 0 ; i < g[cur].size() ; i++){
            degree[g[cur][i]]--;
            dp[g[cur][i]] = max(dp[g[cur][i]], dp[cur] + delay[g[cur][i]]);
            if(!degree[g[cur][i]]){
                q.push(g[cur][i]);
            }
        }
    }
    cout << dp[w] << '\n';
}
int main() {
    int TC; cin >> TC;
    while(TC--){
        int a,b;
        cin >> n >> k;
        for(int i = 1 ; i <= n ; i++){
            cin >> delay[i];
            dp[i] = delay[i];
        }
        for(int j = 0 ; j < k ; j++){
            cin >> a >> b;
            g[a].push_back(b);
            degree[b]++;
        }
        cin >> w;
        solve(w);
        for(int i = 1 ; i <= n ; i++){
            dp[i] = 0;
            degree[i] = 0;
            delay[i] = 0;
            g[i].clear();
        }
    }
    return 0;
}