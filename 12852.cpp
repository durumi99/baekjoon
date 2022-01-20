#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int dp[1111111];
    vector <int> v[1111111];
    dp[1] = 0;
    v[1].push_back(1);
    for(int i = 2; i <= n ; i++){
        //v[i].push_back(i);
        if(i % 6 == 0){
            dp[i] = min(min(dp[i/2],dp[i/3]),dp[i-1]);
            if(dp[i] == dp[i-1]){
                v[i] = v[i-1];
            }
            else if(dp[i] == dp[i/2]){
                v[i] = v[i/2];
            }
            else{
                v[i] = v[i/3];
            }
        }
        else if(i % 3 == 0){
            dp[i] = min(dp[i-1],dp[i/3]);
            if(dp[i] == dp[i-1]){
                v[i] = v[i-1];
            }
            else if(dp[i] == dp[i/3]){
                v[i] = v[i/3];
            }
        }
        else if(i % 2 == 0){
            dp[i] = min(dp[i-1],dp[i/2]);
            if(dp[i] == dp[i-1]){
                v[i] = v[i-1];
            }
            else if(dp[i] == dp[i/2]){
                v[i] = v[i/2];
            }
        }
        else{
            dp[i] = dp[i-1];
            v[i] = v[i-1];
        }
        dp[i]++;
        v[i].push_back(i);
    }
    cout << dp[n] << '\n';
    for(int i = v[n].size()-1 ; i >= 0 ; i--)
        cout << v[n][i] << ' ';
    return 0;
}