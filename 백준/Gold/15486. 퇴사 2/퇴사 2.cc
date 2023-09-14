#include <iostream>
#include <bits/stdc++.h>
#define MAX 1500001
using namespace std;
int t[MAX];
int p[MAX];
int dp[MAX];
int main() {
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> t[i] >> p[i];
    }
    for(int i = 0 ; i < n ; i++) {
        if(t[i] + i <= n) {
            dp[t[i] + i] = max(dp[t[i] + i], dp[i] + p[i]);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    
    cout << dp[n];
    return 0;
}