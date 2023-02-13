#include <bits/stdc++.h>

#define MAX 300001
#define INF 987654321
using namespace std;

int N, M, K, X;
vector <int> v[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K >> X;
    
    for(int i = 0 ; i < M ; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        // v[b].push_back(a);
    }
    
    int visited[N];
    for(int i = 1 ; i <= N ; i++)
    	visited[i] = INF;
    visited[X] = 0;
    
    queue <int> q;
    q.push(X);
    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(visited[cur] == K) {
            continue;
        }
        
        for(int i = 0 ; i < v[cur].size() ; i++) {
        	int next = v[cur][i];
            if(visited[next] > visited[cur]+1) {
                visited[next] = visited[cur]+1;
                q.push(next);
            }
        }
    }
    bool check = true;
    for(int i = 1 ; i <= N ; i++) {
    	if(visited[i] == K) {
    		check = false;
    		cout << i << '\n';
    	}
    }
    if(check) 
    	cout << -1;
    return 0;
}