#include <iostream>
#include <queue>
#include <vector>

#define MAX 51
using namespace std;

int r,c;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char map[MAX][MAX];
bool visit[MAX][MAX];
int startX,startY;
int endX,endY;
int waterS;
queue < pair<int,int> > water;
void input(){
    cin >> r >> c;
    for(int i = 1 ; i <= r ; i++)
        for(int j = 1 ; j <= c ; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            else if(map[i][j] == 'D'){
                endX = i;
                endY = j;
            }
            else if(map[i][j] == '*'){
                water.push({i,j});
            }
        }
}
void solve(){
    queue < pair<int,int> > q;
    q.push({startX,startY});
    visit[startX][startY] = true;
    int cnt = 0;
    while(!q.empty()){
        cnt++;
        int water_size = water.size();
        while (water_size--) {
    		int x = water.front().first;
    		int y = water.front().second;
    		water.pop();
    
    		for (int i = 0; i < 4; i++) {
    			int nx = x + dx[i];
    			int ny = y + dy[i];
    
    			if (nx < 1 || nx > r || ny < 1 || ny > c) 
    			    continue;
    			if (map[nx][ny] == 'X' || map[nx][ny] == 'D' || map[nx][ny] == '*') 
    			    continue;
    			water.push({nx,ny});
    			map[nx][ny] = '*';
    		}
	    }
        
        int start_size = q.size();
        while(start_size--){
            int x = q.front().first;
			int y = q.front().second;
			q.pop();

			visit[x][y] = true;
			if (x == endX && y == endY) {
				cout << cnt - 1 << endl;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 1 || nx > r || ny < 1 || ny > c) 
				    continue;
				if (map[nx][ny] == 'X' || map[nx][ny] == '*' || visit[nx][ny]) 
				    continue;
				visit[nx][ny] = true;
				q.push({nx,ny});
			}
		}
    }
    cout << "KAKTUS";
    return;
}
int main() {
    input();
    solve();
    return 0;
}