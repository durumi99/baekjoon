#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n,ans = 0;
	int arr[500][500];
    int dp[500][500];
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j <= i ; j++)
			cin >> arr[i][j];
	dp[0][0] = arr[0][0];
	
	for(int i = 1 ; i < n ; i ++){
		dp[i][0] = dp[i-1][0] + arr[i][0];
		for(int j = 1 ; j < i ; j++)
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + arr[i][j];
		dp[i][i] = dp[i-1][i-1] + arr[i][i];
	}

	for(int i = 0 ; i < n ; i++)
		if(dp[n-1][i] > ans)
			ans = dp[n-1][i];
	
	cout << ans;
	return 0;
}