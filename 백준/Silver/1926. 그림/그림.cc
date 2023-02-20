#include <bits/stdc++.h>

#define MAX 555
using namespace std;

int N, M;
int arr[MAX][MAX];
int visited[MAX][MAX];
vector <int> v;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

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
			if(nY < 0 || nY >= N || nX <0 || nX >= M)
				continue;
			if(visited[nY][nX])
				continue;
			if(!arr[nY][nX])
				continue;
			
			visited[nY][nX] = 1;
			q.push({nY, nX});
		}
	}
	v.push_back(cnt);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >>  N >> M ;
    for(int i = 0 ; i < N ; i++) {
    	for(int j = 0 ; j < M ; j++) {
    		cin >> arr[i][j];
    	}	
    }
    for(int i = 0 ; i < N ; i++) {
    	for(int j = 0 ; j < M ; j++) {
	    	if(arr[i][j] == 1 && !visited[i][j]) {
	    		bfs(i, j);
	    	}
    	}	
    }
    sort(v.begin(), v.end(), greater<> ());
    cout << v.size() << '\n';
    if(v.empty())
    	cout << 0;
    else
	    cout << v[0];
    return 0;
}