#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    int arr[n][2];
    
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for(int i = 0 ; i < n ; i++) {
        int rank = 1;
        for(int j = 0 ; j < n ; j++) {
            if(arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1])
                rank++;
        }
        cout << rank << ' ';
    }
    return 0;
}