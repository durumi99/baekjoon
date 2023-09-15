#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
int num[111];
set <int> ans;
void f(int startIdx, int curIdx) {
    
    int visited[n+1] = {0, };
    bool check = false;
    while(true) {
        if(visited[curIdx])
            break;
        visited[curIdx] = 1;
        if(curIdx  == startIdx) {
            check = true;
            break;
        }
        curIdx = num[curIdx];
    }
    if(check) {
        for(int i = 1 ; i <= n ; i++) {
            if(visited[i]) {
                ans.insert(i);
            }
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> num[i];
    }
    for(int i = 1 ; i <= n ; i++) {
        f(i, num[i]);
    }
    
    cout << ans.size() << '\n';
    for(auto el : ans)
        cout << el << '\n';
    return 0;
}