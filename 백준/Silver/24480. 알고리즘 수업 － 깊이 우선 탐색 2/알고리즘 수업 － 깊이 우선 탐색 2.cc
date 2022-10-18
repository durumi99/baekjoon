#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int> > v(101010);
int visited[101010];
int cnt = 1;
void dfs(int cur){
    visited[cur] = cnt++;
    if(v[cur].size() == 0){
        return;
    }
    for(int i = 0 ; i < v[cur].size() ; i++){
        if(!visited[v[cur][i]]){
            dfs(v[cur][i]);
        }
    }
}
int main() {
    int n,m,r; cin >> n >> m >> r;
    for(int i = 0 ; i < m ; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++)
        sort(v[i].begin(),v[i].end(),greater<int>());
    dfs(r);
    for(int i = 1 ; i <= n ; i++)
        cout << visited[i] << '\n';
    return 0;
}