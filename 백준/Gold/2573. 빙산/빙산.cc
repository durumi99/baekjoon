#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int ocean[301][301];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int check() {
    int cnt = 0;
    int visited[301][301] = {0, };
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(ocean[i][j] != 0 && !visited[i][j]) {
                cnt++;
                if(cnt >= 2) {
                    return cnt;
                }
                queue < pair<int, int> > q;
                
                q.push({i, j});
                visited[i][j] = 1;
                
                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    
                    for(int k = 0 ; k < 4 ; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        
                        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
                            continue;
                        if(ocean[ny][nx] == 0)
                            continue;
                        if(visited[ny][nx])
                            continue;
                        q.push({ny, nx});
                        visited[ny][nx] = 1;
                    }
                }
            }
        }
    }
    return cnt;
}
void print() {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cout <<  ocean[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> ocean[i][j];
        }
    }
    
    int year = 0;
    int tmp[301][301];
    // memcpy(&tmp, &ocean, sizeof(ocean));
    
    while(true) {
        int cnt = check();
        if(cnt == 0) {
            year = 0;
            break;
        } else if(cnt >= 2) {
            break;
        }
        
	    memset(tmp, 0, sizeof(tmp));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(ocean[i][j] > 0) {
                    int waterCnt = 0;
                    for(int k = 0 ; k < 4 ; k++) {
                        int y = i + dy[k];
                        int x = j + dx[k];
                        
                        if(y < 0 || x < 0 || y >= n || x >= m)
                            continue;
                        if(ocean[y][x] != 0)
                            continue;
                        
                        // tmp[i][j]--;
                        // if(tmp[i][j] == 0)
                        //     break;
                        waterCnt++;
                    }
                    int val = ocean[i][j] - waterCnt;
                    if(val > 0)
                        tmp[i][j] = val;
                }
            }
        }
        // print();
        memcpy(&ocean, &tmp, sizeof(tmp));
        year++;
    }
    
    cout << year;
    return 0;
}