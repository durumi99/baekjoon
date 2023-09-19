#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char field[12][6];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

bool isPuyo(int y, int x) {
    int visited[12][6] = {0, };
    queue < pair<int, int> > q, qq;
    char color = field[y][x];
    q.push({y, x});
    qq.push({y, x});
    visited[y][x] = 1;
    
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++) {
            int nY = curY + dy[i];
            int nX = curX + dx[i];
            
            if(nY < 0 || nX < 0 || nY >= 12 || nX >= 6)
                continue;
            if(field[nY][nX] != color)
                continue;
            if(visited[nY][nX])
                continue;
            visited[nY][nX] = 1;
            q.push({nY, nX});
            qq.push({nY, nX});
        }
    }
    if(qq.size() >= 4) {
        while(!qq.empty()) {
            int curY = qq.front().first;
            int curX = qq.front().second;
            qq.pop();
            
            field[curY][curX] = '.';
        }
        return true;
    }
    return false;
}
int main() {
    for(int i = 0 ; i < 12  ; i++) {
        for(int j = 0 ; j < 6 ; j++) {
            cin >> field[i][j];  
        }
    }
    int cnt = 0;
    
    while(true) {
        bool check = false;
        for(int i = 0 ; i < 12  ; i++) {
            for(int j = 0 ; j < 6 ; j++) {
                if(field[i][j] != '.') {
                    if(isPuyo(i, j)) {
                        check = true;
                    }
                }
            }
        }
        if(!check)
            break;
        cnt++;
        
        
        for(int j = 0 ; j < 6 ; j++) {
            for(int i = 11 ; i >= 0 ; i--) {
                while(field[i][j] == '.') {
                    bool check = true;
                    for(int k = 0 ; k <= i ; k++) {
                        if(field[k][j] != '.') {
                            check = false;
                            break;
                        }
                    }
                    if(check)
                        break;
                    for(int k = i ; k >= 0 ; k--) {
                        if(k == 0) {
                            field[k][j] = '.';
                        } else {
                            field[k][j] = field[k-1][j];
                        }
                    }
                }
            }
        }
        
    }
    cout << cnt;
    return 0;
}