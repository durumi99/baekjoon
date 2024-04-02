#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int N, M;
int answer;
char campus[606][606];
int visited[606][606];

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for (int i = 0 ; i < 4 ; i++) {
        int nY = y + dy[i];
        int nX = x + dx[i];
        
        if (nY <= 0 || nX <= 0 || nY > N || nX > M) {
            continue;
        }
        if (visited[nY][nX]) {
            continue;
        }
        if (campus[nY][nX] == 'X') {
            continue;
        }
        if (campus[nY][nX] == 'P') {
            answer++;
        }
        dfs(nY, nX);
    }
}
int main() {
    cin >> N >> M;
    int sY, sX;
    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= M ; j++) {
            cin >> campus[i][j];
            if (campus[i][j] == 'I') {
                sY = i;
                sX = j;
            }
        }
    }
    dfs(sY, sX);
    
    if (answer == 0) {
        cout << "TT";
    } else {
        cout << answer;
    }
    return 0;
}