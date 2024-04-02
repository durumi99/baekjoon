#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int getDist(string a, string b, string c) {
    int dist = 0;
    
    for(int idx = 0 ; idx < 4 ; idx++) {
        if(a[idx] != b[idx]) {
            dist++;
        }
        
        if(a[idx] != c[idx]) {
            dist++;
        }
        
        if(b[idx] != c[idx]) {
            dist++;
        }
    }
    return dist;
}

int main() {
    int T; cin >> T;
    
    while(T--) {
        int n; cin >> n;
        
        
        vector <string> MBTI(n);
        for (int i = 0 ; i < n ; i++) {
            cin >> MBTI[i];
        }
        
        if(n >= 33) {
            cout << "0\n";
            continue;
        }
        
        int dist = INF;
        
        for (int i = 0 ; i < n ; i++) {
            for (int j = i + 1 ; j < n ; j++) {
                for (int k = j + 1 ; k < n ; k++) {
                    dist = min(dist, getDist(MBTI[i], MBTI[j], MBTI[k]));
                }
            }
        }
        
        cout << dist << '\n';
    }
    return 0;
}