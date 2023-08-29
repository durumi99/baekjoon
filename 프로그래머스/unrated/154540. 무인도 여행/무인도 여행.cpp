#include <string>
#include <vector>
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int _map[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
int n, m;

void getMap(vector<string> _maps){
    for(int i = 0 ; i <  _maps.size() ; i++) {
        for(int j = 0 ; j < _maps[i].size() ; j++) {
            if(_maps[i][j] == 'X') {
                _map[i][j] = 0;
            } else {
                _map[i][j] = _maps[i][j] - '0';
            }
            cout << _map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int dfs(int y, int x) {
    visited[y][x] = 1;
    int days = _map[y][x] ;
    for(int i = 0 ; i < 4 ; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];
        if(newY < 0 || newX < 0 || newY >= n || newX >= m)
            continue;
        if(visited[newY][newX] || _map[newY][newX] == 0)
            continue;
        days += dfs(newY, newX);
    }
    return days;
}
vector<int> solution(vector<string> _maps) {
    vector<int> answer;
    getMap(_maps);
    n = _maps.size();
    m = _maps[0].length();
    cout << n << ' ' << m << ' ';
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(!visited[i][j] && _map[i][j]) {
                int tmp = dfs(i, j);
                if(tmp)
                    answer.push_back(tmp);
            }
        }
    }
    if(answer.empty())
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}