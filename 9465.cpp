#include <iostream>
#include <cmath>
using namespace std;
int n;
int arr[2][100000];
int dp[2][100000];
int main() {
	int tc;
	cin >> tc;
	for(int t = 0 ; t < tc ; t++){
		cin >> n;
		int tmp1=0,tmp2=0;
		for(int i = 0 ; i < 2 ; i++)
			for(int j = 0 ; j < n ; j++)
				cin >> arr[i][j];
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		for(int j = 1 ; j < n ; j++){
			dp[0][j] = max(dp[1][j-1],dp[1][j-2]) + arr[0][j];
			dp[1][j] = max(dp[0][j-1],dp[0][j-2]) + arr[1][j];
		}
		cout << max(dp[0][n-1],dp[1][n-1]) << '\n';
	}
	return 0;
}