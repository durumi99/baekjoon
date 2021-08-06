#include <iostream>

using namespace std;
const int MAX = 501;
long long map[MAX][MAX];
long long dp[MAX][MAX];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n,m;
void input(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
}
int dfs(int y , int x){
    if(y == n && x == m)
        return 1;
    if(dp[y][x] != -1)
        return dp[y][x];
    dp[y][x] = 0;
    for(int i = 0 ; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 1 || ny < 1 || nx > m || ny > n)
			continue;
			
		if(map[ny][nx] < map[y][x]){
	    	dp[y][x] += dfs(ny,nx);
		}
	}
	
	return dp[y][x];
}
void solve(){
    cout << dfs(1,1) << '\n';
}
int main() {
    input();
    solve();
    return 0;
}