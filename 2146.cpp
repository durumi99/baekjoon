#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#define MAX 101
#define INF 1e9
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n;
int map[MAX][MAX];
int idx[MAX][MAX];
int idxN = 1;
int ans = INF;
bool visit[MAX][MAX];
void input(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> map[i][j];
}
void bfs(int i , int j){
    queue < pair <int,int> > q;
    q.push({i,j});
    visit[i][j] = true;
    idx[i][j] = idxN;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n ){
                if(map[nx][ny] == 1 && !visit[nx][ny]){
                    visit[nx][ny] = true;
                    idx[nx][ny] = idxN;
                    q.push({nx,ny});
                }
            }
        }
    }
}
void bfsBRG(int i , int j){
    queue < pair<pair <int,int>,int> > q;
    q.push({{i,j},0});
    memset(visit,false,sizeof(visit));
    visit[i][j] = true;
    int startIDX = idx[i][j];
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int len = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n ){
                if(idx[nx][ny] != 0 && idx[nx][ny] != startIDX){ // 다른 섬 도칙
                    ans = min(ans,len);
                    //cout << nx << ' ' << ny << ' ' << len << '\n';
                    return;
                }
                if(map[nx][ny] == 0 && !visit[nx][ny]){
                    visit[nx][ny] = true;
                    q.push({{nx,ny},len+1});
                }
            }
        }
    }
}
void makeIDX(){
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++){
            if( map[i][j] == 1 && !visit[i][j]){
                bfs(i,j);
                idxN++;
            }
        }
}
void makeBRG(){
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++){
            if(map[i][j] == 1){
                bfsBRG(i,j);
            }
        }
}
void solve(){
    makeIDX();
    makeBRG();
    cout << ans;
}
int main() {
    input();
    solve();
    return 0;
}