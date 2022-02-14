#include <iostream>
#include <map>
#include <algorithm>
#define MAX 1001
#define INF 1e10
using namespace std;
long long t,n,m,ans;
long long A[MAX];
long long B[MAX];
map <int,int> subSum;
void input(){
    cin >> t;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> A[i];
    cin >> m;
    for(int i = 0 ; i < m ; i++)
        cin >> B[i];
}


void solve(){
    for(int i = 0 ; i < n ; i++){
        long long sum = 0;
        for(int j = i ; j < n ; j++){
            sum += A[j];
            subSum[sum]++;
        }
    }
    for(int i = 0 ; i < m ; i++){
        long long sum = 0;
        for(int j = i ; j < m ; j++){
            sum += B[j];
            if(subSum[t-sum])
                ans += subSum[t-sum];
        }
    }
    cout << ans << '\n';
}
int main(){
    input();
    solve();
    return 0;
}