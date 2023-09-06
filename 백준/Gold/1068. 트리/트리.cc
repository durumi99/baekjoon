#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <int> child[55];

int main() {
    int n; cin >> n;
    int rootIdx;
    for(int i = 0 ; i < n ; i++) {
        int tmp; cin >> tmp;
        if(tmp != -1) {
            child[tmp].push_back(i); 
        } else {
            rootIdx = i;
        }
    }
    int del; cin >> del;
    
    int cnt = 0;
    
    queue <int> q;
    q.push(rootIdx);
    while(!q.empty()) {
        int curIdx = q.front();
        q.pop();
        
        if(curIdx == del) {
            continue;
        }
        if(child[curIdx].empty() || (child[curIdx][0] == del && child[curIdx].size() == 1)) {
            cnt++;
        }
        for(int i = 0 ; i < child[curIdx].size() ; i++) {
            q.push(child[curIdx][i]);
        }
    }
    
    cout << cnt;
    return 0;
}