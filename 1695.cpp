#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MN = 5001;

int dp[MN][MN];
int arr1[MN],arr2[MN];
int main() {
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
       cin >> arr1[i];
       arr2[n-i+1] = arr1[i];
    }
   
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(arr1[i] == arr2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout <<  n - dp[n][n] ;
}