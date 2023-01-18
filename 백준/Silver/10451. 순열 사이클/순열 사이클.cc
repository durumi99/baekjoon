#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int *visited, int cur, vector <int> graph[]) {
	int next = graph[cur][0]; 
	
	if(!visited[next]){
		visited[next] = 1;
		dfs(visited, next, graph);
	}
	return;
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector <int> graph[n+1];
		for(int i = 1 ; i <= n ; i++) {
			int tmp; cin >> tmp;
			graph[i].push_back(tmp);
		}
		int cnt = 0;
		int visited[n+1] = {0, }; 
		for(int i = 1 ; i <= n ; i++){
			if(!visited[i]) {
				// cout << i << ' ';
				visited[i] = 1;
				dfs(visited, i, graph);
				cnt++;
			}
		}
		cout <<cnt << '\n';
	}
	return 0;
}