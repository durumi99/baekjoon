#include <bits/stdc++.h>
#define INF 1e9

using namespace std;
int K, W, H;
int ans = INF;
int A[201][201];
pair<int, int> visited[201][201]; // {말로 이동 횟수, 총 이동 횟수}
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
int hy[] = {1, -1, 2, 2,  1, -1, -2, -2};
int hx[] = {2, 2, 1, -1, -2, -2, 1, -1};

struct Monkey {
    int y;
    int x;
    // int k;
};

int bfs() {
    int ans = -1;
    visited[0][0] = {0, 0};
    queue <Monkey> q;
    Monkey monkey = {0, 0};
    q.push(monkey);
    
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        // int k = q.front().k;
        int k = visited[y][x].first;
        int cnt = visited[y][x].second;
        q.pop();
        
        // cout << y << ' ' << x << ' ' << k << ' ' << cnt << '\n';
        
        if(y == H - 1 && x == W - 1) {
            ans = cnt;
            break;
        }
        
        if(k < K) { // 말 이동
            for(int i = 0 ; i < 8 ; i++) {
                int ny = y + hy[i];
                int nx = x + hx[i];
                if(ny < 0 || nx < 0 || ny >= H || nx >= W)
                    continue;
                if(A[ny][nx] == 1)
                    continue;
                if(visited[ny][nx].second <= cnt + 1 && visited[ny][nx].first <= k + 1)
                    continue;
                // if(visited[ny][nx].second == cnt + 1 && visited[ny][nx].first <= k + 1){
                //     // cout << "말 이동\n";
                //     // cout << ny << ' ' << nx << ' ' << k + 1 << ' ' << cnt + 1<< '\n';
                //     // cout << visited[ny][nx].first << ' ' << visited[ny][nx].second << '\n';
                //     continue;
                // } 
                
                visited[ny][nx] = {k + 1, cnt + 1};
                Monkey monkey = {ny, nx};
                q.push(monkey);
            }    
        }
        // 일반 이동
        for(int i = 0 ; i < 4 ; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= H || nx >= W)
                continue;
            if(A[ny][nx] == 1)
                continue;
            if(visited[ny][nx].second <= cnt + 1 && visited[ny][nx].first <= k)
                continue;
            // if(visited[ny][nx].second == cnt + 1 && visited[ny][nx].first <= k) {
            //     // cout << "일반 이동\n";
            //     // cout << ny << ' ' << nx << ' ' << k << ' ' << cnt + 1 << '\n';
            //     // cout << visited[ny][nx].first << ' ' << visited[ny][nx].second << '\n';
            //     continue;
            // }
            
            visited[ny][nx] = {k, cnt + 1};
            Monkey monkey = {ny, nx};
            q.push(monkey);
        }
    }
    
    return ans;
}
int main() {
    cin >> K >> W >> H;
    for(int i = 0 ; i < H ; i++) {
        for(int j = 0 ; j < W ; j++) {
            cin >> A[i][j];
            visited[i][j] = {INF, INF};
        }
    }
    
    cout << bfs() << '\n';
    
    // for(int i = 0 ; i < H ; i++) {
    //     for(int j = 0 ; j < W ; j++) {
    //         cout << visited[i][j].first << ',' << visited[i][j].second << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}