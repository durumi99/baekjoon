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
    dp[0] = 1;
    for(int i = 0 ; i < n ; i++) {
        for(int j = coin[i] ; j <= k ; j ++) {
            dp[j] += dp[j-coin[i]];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++) {
	    int tmp; cin >> tmp;
	    if(tmp <= k)
	        coin.push_back(tmp);
	}
	sort(coin.begin(), coin.end());
	n = coin.size();
	
	makeDp();
	
	cout << dp[k];
	return 0;
}