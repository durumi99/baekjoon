#include <iostream>
#include <cmath>
using namespace std;
const int MN = 1001;
int dp[MN], arr[MN];
int main() {
    int N; cin >> N;
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i];
    int res = 0;
    for(int i = 0 ; i < N ; i++){
        dp[i] = arr[i];
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i],dp[j]+arr[i]);
            }
        }
        res = max(res,dp[i]);
    }
    cout << res;
}