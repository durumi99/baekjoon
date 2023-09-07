#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
long long dp[1000001];

int main() {
    cin >> n;
    queue <long long > q;
    
    for(int i = 1 ; i <= 9 ; i++) {
        q.push(i);
        dp[i] = i;
    }
    if(0 <= n && n <= 10) {
        cout << n;
        return 0;
    }
    int idx = 10;
    
    while(idx <= n && !q.empty()) {
        long long curNum = q.front();
        q.pop();
        
        int lastNum = curNum % 10;
        
        for(int i = 0 ; i < lastNum ; i++) {
            q.push(curNum * 10 + i);
            dp[idx++] = curNum * 10 + i;
        }
    }
    
    if(idx >= n && dp[n]) {
        cout << dp[n];
    } else {
        cout << -1;
    }
    return 0;
}