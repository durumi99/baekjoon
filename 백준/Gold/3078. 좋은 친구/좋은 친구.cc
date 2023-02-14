#include <bits/stdc++.h>

#define MAX 300001
using namespace std;

int N, K;
int lis[666666];
int cnt[22];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 0 ; i < N ; i++) {
        string tmp; cin >> tmp;
        lis[i] = tmp.size();
    }
    
    long long goodF = 0;
    
    for(int i = 0 ; i <= K ; i++) {
    	cnt[lis[i]]++;
    }
    for(int i = 0 ; i < N-1 ; i++) {
    	cnt[lis[i]]--;
    	goodF += cnt[lis[i]];
    	cnt[lis[i+K+1]]++;
    }
    cout << goodF;
    return 0;
}