#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int dp[111];
vector < pair<int,int> > v;
int main() {
    int N; cin >> N;
    int res = 0;
    v.push_back({0,0});
    for(int i = 0 ; i < N ; i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    
    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < i ; j++){
            if(v[i].second > v[j].second){
                if(dp[j] >= dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        res = max(res,dp[i]);
    }
    cout << N - res << '\n';
    return 0;
}