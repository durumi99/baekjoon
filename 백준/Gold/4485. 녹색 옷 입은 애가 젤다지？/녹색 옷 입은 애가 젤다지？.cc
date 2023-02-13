#include <bits/stdc++.h>

#define MAX 130
#define INF 987654321
using namespace std;

int N;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int cave[MAX][MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int tc = 1 ; ; tc++){
        cin >> N;
        if(N == 0)
            break;
        int visited[N][N];
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                cin >> cave[i][j];
                visited[i][j] = INF;
            }
        }
        queue < pair<int, int> > q;
        visited[0][0] = cave[0][0];
        q.push({0, 0});
        
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++) {
                int nY = y + dy[i];
                int nX = x + dx[i];
                
                if(nY < 0 || nY >= N || nX < 0 || nX >= N)
                    continue;
                if(visited[nY][nX] <= visited[y][x] + cave[nY][nX])
                    continue;
                visited[nY][nX] = visited[y][x] + cave[nY][nX];
                q.push({nY, nX});
            }
        
        }
        
        cout << "Problem " << tc << ": " <<visited[N-1][N-1] << '\n';
    }
    
    return 0;
}