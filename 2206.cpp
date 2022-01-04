#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n,m;
int input[1111][1111];
int checked[1111][1111];
int result = 99999999;
int count;
int check = 0;
int visited[1111][1111][2];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int f(){
    visited[1][1][1] = 1;
    checked[1][1] = 1;
    queue<pair<pair<int, int>, int > > q; 
    q.push({ {1,1}, 1});
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        if(y == n && x == m){
            return visited[y][x][block];
        }
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newY = y + dy[i];
            int newX = x + dx[i];
            if(0 < newY && newY <= n && 0 < newX && newX <= m){
                if(input[newY][newX] == 1 && block){
                    visited[newY][newX][block-1] = visited[y][x][block] + 1;
                    q.push({{newY,newX},block - 1});
                }
                if(input[newY][newX] == 0 && !visited[newY][newX][block]){
                    visited[newY][newX][block] = visited[y][x][block] + 1;
                    q.push({{newY,newX},block});
                }
            }
        }
    }
    return -1;
}
int main() {
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            scanf("%1d", &input[i][j]);
            
    cout << f();
    return 0;
}