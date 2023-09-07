#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
char tMap[51][51];
int visited[51][51];
int ans;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

void print() {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << ans << '\n';
}
int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        string str; cin >> str;
        for(int j = 0 ; j < m ; j++) {
            tMap[i][j] = str[j];
        }
    }
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(tMap[i][j] == 'L') {
                queue < pair<pair<int, int>, int> > q;
                visited[i][j] = 1;
                q.push({{i, j}, 0});
                
                while(!q.empty()) {
                    int curY = q.front().first.first;
                    int curX = q.front().first.second;
                    int curD = q.front().second;
                    bool check = false;
                    q.pop();
                    
                    for(int i = 0 ; i < 4 ; i++) {
                        int newY = curY + dy[i];
                        int newX = curX + dx[i];
                        if(newY < 0 || newX < 0 || newY >= n || newX >= m)
                            continue;
                        if(visited[newY][newX])
                            continue;
                        if(tMap[newY][newX] == 'W')
                            continue;
                         check = true;
                         visited[newY][newX] = 1;
                         q.push({{newY, newX}, curD+1});
                    }
                    if(!check) {
                        ans = max(ans, curD);
                    }
                }
                
                for(int k = 0 ; k < n ; k++) {
                    memset(visited[k], 0 , sizeof(int) * m);
                }
                // print();
            }    
        }
    }
    
    cout << ans;
    return 0;
}