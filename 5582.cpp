#include <iostream>
#include <string>
using namespace std;
const int MN = 4001;
int ans;
int dp[MN][MN];
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    
    for(int i = 1 ; i < s1.size() ; i++){
        for(int j = 1 ; j < s2.size() ; j++){
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            ans = max(dp[i][j],ans);
        }
    }
    
    cout << ans;
}