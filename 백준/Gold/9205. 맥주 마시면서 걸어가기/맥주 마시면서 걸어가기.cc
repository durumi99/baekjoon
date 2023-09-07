#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canMove(int startX, int startY, int destX, int destY) {
    int dist = abs(startX - destX) + abs(startY - destY);
    
    if(dist <= 20 * 50) {
        return true;
    }
    
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    
    int TC ; cin >> TC;
    while(TC--) {
        int n; cin >> n;
        int x[n], y[n]; 
        int visited[n] = {0, };
        bool result = false;
        int homeX, homeY; cin >> homeX >> homeY;
        for(int i = 0 ; i < n ; i++) {
            cin >> x[i] >> y[i];
        }
        int pentaX, pentaY; cin >> pentaX >> pentaY;
        
        queue < pair<int, int> > q;
        q.push({homeX, homeY});
        
        while(!q.empty()) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            
            if(canMove(curX, curY, pentaX, pentaY)) {
                result = true;
                break;
            }
            for(int i = 0 ; i < n ; i++) {
                if(!visited[i] && canMove(curX, curY, x[i], y[i])) {
                    visited[i] = 1;
                    q.push({x[i], y[i]});
                }
            }
        }
        if(result) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }
        memset(visited, 0, sizeof(visited));
    }
    
    return 0;
}