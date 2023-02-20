#include <bits/stdc++.h>

#define MAX 111
using namespace std;

int M, N, K;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector <int> area;

void bfs(int y, int x) {
	int cnt = 0;
	visited[y][x] = 1;
	queue < pair<int, int> > q;
	q.push({y, x});
	
	while(!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		cnt++;
		
		for(int i = 0 ; i < 4 ; i++) {
			int nY = curY + dy[i];
			int nX = curX + dx[i];
			
			if(nY < 0 || nY >= M || nX < 0 || nX >= N) 
				continue;
			if(arr[nY][nX])
				continue;
			if(visited[nY][nX])
				continue;
				
			visited[nY][nX] = 1;
			q.push({nY, nX});
		}
	}
	
	area.push_back(cnt);
}
void f(int sY, int sX, int eY, int eX) {
	
	for(int i = sY ; i < eY ; i++) {
		for(int j = sX ; j < eX ; j++) {
			arr[i][j] = 1;
		}
 	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N >> K;
    for(int i = 0 ; i < K ; i++) {
    	int x[2], y[2];
    	cin >> x[0] >> y[0] >> x[1] >> y[1];
    	f(y[0], x[0], y[1], x[1]);
    }
    
    for(int i = 0 ; i < M ; i++) {
		for(int j = 0 ; j < N ; j++) {
			if(!visited[i][j] && !arr[i][j]) {
				bfs(i, j);
			}
		}
 	}
 	
 	sort(area.begin(), area.end());
 	cout << area.size() << '\n';
 	for(int i = 0 ; i < area.size(); i++)
 		cout << area[i] << ' ';
    return 0;
}