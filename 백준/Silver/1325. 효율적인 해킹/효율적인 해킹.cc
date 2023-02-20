#include <bits/stdc++.h>

#define MAX 10001
using namespace std;

int N, M;
vector <int> arr[MAX];
int visited[MAX];
vector <int> v;
int maxCom = -1;

void bfs(int start) {
	int cnt = 0;
	int tmpvisited[N+1] = {0, };
		
	tmpvisited[start] = 1;
	queue <int> q;
	q.push(start);
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		cnt++;
		
		for(int i = 0 ; i < arr[cur].size() ; i++) {
			int next = arr[cur][i];
			if(tmpvisited[next])
				continue;
			
			tmpvisited[next] = 1;
			q.push(next);
		}
	}
	if(cnt > maxCom) {
		v.clear();
		v.push_back(start);
		maxCom = cnt;
	} else if(cnt == maxCom) {
		v.push_back(start);
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >>  N >> M ;
 
	for(int j = 0 ; j < M ; j++) {
		int a, b; cin >> a >> b;
		arr[b].push_back(a);
	}
	
    for(int i = 1 ; i <= N ; i++) {
    	if(!visited[i]) {
	    	bfs(i);
	    	visited[i] = 1;
    	}
    }
    
    sort(v.begin(), v.end());
    for(int i = 0 ; i < v.size(); i++)
    	cout << v[i] << ' ';
    return 0;
}