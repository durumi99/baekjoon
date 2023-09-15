#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int l, r, c;
char building[33][33][33];
int visited[33][33][33];
int dy[] = {0, 0, 0, 0, 1, -1};
int dx[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};
int startX, startY, startZ;
int endX, endY, endZ;

void bfs() {
    visited[startX][startY][startZ] = 1;
    queue < pair<tuple<int, int, int>, int> > q;
    q.push({{startX, startY, startZ}, 0});
    
    while(!q.empty()) {
        int x = get<0>(q.front().first);
        int y = get<1>(q.front().first);
        int z = get<2>(q.front().first);
        int cnt = q.front().second;
        q.pop();
        
        if(x == endX &&  y == endY && z == endZ) {
            cout << "Escaped in " << cnt << " minute(s).\n";
            return;
        }
        
        for(int i = 0 ; i < 6 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if(nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c)
                continue;
            if(building[nx][ny][nz] == '#')
                continue;
            if(visited[nx][ny][nz])
                continue;
            visited[nx][ny][nz] = 1;
            q.push({{nx, ny, nz}, cnt + 1});
        }
    }
    cout << "Trapped!\n";
}
int main() {
    while(true) {
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0)
            break;
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0 ; i < l ; i++) {
            for(int j = 0 ; j < r ; j++) {
                for(int k = 0 ; k < c ; k++) {
                    cin >> building[i][j][k];
                    if(building[i][j][k] == 'S') {
                        startX = i;
                        startY = j;
                        startZ = k;
                    } else if(building[i][j][k] == 'E') {
                        endX = i;
                        endY = j;
                        endZ = k;
                    }
                }
            }
        }
        bfs();
    }
    return 0;
}