#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector <pair <int,int> > v;
vector <int> lim;
vector <int> dp;


int main() {
    int N,S ; cin >> N >> S;
    v.resize(N+1);
    dp.resize(N+1);
    lim.resize(N+1);
    
    for(int i = 1 ; i <= N ; i++){
        cin >> v[i].first >> v[i].second ;
    }
    sort(v.begin(),v.end());
    
    for(int i = 1 ; i <= N ; i++){
        for(lim[i] = lim[i-1] ; lim[i] < i ; lim[i]++)
            if(v[i].first - v[lim[i]].first < S){
                break;
            }
        lim[i]--;
    }
    for(int i = 1 ; i <= N ; i++)
        dp[i] = max(dp[i-1],dp[lim[i]] + v[i].second);
        
    cout << dp[N] << '\n';
    return 0;
}