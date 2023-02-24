#include <bits/stdc++.h>

#define INF 987654321
#define MAX 101
using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int bfs(vector<vector<int> > maps) {
    int res = -1;
    int n = maps.size();
    int m = maps[0].size();
    int visited[n][m];
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            visited[i][j] = 0;
    
    queue < pair <pair <int, int>, int> > q;
    q.push({{0, 0}, 1});
    visited[0][0] = 1;
    
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int step = q.front().second;
        q.pop();
        
        if(y == n-1 && x == m-1) {
            res = step;
            break;
        }
        
        for(int i = 0 ; i < 4 ; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            
            if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                continue;
            if(visited[nextY][nextX])
                continue;
            if(maps[nextY][nextX] == 0)
                continue;
            
            visited[nextY][nextX] = 1;
            q.push({{nextY, nextX}, step+1});
        }
    }
    
    return res;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = bfs(maps);
    
    return answer;
}