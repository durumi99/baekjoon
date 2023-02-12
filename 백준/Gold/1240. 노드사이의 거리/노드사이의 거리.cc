#include <bits/stdc++.h>

#define MAXN 1001
#define MAXC 10001
using namespace std;

int N, M; 
int arr[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            arr[i][j] = MAXC;
        }
        arr[i][i] = 0;
    }
    for(int i = 0 ; i < N-1 ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = arr[b][a] = c; 
    }
    
    while(M--) {
        int a, b;
        cin >> a >> b;
        
        queue < pair<int, int> > q;
        int visited[MAXN] = {0, };
        q.push({a, 0});
        visited[a] = 1;
        
        while(!q.empty()) {
            int curL = q.front().first;
            int curC = q.front().second;
            q.pop();
            
            if(curL == b) {
                cout << curC << '\n';
                break;
            }
            
            for(int i = 1 ; i <= N ; i++) {
                if(visited[i] || arr[curL][i] == MAXC)
                    continue;
                visited[i] = 1;
                q.push({i, curC+arr[curL][i]});
            }
        }
        
    }
    return 0;
}