#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000001;
bool visited[MAX];

void bfs(int start, int end){
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	visited[start]= true;
	while(!q.empty()){
		int curLoc = q.front().first;
		int curSec = q.front().second;
		q.pop();
		if(curLoc == end){
			cout << curSec;
			return;
		}
		if (curLoc + 1 < MAX && !visited[curLoc + 1]){
            q.push(make_pair(curLoc + 1, curSec + 1));
            visited[curLoc + 1] = true;
        }
        if (curLoc - 1 >= 0 && !visited[curLoc - 1]){
            q.push(make_pair(curLoc - 1, curSec + 1));
            visited[curLoc - 1] = true;
         }
        if (curLoc * 2 < MAX && !visited[curLoc * 2]){
            q.push(make_pair(curLoc * 2, curSec + 1));
            visited[curLoc * 2] = true;
        }
	}
}
int main() {
	int n,k;
	cin >> n >> k;
	bfs(n,k);
	return 0;
}