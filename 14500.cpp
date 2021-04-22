#include <iostream>
using namespace std;
int n,m,Max = 0;
int arr[500][500];
int visited[500][500];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
void dfs(int x, int y,int cnt, int nMax){
	if(cnt == 4){
		Max = (nMax > Max) ? nMax : Max;
		return;
	}
	for(int i = 0 ; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if(!visited[nx][ny]){
			visited[nx][ny] = 1;
			dfs(nx,ny,cnt+1,nMax+arr[nx][ny]);
			visited[nx][ny] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> arr[i][j];
	for (int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			visited[i][j] = 1;
			dfs(i,j,1,arr[i][j]);
            visited[i][j] = 0;
            if(i < n - 1 && j < m- 2){
				Max = ( (arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2]) > Max) ? (arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2]) : Max ;
				Max = ( (arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1]) > Max) ? (arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1]) : Max ;
			}
			if( i < n -2 && j < m-1){
				Max = ( (arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1]) > Max) ? (arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1]) : Max ;
				Max = ( (arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1]) > Max) ? (arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1]) : Max ;
			}
		}
	cout << Max;			
	return 0;
}