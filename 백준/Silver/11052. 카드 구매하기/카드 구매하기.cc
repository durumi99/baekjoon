#include <iostream>
#include <cmath>
using namespace std;
long long dp[10001];
long long P[10001];

int N;
void makeDP(int N) {
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++) {
			if(i-j >= 0) {
				dp[i] = max(dp[i-j]+P[j], dp[i]);
			}
		}
	}
}
int main() {
	cin >> N;
	for(int i = 1 ; i <= N ; i++)
		cin >> P[i];
		
	makeDP(N);
	cout << dp[N];
	return 0;
}