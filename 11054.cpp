#include <iostream>
#include <cmath>
using namespace std;
const int MN = 1001;
int dp[MN], arr[MN] , dp2[MN];
int main() {
    int N; cin >> N;
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i];
    int res = 0 ;
    for(int i = 0 ; i < N ; i++){
        dp[i] = dp2[i] = 1;
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
            if(arr[i] < arr[j]){
                dp2[i] = max(dp2[i],dp2[j]+1);
            }
        }
    }
    for(int i = N-1 ; i >= 0 ; i--){
        dp2[i] = 1;
        for(int j = N-1 ; j > i ; j--){
            if(arr[i] > arr[j]){
                dp2[i] = max(dp2[i],dp2[j]+1);
            }
        }
    }
    for(int i = 0 ; i < N ; i++){
        res = max(res,dp[i]+dp2[i]);
    }
    cout << res -1;
}