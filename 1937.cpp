#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 501;
int map[MAX][MAX];
int dp[MAX][MAX];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n,ans,tmp;
bool canMove;
void input(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
}
int dfs(int y , int x){
    if(dp[y][x] != -1)
        return dp[y][x];
    dp[y][x] = 1;
    for(int i = 0 ; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 1 || ny < 1 || nx > n || ny > n)
			continue;
			
		if(map[ny][nx] > map[y][x]){
	    	dp[y][x] = max(dfs(ny,nx) + 1 , dp[y][x]);
		}
	}
	return dp[y][x];
}
void solve(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            tmp = dfs(i,j);
            ans = ( tmp > ans ) ? tmp : ans ;
        }
    }
    cout << ans << '\n';
}
int main() {
    input();
    solve();
    return 0;
}