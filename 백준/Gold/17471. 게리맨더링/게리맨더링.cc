#include <bits/stdc++.h>

#define MAX 11
#define INF 987654321
using namespace std;

int N;
int pop[MAX];
int road[MAX][MAX];
int ans = INF;
int visited[MAX];
int selected[MAX];

void input() {
	cin >> N;  
	for(int i = 1 ; i <= N ; i++) {
		cin >> pop[i];
	}
	
	for(int i = 1; i <= N ; i++) {
		int tmp; cin >> tmp;
		for(int j = 0 ; j < tmp ; j++) {
			int k; cin >> k;
			road[i][k] = 1;
		}
	}
}

bool checkConnection(vector <int> v, int T) {
	memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(v[0]);        
    visited[v[0]] = 1;
    int cnt = 1;
 
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
 
        for (int i = 1; i <= N; i++) {
            if (road[cur][i] && selected[i] == T && !visited[i])
            {
                visited[i] = 1;
                cnt++;        // 갯수를 계속해서 Count
                q.push(i);
            }
        }
    }
 
    /* 2번 조건에 위배 되지 않는다 = BFS에서 Count한 값과 Vector의 Size가 같다. */
    if (v.size() == cnt) 
    	return true;
    return false;
}
bool check() {
	 vector <int> A, B;
	 
	 for (int i = 1; i <= N; i++) {
        if (selected[i]) 
        	A.push_back(i); // 1선거구 = A Vector
        else 
        	B.push_back(i);                   // 2선거구 = B Vector
    }
 
    /* 1번 조건 Check */
    if (A.size() == 0 || B.size() == 0) 
    	return false;
 
    /* 2번 조건 Check */
    if (!checkConnection(A, 1)) 
    	return false;
 
    if (!checkConnection(B, 0)) 
    	return false;
 
    return true;
}
void cal() {
	int aPop = 0;
	int bPop = 0;
	
	for(int i = 1 ; i <= N ; i++) {
		if(selected[i]) {
			aPop += pop[i];
		} else {
			bPop += pop[i];
		}
	}
	
	ans = min(ans, abs(aPop-bPop));
}
void dfs(int idx, int cnt) {
	if(cnt >= 1 ) {
		if(check()) {
			cal();
		}
	}
	
	for(int i = idx; i <= N ; i++) {
		if(selected[i])
			continue;
		selected[i] = 1;
		dfs(i, cnt+1);
		selected[i] = 0;
	}
}
void solve() {
	dfs(1, 0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	input();	
	solve();
	if(ans == INF)
		cout << -1;
	else
		cout << ans;
    return 0;
}