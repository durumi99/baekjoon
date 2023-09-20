#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int visited[1001][1001];

int main() {
    int s; cin >> s;
    
    queue < pair<pair<int, int>, int> > q;
    q.push({{1, 0}, 0});
    visited[1][0] = 1;
    
    while(!q.empty()) {
        int cur = q.front().first.first;
        int copy = q.front().first.second;
        int cnt = q.front().second;
        
        q.pop();
        
        if(cur == s) {
            cout << cnt;
            break;
        }
        
        if(cur - 1 >= 0 && !visited[cur - 1][copy]) {
            visited[cur - 1][copy] = 1;
            q.push({{cur - 1, copy}, cnt + 1});
        }
        if(copy != 0 && cur + copy <= 1000 && !visited[cur + copy][copy]) {
            visited[cur + copy][copy] = 1;
            q.push({{cur + copy, copy}, cnt + 1});
        }
        if(!visited[cur][cur]) {
            visited[cur][cur] = 1;
            q.push({{cur, cur}, cnt + 1});
        }
    }
    return 0;
}