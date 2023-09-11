#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, l, r;
int popularity[51][51];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
int visited[51][51];
bool check;

int main() {
    cin >> n >> l >> r;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> popularity[i][j];
        }
    }
    int day = 0;
    while(true) {
        check = true;
        memset(visited, 0, sizeof(visited));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(!visited[i][j]) {
                    queue < pair<int, int> > q;
                    queue < pair<int, int> > qq;
                    q.push({i, j});
                    qq.push({i, j});
                    visited[i][j] = 1;
                    int qSum = 0;
                    
                    while(!q.empty()) {
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();
                        qSum += popularity[y][x];
                        
                        for(int i = 0 ; i < 4 ; i++) {
                            int ny = y + dy[i];
                            int nx = x + dx[i];
                            
                            if(ny < 0 || nx < 0 || ny >= n || nx >= n)
                                continue;
                            if(visited[ny][nx])
                                continue;
                            int pDif = abs(popularity[ny][nx] - popularity[y][x]);
                            if(pDif < l || pDif > r)
                                continue;
                            q.push({ny, nx});
                            qq.push({ny, nx});
                            visited[ny][nx] = 1;
                        }
                    }
                    int qSize = qq.size();
                    if(qSize > 1) {
                        check = false;
                        while(!qq.empty()) {
                            int y = qq.front().first;
                            int x = qq.front().second;
                            qq.pop();
                            
                            popularity[y][x] = qSum / qSize;
                        }
                    }
                }
            }
        }
        
        if(check)
            break;
        day++;
    }
    cout << day;
    return 0;
}