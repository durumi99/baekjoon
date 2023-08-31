#include <iostream>

using namespace std;
int dp[2501][2501];
string s;

void getP(int l, int r) {
    while(l >= 0 && r < s.length() && s[l] == s[r]) {
        // cout << l << ' ' << s[l] << ' ' << r << ' ' << s[r] << '\n'; 
        dp[l][r] = 1;
        l--;
        r++;
    }
}
int main() {
    cin >> s;
    for(int i = 0 ; i < s.length() - 1; i++) {
        getP(i, i);
        getP(i, i + 1);
    }
    getP(s.length() - 1, s.length() - 1);
    
    int ans[s.length()];
    for(int i = 0 ; i < s.length()  ; i++){
        ans[i] = 3000;
    }
    int idx = 0;
    
    ans[0] = 1;
    for(int i = 1 ; i < s.length() ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            if(dp[j][i]) {
                if(j == 0)
                    ans[i] = min(ans[i], dp[j][i]);
                else 
                    ans[i] = min(ans[i], ans[j-1] + dp[j][i]);
            }
        }
    }
    cout << ans[s.length() - 1] << '\n';
    return 0;
}