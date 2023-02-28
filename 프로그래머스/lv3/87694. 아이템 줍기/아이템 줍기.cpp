#include <bits/stdc++.h>

#define MAX 101
using namespace std;
int visited[MAX][MAX];
int arr[MAX][MAX];

int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int by[4] = {-1, -1, 1, 1};
int bx[4] = {-1, 1, -1, 1};

bool checkBorder(int y, int x) {
    for(int i = 0 ; i < 8 ; i++) {
        int nY = y + dy[i];
        int nX = x + dx[i];
        if(nY < 0 || nY >= MAX || nX < 0 || nX >= MAX)
            return false;
        if(arr[nY][nX] == 0)
            return false;
    }
    return true;
}
int bfs(int characterX, int characterY, int itemX, int itemY) {
    visited[characterY][characterX] = 1;
    queue < pair< pair<int, int>, int> > q;
    q.push({{characterY, characterX}, 0});
    int answer = -1;
    
    while(!q.empty()) {
        int curMove = q.front().second;
        int y = q.front().first.first;
        int x = q.front().first.second;
        q.pop();
        
        // cout << curMove << ' ' << y << ' ' << x << '\n';
        if(y == itemY && x == itemX) {
            answer = curMove;
            break;
        }
        for(int i = 0 ; i < 4 ; i++) {
            int nY = y + dy[i];
            int nX = x + dx[i];
            if(nY < 0 || nY >= MAX || nX < 0 || nX >= MAX)
                continue;
            if(arr[nY][nX] == 0)
                continue;
            if(visited[nY][nX])
                continue;
            if(checkBorder(nY, nX))
                continue;
            
            visited[nY][nX] = 1;
            q.push({{nY, nX}, curMove+1});
        }
    }
    return answer / 2;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(auto it : rectangle) {
        for(int i = it[1]*2 ; i <= it[3]*2 ; i++)
            for(int j = it[0]*2 ; j <= it[2]*2 ; j++)
                arr[i][j] = 1;     
    }
    // for(int i = 19 ; i >= 0 ; i--) {
    //     for(int j = 0 ; j < 20 ; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    answer = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    return answer;
}