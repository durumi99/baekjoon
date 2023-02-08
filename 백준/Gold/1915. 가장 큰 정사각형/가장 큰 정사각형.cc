#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int arr[1001][1001];
int dp[1001][1001];
int maxArea = 0;

void makeDp(){
    for(int i = 1 ; i < n ; i++) {
        for(int j = 1 ; j < m ; j++) {
            if(dp[i][j] == 0)
                continue;
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
            maxArea = max(dp[i][j], maxArea);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++) {
	    string s ; cin >> s;
	    for(int j = 0 ; j < m ; j++) {
	       // cin >> arr[i][j];
            arr[i][j] = s[j]-'0';
	        if(arr[i][j] == 1){
	            dp[i][j] = 1;
	            maxArea = 1;
	        }
	    }
	}
	
    if(maxArea == 0) {
        cout << 0;
        return 0;
    }
    
	makeDp();
	
	cout << maxArea * maxArea; 
	return 0;
}