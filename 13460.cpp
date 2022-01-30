#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
char map[11][11];
int holeX,holeY,redX,redY,blueX,blueY;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void f(){
    queue < pair< pair< pair<int,int> , pair<int,int> >, int> > q;
    q.push({{{redX,redY},{blueX,blueY}},0});
    
    while(!q.empty()){
        int curRedX = q.front().first.first.first;
        int curRedY = q.front().first.first.second;
        int curBlueX = q.front().first.second.first;
        int curBlueY = q.front().first.second.second;
        int curCnt = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            bool redArrivedHole = false;
            bool blueArrivedHole = false;
            int newRedX = curRedX;
            int newRedY = curRedY;
            int newBlueX = curBlueX;
            int newBlueY = curBlueY;
            while(true){
                bool redMoved = true;
                bool blueMoved = true;
                newRedX += dx[i];
                newRedY += dy[i];
                newBlueX += dx[i];
                newBlueY += dy[i];
                if(map[newRedX][newRedY] == 'O'){ // 빨간 구슬이 구멍 도착
                    redArrivedHole = true;
                }
                if(map[newBlueX][newBlueY] == 'O'){ // 파란 구슬이 구멍 도착
                    blueArrivedHole = true;
                }
                if(map[newRedX][newRedY] == '#' && map[newBlueX][newBlueY] == '#'){ // 두 구술이 벽에 부딪힘 
                    newRedX -= dx[i];
                    newRedY -= dy[i];
                    newBlueX -= dx[i];
                    newBlueY -= dy[i];
                    break;
                }
                if(map[newRedX][newRedY] == '#' && map[newBlueX][newBlueY] != '#'){ // 빨간 구슬만 벽에 부딪힘
                    redMoved = false;
                    newRedX -= dx[i];
                    newRedY -= dy[i];
                }
                if(map[newRedX][newRedY] != '#' && map[newBlueX][newBlueY] == '#'){ // 파란 구슬만 벽에 부딪힘
                    blueMoved = false;
                    newBlueX -= dx[i];
                    newBlueY -= dy[i];
                }
                if(newRedX == newBlueX && newRedY == newBlueY){ // 두 구슬의 위치가 겹침
                    if(redMoved){
                        newRedX -= dx[i];
                        newRedY -= dy[i];
                    }
                    else if(blueMoved){
                        newBlueX -= dx[i];
                        newBlueY -= dy[i];
                    }
                    break;
                }
            }
            if(blueArrivedHole)
                continue;
            else if(redArrivedHole){ 
                cout << curCnt+1 << '\n';
                return;
            }
            if(curCnt <= 8)
                q.push({{{newRedX,newRedY},{newBlueX,newBlueY}},curCnt+1});
        }
    }
    cout << -1 << '\n';
}
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++){
            cin >> map[i][j];
            if(map[i][j] == 'O'){
                holeX = i;
                holeY = j;
            }
            else if(map[i][j] == 'R'){
                redX = i;
                redY = j;
            }
            else if(map[i][j] == 'B'){
                blueX = i;
                blueY = j;
            }
        }
}
int main() {
    input();
    f();
    return 0;
}