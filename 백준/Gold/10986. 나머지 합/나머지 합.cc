#include <bits/stdc++.h>

using namespace std;
int n, m;

int main() {
    long sum = 0;
    long ans = 0;
    cin >> n >> m;
    int arr[n];
    long long rest[m] = {0, };
    
    for(int i = 0 ; i < n ; i++) {
        int tmp; cin >> tmp;
        sum = (sum + tmp) % m;
        arr[i] = sum;
        if(arr[i] == 0)
            ans++;
        rest[arr[i]]++;
    }
    for(int i = 0 ; i < m ; i++) {
        ans += rest[i] * (rest[i]-1) / 2;
    }
    
    cout << ans;
    return 0;
}