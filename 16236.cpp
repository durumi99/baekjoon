#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct fish
{
    int dist;
    int y;
    int x;
};

struct compare
{
    bool operator()(fish a, fish b)
    {
        if (a.dist == b.dist)
        {
            if (a.y == b.y)
            {
                return a.x > b.x;
            }
            return a.y > b.y;
        }
        return a.dist > b.dist;
    }
};
int n;
int map[21][21];
bool visit[21][21];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
queue<fish> q;

void bfs(){
	int sharkSize = 2;
	int eatenFish = 0;
	int time = 0;
	
	while(true){
		priority_queue<fish, vector<fish>,compare> pq;
		
		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			for(int i = 0 ; i < 4 ; i++){
				int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] > sharkSize || visit[ny][nx] )
                    continue;
                q.push({cur.dist+1,ny,nx});
            	visit[ny][nx] = true;
                if (map[ny][nx] < sharkSize && map[ny][nx] != 0)
                    pq.push({cur.dist + 1, ny, nx});
			}
		}
		memset(visit, false, sizeof(visit));
		if (!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            map[cur.y][cur.x] = 0;
            eatenFish++;
            time = cur.dist; 
            q.push({cur.dist, cur.y, cur.x}); 
            visit[cur.y][cur.x] = true;
        }
        else{
            cout << time << '\n';
            break;
        }
        if (eatenFish == sharkSize){
            sharkSize++;
            eatenFish = 0;
        }
	}
}
int main() {
	cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                q.push({0, i, j});
                map[i][j] = 0;
                visit[i][j] = true;
            }
        }
    }
    bfs();
	return 0;
}