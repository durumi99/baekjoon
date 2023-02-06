#include <iostream>
#include <cstring>

#define MAX 101
#define llu unsigned long long

using namespace std;
int N, M, K;
char map[MAX][MAX];
llu dp[MAX][MAX][80];
llu cnt = 0;
string word;


int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

llu dfs(int curY, int curX, int curL){
	if(dp[curY][curX][curL] != -1) {
		return dp[curY][curX][curL];
	}
	if(curL == word.length()-1) {
		// cnt++;
		// dp[curY][curX] += 1;
		return 1;
	}
	dp[curY][curX][curL] = 0;
	for(int i = 1 ; i <= K ; i++) {
		for(int j = 0 ; j < 4 ; j++) {
			int newY = curY + dy[j] * i;
			int newX = curX + dx[j] * i;
			if(newY < 0 || newY > N || newX < 0 || newX > M)
				continue;
			if(word[curL+1] != map[newY][newX])
				continue;

			dp[curY][curX][curL] += dfs(newY, newX, curL+1);
		
		}
	}
	return dp[curY][curX][curL];
}
int main() {
	cin >> N >> M >> K;
	for(int i = 0 ; i < N ; i++) {
		string s; cin >> s;
		for(int j = 0 ; j < M ; j++) {
			map[i][j] = s[j];
		}
	}
	cin >> word;
	memset(dp, -1, sizeof(dp));
	
	for(int i = 0 ; i < N ; i++) 
		for(int j = 0 ; j < M ; j++)
			if(map[i][j] == word[0]) 
				cnt += dfs(i, j, 0);
	
	// for(int i = 0 ; i < N ; i++) {
	// 	for(int j = 0 ; j < M ; j++){
	// 		cout << dp[i][j] << ' ';	
	// 	}
	// 	cout << '\n';
	// }
	cout << cnt;
	return 0;
}