#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
int map[111][111];
int cnt = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool allMelt(){ // 모든 치즈가 녹았는지 확인
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(map[i][j])
                return false;
    return true;
}
bool isInside(int a,int b){ // 치즈 내부 공간 판별
    int visited[111][111] = {0,};
    queue <pair<int,int> > q;
    q.push({a,b});
    visited[a][b] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX > n || newY > n || newX < 1 || newY < 1)
                return false;
            if(map[newX][newY] == 0 && !visited[newX][newY]){
                visited[newX][newY] = 1;
                q.push({newX,newY});
            }
        }
    }
    return true;
}
bool isMelt(int x,int y){ // 녹을 치즈인지 확인
    vector < pair<int,int> > v;
    int meltCnt = 0;
    for(int i = 0 ; i < 4 ; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(map[newX][newY] == 0 && !isInside(newX,newY))
            meltCnt++;
    }
    if(meltCnt >= 2)
        return true;
    else
        return false;
}
void cheese(){
    int tmp[111][111] = {0,};
    while(!allMelt()){
        cnt++;
        
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++){
                if(map[i][j] == 1 && isMelt(i,j))
                    tmp[i][j] = -1;
        }
        
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++){
                if(tmp[i][j] == -1)
                    map[i][j] = 0;
        }
    }
    cout << cnt << '\n';
}
int main() {
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> map[i][j];
    cheese();
    return 0;
}