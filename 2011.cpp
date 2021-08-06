#include <iostream>
#include <string>

#define MAXN 5001
#define mod 1000000
using namespace std;

int dp[MAXN];
int arr[MAXN];
int len;
void inputF(){
    string s; cin >> s;
    len = s.length();
    if(len >= MAXN || s[0] == 0 )
        exit(0);
    for(int i =1 ; i <= len ; i++)
        arr[i] = s[i-1] - '0';
    
}

void solve(){
    dp[0] =  1;
    for(int i = 1 ; i <= len ; i++){
        if(arr[i] >= 1 && arr[i] <= 9)
            dp[i] = dp[i-1];
        int tmp = arr[i] + arr[i-1] * 10;
        if ( tmp <= 26 && tmp >= 10){
            dp[i] = (dp[i] + dp[i-2]) % mod;
        }
    }
    cout << dp[len] ; 
}
int main() {
    inputF();
    solve();
    return 0;
}