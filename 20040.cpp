#include <iostream>
#include <vector>

#define MAX 500005
using namespace std;
int n,m;
vector <int> parent(MAX);

int find(int u){
    if( u == parent[u])
        return u;
    return find(parent[u]);
}
void merge(int u , int v){
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    parent[v] = u;
}

int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        parent[i] = i;
    int u,v;
    for(int i = 1 ; i <= m ; i++){
        cin >> u >> v;
        u = find(u);
        v = find(v);
        if(u == v){
            cout << i << '\n';
            return 0;
        }
        merge(u,v);
    }
    cout << 0 << '\n';
    return 0;
}