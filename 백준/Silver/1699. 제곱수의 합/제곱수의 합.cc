#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int dp[100001];

int main() {
	// your code goes here
	cin >> N;
	for (int i = 1 ; i <= N ; i++) {
		int tmp = floor(sqrt(i)); 
		dp[i] = i;
		for(int j = tmp ; j >= 1 ; j--) {
			dp[i] = min(dp[i], dp[i-j*j] + 1);
		}
	}	
	
	cout << dp[N];
	return 0;
}