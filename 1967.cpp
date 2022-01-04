#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n,res = 0, endp = 0;
vector < pair<int,int> > tree[11111];
int visited[11111];
void dfs(int n, int w){
    if(visited[n])
        return;
    visited[n] = 1;
    if(res < w){
        res = w;
        endp = n;
    }
    for(int i = 0 ; i < tree[n].size() ; i++)
        dfs(tree[n][i].first, w + tree[n][i].second);
}
int main(){
    cin >> n;
    
    int parent,child,weight;
    for(int i = 1 ; i < n ; i ++){
        cin >> parent >> child >> weight;
        tree[parent].push_back({child,weight});
        tree[child].push_back({parent,weight});
    }
    dfs(1,0);
    res = 0;
    memset(visited, 0 , sizeof(visited));
    dfs(endp,0);
    
    cout << res;
    return 0;
}