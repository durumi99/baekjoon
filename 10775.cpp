#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;
int g,p;
int gate[MAX] = {0,};
int parent[MAX];

int find(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void unite(int u , int v){
    u = find(u);
    v = find(v);
    
    if(u != v)
        parent[u] = v;
}
void input(){}
void solve(){
    int ans = 0;
    int plane;
    cin >> g >> p;
    for(int i = 0 ; i <= g ;i++)
        parent[i] = i;
    for(int i = 0 ; i < p ; i++){
        cin >> plane;
        if(find(plane) == 0)
            break;
        else{
            ans++;
            unite(find(plane),find(plane)-1);
        }
    }
    cout << ans;
}
int main() {
    solve();
    return 0;
}