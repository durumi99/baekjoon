#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int location[101];
int visited[101];

void bfs(){
	queue<pair<int,int> > q;
	q.push({1,0}); // 시작 위치 1, 시작 카운트 0
	
	while(!q.empty()){
		int tmp = q.front().first; // 현재 위치
		int cnt = q.front().second; // 굴린 주사위 수
		q.pop();
		for(int i = 1; i <=6 ; i++){
			if( tmp+i == 100 || location[tmp+i] == 100){ //100에 도착
				cout << cnt+1;
				return;
			}
			else if(!visited[tmp+i]){ // 방문 노드 재방문 X
				visited[tmp+i] = 1;
				if(location[tmp+i] != 0){ // 뱀 이나 사다리 있는 경우
					visited[location[tmp+i]] = 1;
					q.push({location[tmp+i],cnt+1});
				}
				else // 없는 경우
					q.push({tmp+i,cnt+1});
			}
		}
	}
}
int main() {
	int n,m;
	cin >> n >> m;
	int x,y;
	for(int i = 0 ; i < n + m ; i++){
		cin >> x >> y;
		location[x] = y;
	}
	
	bfs();
	return 0;
}