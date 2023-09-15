#include <iostream>
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int n, m;
int route[6001][3];
long long dis[501];

void bf() {
    dis[1] = 0;
    for(int i = 2 ; i <= n ; i++) {
        dis[i] = INF;
    }
    for(int i = 1 ; i <= n - 1 ; i++) {
        for(int j = 0 ; j < m ; j++) {
            int start = route[j][0];
            int dest = route[j][1];
            int cost = route[j][2];
            
            if(dis[start] == INF)
                continue;
            if(dis[dest] > dis[start] + cost) {
                dis[dest] = dis[start] + cost;
            }
        }
    }
    for(int i = 0 ; i < m ; i++) {
        int start = route[i][0];
        int dest = route[i][1];
        int cost = route[i][2];
        
        if(dis[start] == INF)
            continue;
        if(dis[dest] > dis[start] + cost) {
            cout << -1 << '\n';
            return;
        }
    }
    for(int i = 2 ; i <= n ; i++) {
        if(dis[i] == INF) {
            cout << -1 << '\n';
        } else {
            cout << dis[i] << '\n';
        }
        
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) {
        int a, b, c; cin >> a >> b >> c;
        route[i][0] = a;
        route[i][1] = b;
        route[i][2] = c;
    }
    
    bf();
    
    return 0;
}