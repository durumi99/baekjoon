#include <bits/stdc++.h>

#define MAX 15050
#define INF 987654321
using namespace std;

int N, M;
int mat[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++)
        cin >> mat[i];
    
    sort(mat, mat+N);
    int ans = 0;
    int left = 0;
    int right = N-1;
    while(left < right) {
        int sum = mat[left] + mat[right];
        if(sum <= M) {
            if(sum == M)
                ans++;
            left++;
        } else {
            right--;
        }
    }
    
    cout << ans;
    return 0;
}