#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
int N,M;
int DP[10000];
int visited[10000];

void setPN(){
	for(int i = 2 ; i < 10000 ; i ++) {
		DP[i] = i;
	}
	for(int i = 2 ; i <= sqrt(10000) ; i++) {
		if(DP[i] == 0)
			continue;
		
		for(int j = i * i ; j < 10000; j += i) 
			DP[j] = 0;
	}
}

int bfs() {
	int minCnt = -1;
	visited[N] = 1;
	queue < pair<int, int> > q;
	q.push({N, 0});
	while(!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == M) {
			minCnt = cnt;
			break;
		}
		for(int i = 1000 ; i < 10000 ; i += 1000) { // 천의 자리
			int next = cur % 1000 + i;
			
			if(!visited[next] && DP[next] && next >= 1000) {
				visited[next] = 1;
				q.push({next, cnt+1});
			}
		}
		for(int i = 0 ; i < 1000 ; i += 100) { // 백의 자리
			int next = (cur / 1000) * 1000 + cur % 100 + i;

			if(!visited[next] && DP[next] && next >= 1000) {
				visited[next] = 1;
				q.push({next, cnt+1});
			}
		}
		for(int i = 0 ; i < 100 ; i += 10) { // 십의 자리
			int next = (cur / 100) * 100 + cur % 10 + i;
			
			if(!visited[next] && DP[next] && next >= 1000) {
				visited[next] = 1;
				q.push({next, cnt+1});
			}
		}
		for(int i = 1 ; i < 10 ; i++) { // 일의 자리
			int next = (cur / 10) * 10 + i;
			
			if(!visited[next] && DP[next] && next >= 1000) {
				visited[next] = 1;
				q.push({next, cnt+1});
			}
		}
	}
	return minCnt;
}

int main() {
	int TC; cin >> TC;

	setPN();
	while(TC--) {
		memset(visited, 0, sizeof(int) * 10000);
		cin >> N >> M;
		if(N == M)
			cout << 0 << '\n';
		else {
			int cnt = bfs();
			if(cnt == -1){
				cout << "Impossible\n";
			} else {
				cout << cnt << '\n';
			}
		}
	}
	return 0;
}