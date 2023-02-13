#include <bits/stdc++.h>

#define MAX 2001
#define INF 987654321
using namespace std;

int n, m, t, s, g, h; 
int result1[MAX], result2[MAX];
int ghDist, cr1, cr2;
vector < pair<int, int> > v[MAX];
vector <int> ans;

void dijkstra(int start, int* visited) {
    queue <int> q;
    for(int i = 1 ; i <= n ; i++) {
        visited[i] = INF;
    }
    
    visited[start] = 0;
	q.push(start);
        
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0 ; i < v[cur].size() ; i++) {
            int nextL = v[cur][i].first;
            int nextC = v[cur][i].second + visited[cur];

            if(visited[nextL] <= nextC) {
                continue;
            }
            
            visited[nextL] = nextC;
            q.push(nextL);
        }
    }
    
 //   for(int i = 1 ; i <= n ; i++) {
 //   	cout << visited[i] << ' ';
 //   }
	// cout << '\n';	
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC; cin >> TC;
    while(TC--) {
        // tt.clear();
        ans.clear();
		memset(result1, 0, sizeof(result1));
		memset(result2, 0, sizeof(result2));
        for (int i = 0; i < MAX; i++)
			v[i].clear();
		
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        
        for(int i = 0 ; i < m ; i++) {
            int a, b, d; cin >> a >> b >> d;
            
            v[a].push_back({b, d});
            v[b].push_back({a, d});
            if ((a == g && b == h) || (a == h && b == g))
				ghDist = d; 
        }
        
        // for(int i = 0 ; i < t ; i++){
        //     int tmp; cin >> tmp;
        //     tt.push_back(tmp);
        // }
        // sort(tt.begin(), tt.end());
        
        dijkstra(s, result1);
        
        if(result1[g] > result1[h]) {
        	cr1 = h;
        	cr2 = g;
        } else {
        	cr1 = g;
        	cr2 = h;
        }
        
        dijkstra(cr2, result2);
        
        for(int i = 0 ; i < t ; i++) {
            int target; cin >> target;
            
            if(result1[target] == result1[cr1] + ghDist + result2[target])
        		ans.push_back(target);
        }
        sort(ans.begin(), ans.end()); // 정답 오름차순 정렬

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
    }
    return 0;
}