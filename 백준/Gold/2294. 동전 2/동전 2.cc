#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
int n, k;
int dp[10001];
vector <int> coin;

void makeDp(){
    dp[0] = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = coin[i] ; j <= k ; j++) {
            if(j-coin[i] != 0 && dp[j-coin[i]] == 0)
                continue;
            if(dp[j] == 0) {
                dp[j] = dp[j-coin[i]]+1;
            } else {
                dp[j] = min(dp[j], dp[j-coin[i]]+1);
            }
        }
        // for(int j = 0 ; j <= k ; j++)
        //     cout << dp[j] << ' ';
        // cout << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++) {
	    int tmp; cin >> tmp;
	    if(tmp <= k && find(coin.begin(), coin.end(), tmp) == coin.end())
	        coin.push_back(tmp);
	}
	sort(coin.begin(), coin.end());
	n = coin.size();
	
	makeDp();
	
	if(dp[k] != 0)
    	cout << dp[k];
    else
        cout << -1;
	return 0;
}