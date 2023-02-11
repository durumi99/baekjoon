#include <bits/stdc++.h>

#define MAX 2000001
using namespace std;

int f;
int root[MAX];
int friends[MAX];
int tmp;
string a, b; 
map <string, int> m;

int find(int x) {
    if(root[x] == x)
        return x;
    
    return root[x] = find(root[x]);
}

void unionF(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y)
        return;

    root[max(x, y)] = min(x, y);
    friends[min(x, y)] += friends[max(x, y)];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc; cin >> tc;
    while(tc--) {           
        m.clear();
        tmp = 0;
        cin >> f;
        
        for(int i = 1 ; i < MAX ; i++) {
            root[i] = i;
            friends[i] = 1;
        }
        int aIdx, bIdx;
        for(int i = 0 ; i < f ; i++) {
            cin >> a >> b;
            
            auto it = m.find(a);
            if(it == m.end()) {
                // m.insert({a,tmp});
                m[a] = ++tmp;
                aIdx = tmp;
            } else {
                aIdx = it->second;
            }
            
            it = m.find(b);
            if(it == m.end()) {
                // m.insert({b,tmp++});
                m[b] = ++tmp;
                bIdx = tmp;
            } else {
                bIdx = it->second;
            }
            
            unionF(aIdx, bIdx);
            cout << friends[find(aIdx)] << '\n';
        }
    }
    return 0;
}