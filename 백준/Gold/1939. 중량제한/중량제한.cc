#include <bits/stdc++.h>

#define MAX 10001
using namespace std;

int N, M;
vector < pair<int, pair<int,int>> > bridge;
int fac1, fac2;
int root[MAX];

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
}


int main() {
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bridge.push_back({c, {a, b}});
    }
    sort(bridge.begin(), bridge.end(), greater<>());
    cin >> fac1 >> fac2;
    
    for(int i = 1 ; i <= N ; i++)
        root[i] = i;

    for(int i = 0 ; i < bridge.size() ; i++) {
        int c = bridge[i].first;
        int a = bridge[i].second.first;
        int b = bridge[i].second.second;
        unionF(a, b);
        if(find(fac1) == find(fac2)) {
            cout << c;
            break;
        }
    }
    return 0;
}