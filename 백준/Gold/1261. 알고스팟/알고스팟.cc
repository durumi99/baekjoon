#include <iostream>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;
int miro[101][101];
int visited[101][101];
int wall[101][101];

int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};
int ans = 10001;

int main() {
	int N, M; cin >> M >> N;
	for(int i = 1 ; i <= N ; i++) {
		string s; cin >> s;
		for(int j = 1 ; j <= M ; j++) {
			miro[i][j] = s[j-1] - '0';
		}
	}

	queue < pair <pair<int, int>, int> > q;
	q.push({{1, 1}, 0});
	visited[1][1] = 1;
	
	while(!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int wallCnt = q.front().second;
		q.pop();
		if(wallCnt > ans) {
			continue;
		}
		// cout << y << ' ' << x << ' ' << wallCnt << '\n';
		if(y == N && x == M) {
			ans = min(ans, wallCnt);
			visited[N][M] = ans;
			continue;
		}
		
		for(int i = 0 ; i < 4 ; i++) {
			int newY = y + dy[i];
			int newX = x + dx[i];
			if(newY < 1 || newY > N || newX < 1 || newX > M) {
				continue;
			}
			if(miro[newY][newX] == 0 && (!visited[newY][newX] || wall[newY][newX] > wallCnt)) {
				visited[newY][newX] = 1;
				wall[newY][newX] = wallCnt;
				q.push({{newY, newX}, wallCnt});	
			}
			if(miro[newY][newX] == 1 && (!visited[newY][newX] || wall[newY][newX] > wallCnt + 1)) {
				visited[newY][newX] = 1;
				wall[newY][newX] = wallCnt + 1;
				q.push({{newY, newX}, wallCnt + 1});
			}
		}
	}
	
	cout << ans;
	return 0;
}