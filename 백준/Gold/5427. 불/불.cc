#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char maze[1001][1001];
bool visited[1001][1001];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int r, c;
queue <pair<int, int>> J, F;

int main() {
    int TC; cin >> TC;
    
    while(TC--) {
        memset(visited, false, sizeof(visited));
        while(!J.empty())
            J.pop();
        while(!F.empty())
            F.pop();
            
        cin >> c >> r;
        
        for(int i = 0 ; i < r ; i++) {
            for(int j = 0 ; j < c ; j++) {
                cin >> maze[i][j];
                if(maze[i][j] == '@'){
                    J.push({i, j});
                    visited[i][j] = true;
                } else if(maze[i][j] == '*') {
                    F.push({i, j});
                }
            }
        }
        int cnt = 0;
        
        while(true) {
            int fSize = F.size();
            bool check = false;
            
            for(int i = 0 ; i < fSize ; i++) {
                int y = F.front().first;
                int x = F.front().second;
                F.pop();
                
                for(int k = 0 ; k < 4 ; k++) {
                    int nY = y + dy[k];
                    int nX = x + dx[k];
                    
                    if(nY < 0 || nX < 0 || nY >= r || nX >= c)
                        continue;
                        
                    if(maze[nY][nX] != 'F' && maze[nY][nX] != '#') {
                        maze[nY][nX] = 'F';
                        F.push({nY, nX});
                    }
                }
            }
            
            int jSize = J.size();
            for(int i = 0 ; i < jSize ; i++) {
                int y = J.front().first;
                int x = J.front().second;
                J.pop();
                for(int k = 0 ; k < 4 ; k++) {
                    int nY = y + dy[k];
                    int nX = x + dx[k];
                    
                    if(nY < 0 || nX < 0 || nY >= r || nX >= c) {
                        check = true;
                        break;
                    }
                    if(maze[nY][nX] == '.' && !visited[nY][nX]) {
                        visited[nY][nX] = true;
                        J.push({nY, nX});
                    }
                }
                if(check)
                	break;
            }
            if(check) {
            	cout << cnt + 1 << '\n';
            	break;
            }
            if(J.empty()) {
                cout << "IMPOSSIBLE\n";
                break;
            } 
            cnt++;
        }
    }
    return 0;
}