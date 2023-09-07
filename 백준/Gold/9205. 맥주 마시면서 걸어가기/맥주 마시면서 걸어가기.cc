#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int visited[101];
int x[101], y[101]; 
int n; 
int homeX, homeY;
int pentaX, pentaY; 

bool canMove(int startX, int startY, int destX, int destY) {
    int dist = abs(startX - destX) + abs(startY - destY);
    
    if(dist <= 20 * 50) {
        return true;
    }
    
    return false;
}

bool dfs(int curX, int curY) {
    if(canMove(curX, curY, pentaX, pentaY)) {
        return true;
    }
    vector <bool> res;    
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i] && canMove(curX, curY, x[i], y[i])) {
            visited[i] = 1;
            res.push_back(dfs(x[i], y[i]));
        }
    }
    for(int i = 0 ; i < res.size() ; i++) {
        if(res[i])
            return true;
    }
    
    return false;
}
int main() {
    int TC ; cin >> TC;
    while(TC--) {
        cin >> n;
        
        bool result = false;
        cin >> homeX >> homeY;
        for(int i = 0 ; i < n ; i++) {
            cin >> x[i] >> y[i];
        }
        cin >> pentaX >> pentaY;
        result = dfs(homeX, homeY);
        
        if(result) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }
        memset(visited, 0, sizeof(visited));
        memset(x, 0, sizeof(x));
        memset(x, 0, sizeof(y));
    }
    
    return 0;
}