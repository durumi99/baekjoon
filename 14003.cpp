#include <iostream>
#include <algorithm>
using namespace std;

const int MN = 1001010;
int dp[MN], arr[MN] , bt[MN], N , l ,a;
vector <int> res;
int main() {
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i];
        
    for(int i = 0 ; i < N ; i++){
        auto it = lower_bound(dp, dp + l,arr[i]);
        if(*it == 0) l++;
        *it = arr[i];
        bt[i] = it-dp;
    }
    
    cout << l << '\n';
    for(int i = N -1 ; i >= 0 ; i--){
        if(bt[i] == l - 1){
            res.push_back(arr[i]);
            l--;
        }
    }
    reverse(res.begin(),res.end());
    for(int a : res)
        cout << a << ' ';
    return 0;
}