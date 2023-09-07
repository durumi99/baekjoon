#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m; 
bool visited[2001];
vector <int> v[2001];

bool dfs(int cur, int cnt) {
    if(cnt == 5)
        return true;
    
    for(int i = 0 ; i < v[cur].size() ; i++) {
        if(!visited[v[cur][i]]) {
            visited[v[cur][i]] = true;
            if(dfs(v[cur][i], cnt + 1)) {
                return true;
            }
            visited[v[cur][i]] = false;
        }
    }
    
    return false;
}
int main() {
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int result = 0;
    for(int i = 0 ; i < m ; i++) {
        visited[i] = true;
        if(dfs(i, 1)) {
            result = 1;
            break;
            // memset(visited, false, sizeof(visited));
        }
        visited[i] = false;
    }
    cout << result;
    return 0;
}