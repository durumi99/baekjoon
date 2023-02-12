#include <bits/stdc++.h>

#define MAX 1001
using namespace std;

long long arr[MAX];
set <long long> s;
int N; 
vector <int> v, vv;
long long ans = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());

    for(int i = 0 ; i < N ; i++) {
        for(int j = i ; j < N ; j++) {
            vv.push_back(v[i]+v[j]);
        }
    }
    sort(vv.begin(), vv.end());
    
    // for(int i = N-1 ; i >= 3 ; i--) {
    //     for(int j = i-1 ; j >= 2 ; j--) {
    //         if(binary_search(vv.begin(), vv.end(), v[i]- v[j])) {
    //             cout << v[i];
    //             return 0;
    //         }
    //     }
    // }
    
    int result = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(binary_search(vv.begin(), vv.end(), v[j]-v[i])){
                result = max(result, v[j]);
            }
        }
    }

    cout<<result;
    return 0;
}