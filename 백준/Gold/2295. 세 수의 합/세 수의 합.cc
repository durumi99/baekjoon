#include <bits/stdc++.h>

#define MAX 1001
using namespace std;

int N; 
vector <int> v, vv;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    for(int i = 0 ; i < N ; i++) {
        for(int j = i ; j < N ; j++) {
            vv.push_back(v[i]+v[j]);
        }
    }
    
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    
    for(int i = N-1 ; i >= 0 ; i--) {
        for(int j = i ; j >= 0 ; j--) {
            int target = v[i] - v[j];
            if(binary_search(vv.begin(), vv.end(), target)) {
                cout << v[i];
                return 0;
            }
        }
    }
    

    return 0;
}