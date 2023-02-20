#include <bits/stdc++.h>

#define MAX 111
using namespace std;

int N;
int arr[MAX][MAX];
int visited[MAX][MAX];
int ans = 1;
int maxH = -1;
int height;
int cnt = 0;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(int y, int x) {
	queue < pair<int, int> > q;
	q.push({y, x});
	
	while(!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++) {
			int nY = curY + dy[i];
			int nX = curX + dx[i];
			
			if(nY < 0 || nY >= N || nX < 0 || nX >= N)
				continue;
			if(visited[nY][nX])
				continue;
			if(arr[nY][nX] <= height)
				continue;
				
			visited[nY][nX] = 1;
			// cout << nY << ' ' << nX << ' ';
			q.push({nY, nX});
		}
	}
	// cout << '\n';
}
void solve() {
	int cnt = 0;
	for(int i = 0 ; i < N ; i++) 
    	for(int j = 0 ; j < N ; j++) 
    		visited[i][j] = 0;
	
	for(int i = 0 ; i < N ; i++) {
    	for(int j = 0 ; j < N ; j++) {
    		if(arr[i][j] > height && !visited[i][j]) {
    			visited[i][j] = 1;
    			cnt++;
    			bfs(i, j);
    			// cout << '\n';
    		}
    	}
    }
	// for(int i = 0 ; i < N ; i++) { 
 //   	for(int j = 0 ; j < N ; j++) { 
 //   		cout << visited[i][j] << ' ';
 //   	}
 //   	cout << '\n';
	// }
	// cout << cnt << '\n';
	
    ans = max(ans, cnt);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0 ; i < N ; i++) {
    	for(int j = 0 ; j < N ; j++) {
    		cin >> arr[i][j];
    		maxH = max(arr[i][j], maxH);
    	}
    }
    
    for(int i = 0 ; i <= maxH ; i++) {
    	height = i;
    	solve();
    }
    
    cout << ans ;
    return 0;
}