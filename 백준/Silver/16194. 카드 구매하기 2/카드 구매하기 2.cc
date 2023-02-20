#include <bits/stdc++.h>

#define MAX 10001
#define INF 987654321

using namespace std;

int N;
int p[MAX];
int dp[MAX];

void makeDp() {
	dp[0] = 0;
	for(int i = 1 ; i <= N ; i++) {
		for(int j = 1 ; j <= N ; j++) {
			if(i - j >= 0)
				dp[i] = min(dp[i], dp[i-j] + p[j]);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >>  N ;
 
	for(int i = 1 ; i <= N ; i++) {
		cin >> p[i];
		dp[i] = INF;
	}
    makeDp();
    cout << dp[N];
    return 0;
}