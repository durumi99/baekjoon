#include <iostream>
using namespace std;
int n,m,num,x1,x2,y1,y2;
int dp[1050][1050];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++){
			cin >> num;
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num;
		}
	
	for(int i = 0 ; i < m ; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << '\n';
	}
	return 0;
}