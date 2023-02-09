#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

#define MAX 10
using namespace std;
int N, M;
int map[MAX][MAX];
int bsCnt = MAX * MAX;
int rot_type[6] = {-1, 4, 2, 4, 4, 1};

vector <int> cam;
vector < pair<int, int> > v;
void update(int dir, int y, int x) {
    dir %= 4;
    // cout << dir << '\n';
    if(dir == 0) { // 동
        for(int i = x + 1 ; i < M ; i++) {
            if(map[y][i] == 6)
                break;
            map[y][i] = -1;
        }
    } else if(dir == 1) { // 북
        for(int i = y-1 ; i >= 0 ; i--) {
            if(map[i][x] == 6)
                break;
            map[i][x] = -1;
        }
    } else if(dir == 2) { // 서서
        for(int i = x - 1 ; i >= 0 ; i--) {
            if(map[y][i] == 6)
                break;
            map[y][i] = -1;
        }
    } else {
        for(int i = y + 1 ; i < N ; i++) {
            if(map[i][x] == 6)
                break;
            map[i][x] = -1;
        }
    }
}
void calbsCnt() {
    int tmp = 0;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            // cout << map[i][j] << ' ';
            if(map[i][j] == 0)
                tmp++;
        }
        // cout << '\n';
    }
    // cout << '\n';
    bsCnt = min(bsCnt, tmp);
}

void copy(int copied[MAX][MAX], int origin[MAX][MAX]) {
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            copied[i][j] = origin[i][j];
        }
    }
}
void dfs(int idx) {
    if(idx == v.size()) {
        calbsCnt();
        return;
    }
    int y = v[idx].first;
    int x = v[idx].second;
    int CCTV = cam[idx];
    
    int backup[MAX][MAX];
    // cout << CCTV << '\n';
    for(int dir = 0 ; dir < rot_type[CCTV] ; dir++) {
        copy(backup, map);
        if(CCTV == 1) {
            update(dir, y, x);
        } else if(CCTV == 2) {
             update(dir, y, x);
             update(dir+2, y, x);
        } else if(CCTV == 3) {
           update(dir, y, x);
           update(dir+1, y, x);
        } else if(CCTV == 4) {
            update(dir, y, x);
            update(dir+1, y, x);
            update(dir+2, y, x);
        } else if(CCTV == 5) {
            update(dir, y, x);
            update(dir+1, y, x);
            update(dir+2, y, x);
            update(dir+3, y, x);
        }
        dfs(idx+1);
        copy(map, backup);
    }
} 
int main() {
    cin >> N >> M ;
    
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <= 5) {
                v.push_back({i, j});
                cam.push_back(map[i][j]);
            } 
        }
    }
    // cout << v.size() << '\n';
    dfs(0);
    
    cout << bsCnt;
    return 0;
}