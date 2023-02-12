#include <bits/stdc++.h>

#define MAX 10001
using namespace std;

int N, M, k;
int root[MAX];
int friends[MAX];
set <int> s;

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
    friends[min(x, y)] = min(friends[x], friends[y]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> k;
    for(int i = 1 ; i <= N ; i++) {
        cin >> friends[i];
        root[i] = i;
    }
    for(int i = 0 ; i < M ; i++) {
        int x, y; cin >> x >> y;
        unionF(x, y);
    }
    
    int cost = 0;
    for(int i = 1 ; i <= N ; i++) {
        int tmp = find(i);
        // cout << tmp << ' ';
        auto it = s.find(tmp);
        if(it != s.end()) {
            continue;
        } 
    
        s.insert(tmp);
        cost += friends[tmp];
    
    }
    if(cost <= k)
        cout << cost << '\n';
    else
        cout << "Oh no";
    return 0;
}