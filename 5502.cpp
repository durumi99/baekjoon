#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MN = 5001;

int dp[MN][MN];
int main() {
    int n,tmp;
    string s1,s2;
    cin >> n >> s1;
    
    s2 = s1;
    reverse(s2.begin(),s2.end());
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    
    for(int i = 1 ; i < n + 1 ; i++){
        for(int j = 1 ; j < n + 1 ; j++){
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << n - dp[n][n] ;
}