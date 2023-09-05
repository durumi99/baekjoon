#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    
    stack < pair<int, int> > s;
    stack <int> answer;
    
    for(int i = 0 ; i < n ; i++) {
        int h; cin >> h;
        
        while(!s.empty()) {
            if(s.top().second > h) {
                cout << s.top().first << ' ';
                break;
            }
            
            s.pop();
        }
        
        if(s.empty())
            cout << 0 << ' ';
            
        s.push({i+1, h});
    }
    return 0;
}