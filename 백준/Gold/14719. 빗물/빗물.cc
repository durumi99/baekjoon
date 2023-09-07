#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int h, w;
int blocks[501][501];
int visited[501][501];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

bool canPooled(int y, int x) {
    if(y < 0 || x < 0 || y >= h || x >= w)
        return false;
    if(blocks[y][x] == 1)
        return false;
    if(visited[y][x])
        return false;
    return true;
}


int dfs(int y, int x) {
    visited[y][x] = 1;
    int cnt = 1;
    for(int i = 0 ; i < 4 ; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];
        if(canPooled(newY, newX)) {
            cnt += dfs(newY, newX);
        }
    }
    return cnt;
}
int main() {
    int ans = 0;
    cin >> h >> w;
    for(int i = 0 ; i < w ; i++) {
        int tmp; cin >> tmp;
        for(int j = 0 ; j < tmp ; j++) {
            blocks[h - j - 1][i] = 1;
        }
    }
    
    
    for(int i = 0 ; i < h ; i++) {
        if(blocks[i][0] == 0) {
            int tmp = 0;
            while(tmp < w && blocks[i][tmp] == 0) {
                visited[i][tmp] = 1;
                tmp++;
            }
        }
        if(blocks[i][w - 1] == 0) {
            int tmp = w - 1;
            while(tmp >= 0 && blocks[i][tmp] == 0) {
                visited[i][tmp] = 1;
                tmp--;
            }
        }
        for(int j = 0 ; j < w ; j++) {
            if(canPooled(i, j)) {
                ans += dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}