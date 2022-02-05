#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1111111
using namespace std;

typedef pair<int,int> p;
vector < pair<int,p> > v;
vector <int> vv;

int n,m,answer;
int parent[MAX];
void input(){
    int start,end,cost;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> start >> end >> cost;
        v.push_back({cost,{start,end}});
    }
    return;
}
int findParent(int u){
    if(u == parent[u])
        return u;
    else
        return parent[u] = findParent(parent[u]);
}

bool sameParent(int u,int v){
    u = findParent(u);
    v = findParent(v);
    if(u == v)
        return true;
    else
        return false;
}
void merge(int u,int v){
    u = findParent(u);
    v = findParent(v);
    if(u == v)
        return;
    parent[v] = u;    
}
void solve(){
    sort(v.begin(),v.end());
    for(int i = 1 ; i <= n ; i++)
        parent[i] = i;
    
    for(int i = 0 ; i < v.size() ; i++ ){
        int curCost = v[i].first;
        int curStart = v[i].second.first;
        int curEnd = v[i].second.second;
        if(sameParent(curStart,curEnd)) 
            continue;
        vv.push_back(curCost);
        merge(curStart,curEnd);
    }
    for(int i = 0 ; i < vv.size() -1 ; i++)
        answer += vv[i];
    
    cout << answer << '\n';
    return;
}
int main() {
    input();
    solve();
    
    return 0;
}