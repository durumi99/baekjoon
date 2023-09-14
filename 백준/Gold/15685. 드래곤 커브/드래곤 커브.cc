#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int board[222][222];

void drawCurve(int x, int y, int d, int g) {
    int endY = y;
    int endX = x;
    queue < pair<int, int>> q;
    q.push({y, x});
    
    board[y][x]++;
    
    board[y + dy[d]][x + dx[d]]++;
    q.push({y + dy[d], x + dx[d]});
    
    endY = y + dy[d];
    endX = x + dx[d];
    
    int nextEndY;
    int nextEndX;
    for(int i = 1 ; i <= g ; i++) {
        int qSize = q.size();
        
        for(int j = 0 ; j < qSize; j++) {
            int curY = q.front().first;
            int curX = q.front().second;
            q.push({curY, curX});
            q.pop();
            
            int yDif = endY - curY; // 1
            int xDif = endX - curX; // 0
            int newY = endY - xDif;
            int newX = endX + yDif;
            if(j == 0) {
                nextEndY = newY;
                nextEndX = newX;
            }
            if(newY < 0 || newX < 0)
            	continue;
            board[newY][newX]++;
            q.push({newY, newX});
        }
        endY = nextEndY;
        endX = nextEndX;
    }
}
bool check(int y, int x) {
    if(board[y][x+1] && board[y+1][x] && board[y][x] && board[y+1][x+1])
        return true;
    return false;
}
int main() {
    int n; cin >> n;
    
    for(int i = 0 ; i < n ; i++) {
        int x, y, d, g; cin >> x >> y >> d >> g;
        drawCurve(x, y , d, g);
    }
    
    int cnt = 0;
    for(int i = 0 ; i <= 100 ; i ++) {
        for(int j = 0 ; j <= 100 ; j ++) {
            if(check(i, j))
                cnt++;
        }
    }
    
    cout << cnt;
    return 0;
}