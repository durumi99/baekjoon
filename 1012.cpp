#include <iostream>
#include <string.h>
using namespace std;

int arr[50][50] = {0};
int visited[50][50] = {0};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int m ,n, k;

void dfs(int y, int x){
	for(int i = 0 ; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
			
		if(arr[ny][nx] && !visited[ny][nx]){
			visited[ny][nx]++;
			dfs(ny,nx);
		}
	}
}
int main() {
	int tc,x,y;
	cin >> tc;
	for(int testcase = 0 ; testcase < tc ; testcase++){
		cin >> m >> n >> k;
		memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
		int ans = 0;
		
		for(int i = 0 ; i < k ; i++){
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < m ; j++)
				if(arr[i][j] && !visited[i][j]){
					ans++;
					visited[i][j]++;
					dfs(i,j);
				}
			
		cout << ans << '\n';	
	}
	return 0;
}