#include <bits/stdc++.h>
#define INF 1e9
#define MAX 404
using namespace std;
int v, e;
int dist[MAX][MAX];

int main() {
    cin >> v >> e;
    for(int i = 1 ; i <= v ; i++) {
        for(int j = 1 ; j <= v ; j++) {
            dist[i][j] = INF;
        }
    }
    for(int i = 0 ; i < e ; i++) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = c;
    }
    
    for(int k = 1; k<= v; k++){
        for(int i = 1; i <= v; i++){
            for(int j = 1; j<= v; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int ans = INF;
    for(int i = 1 ; i < v ; i++) {
        ans = min(ans, dist[i][i]);
    }
    
    if(ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}