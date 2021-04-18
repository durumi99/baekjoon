#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int visited[100][100];
char RGB[100][100];


void dfs(int y, int x,char color){
	for(int i = 0 ; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
			
		if(RGB[ny][nx] == color && !visited[ny][nx]){
			visited[ny][nx]++;
			dfs(ny,nx,color);
		}
	}
}

int main() {
	int ans[2]={0};
	cin >> n;

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> RGB[i][j];
	
	//정상인
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(!visited[i][j]){
				ans[0]++;
				visited[i][j]++;
				dfs(i,j,RGB[i][j]);
			}
	

	memset(visited,0,sizeof(visited));
	
	//색맹
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(RGB[i][j] == 'G')
				RGB[i][j] = 'R';
	
	
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(!visited[i][j]){
				ans[1]++;
				visited[i][j]++;
				dfs(i,j,RGB[i][j]);
			}
	
	cout << ans[0] << ' ' << ans[1];
	return 0;
}