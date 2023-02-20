#include <bits/stdc++.h>

#define MAX 10001

using namespace std;

int N;
int p[MAX];
int dp[MAX];

void makeDp() {
	for(int i = 1 ; i <= N ; i++) {
		dp[i] = p[i];
		for(int j = 1 ; j <= i ; j++) {
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
	}
    makeDp();
    cout << dp[N];
    return 0;
}