#include <iostream>
#define MAX 1000001

using namespace std;
int n,m;
int parent[MAX];

int find(int u){
    if(u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void unite(int u,int v){
    u = find(u);
    v = find(v);
    
    if(u != v){
        if(u < v)
            parent[v] = u;
        else
            parent[u] = v;
    }
}
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i <= n ; i++)
        parent[i] = i;
    int op,a,b;
    for(int i = 0 ; i < m ; i++){
        cin >> op >> a >> b;
        if(a == b){
            if(op == 1)
                cout << "YES" << '\n';
            continue;
        }
        
        a = find(a);
        b = find(b);
        if(op == 1){
            if(a == b)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
            if(a != b)
                unite(a,b);
    }
    return;
}
int main() {
    solve();
    // for(int i = 1 ; i <= n ; i++)
    //     cout << parent[i] << ' ';
    return 0;
}