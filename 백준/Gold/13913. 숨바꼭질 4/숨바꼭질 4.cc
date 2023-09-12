#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int visited[1000001];
int parent[1000001];
int n, k;
int ans;
queue <pair<int, int>> q; 
vector<int> path;
int main() {
    cin >> n >> k;
    q.push({n, 0});
    while(!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();
        if(x == k) {
            int idx = x;
            while(idx != n) {
                path.push_back(idx);
                idx = parent[idx];
            }
            cout << time << '\n';
            break;
        }
        int next[] = {x * 2, x - 1, x + 1};
        for(int i = 0 ; i < 3 ; i++) {
            if(next[i] < 0 || next[i] > 200000)
                continue;
            if(visited[next[i]])
                continue;
            visited[next[i]] = 1;
            q.push({next[i], time + 1});
            parent[next[i]] = x;
        }
    }
    cout << n << ' ';
    for(int i = path.size() - 1 ; i >= 0 ; i--) {
        cout << path[i] << ' ';
    }
    return 0;
}