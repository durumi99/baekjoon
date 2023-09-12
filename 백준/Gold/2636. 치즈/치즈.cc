#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int cheese[101][101];
int visited[101][101];

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

bool isAir(int y, int x) {
    visited[y][x] = 1;
    bool res = false;
    
    for(int i = 0 ; i < 4 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny <= 0 || nx <= 0 || ny >= n - 1 || nx >= m - 1) {
            return true;
        }
        if(cheese[ny][nx])
            continue;
        if(visited[ny][nx])
            continue;
        res |= isAir(ny, nx);
        
        if(res)
            return res;
    }
    
    return res;
}

int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> cheese[i][j];
        }
    }
    int meltTime = 0;
    int cnt = 0;
    int prevCnt;
    // setAir();
    
    while(true) {
        prevCnt = cnt;
        cnt = 0;
        bool check = true;
        int tmp[101][101] = {0, };
        
        for(int i = 1 ; i < n - 1 ; i++) {
            for(int j = 1 ; j < m - 1; j++) {
                tmp[i][j] = cheese[i][j];
                if(cheese[i][j] == 1) {
                    cnt++;
                    check = false; // 아직 다 안녹음
                    
                    for(int k = 0 ; k < 4 ; k++) {
                        int y = i + dy[k];
                        int x = j + dx[k];
                        
                        if(y <= 0 || x < 0 || y >= n || y >= m) {
                            tmp[i][j] = 0;
                            break;   
                        }
                        if(cheese[y][x])
                            continue;
                            
                        memset(visited, 0, sizeof(visited));
                        if(isAir(y, x)) {
                            tmp[i][j] = 0;
                            break;
                        }
                    }
                }
            }
        }
        if(check) {
            break;
        }
        meltTime++;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                cheese[i][j] = tmp[i][j];
            }
        }
    }
    
    cout << meltTime << '\n';
    cout << prevCnt << '\n';
    return 0;
}