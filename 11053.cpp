#include <iostream>
using namespace std;

int main() {
	int n,ans = 1;
	int arr[1000];
	int dp[1000];
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
		dp[i] = 1;
	}
	for(int i = 1 ; i < n ; i++){
		int tmp = i-1;
		while(tmp >= 0){
			if(arr[i] > arr[tmp] && dp[tmp] >= dp[i])
				dp[i] = dp[tmp]+1;
			if(dp[i] > ans)
				break;
			tmp--;
		}
		if(dp[i] > ans)
			ans = dp[i];
	}
	
	cout << ans;
	return 0;
}