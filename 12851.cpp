#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000001;
bool visited[MAX];
int ansTime = MAX, ansWay;
void bfs(int start, int end){
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	visited[start]= true;
	while(!q.empty()){
		int curLoc = q.front().first;
		int curSec = q.front().second;
		visited[curLoc] = true;
		q.pop();
		if(curLoc == end && curSec == ansTime){ // 나머지
		    ansWay++;
		}
		if(curLoc == end && ansTime == MAX){ // 첫 도착
			ansTime = curSec;
			ansWay++;
		}
		if (curLoc + 1 < MAX && !visited[curLoc + 1]){
            q.push(make_pair(curLoc + 1, curSec + 1));
        }
        if (curLoc - 1 >= 0 && !visited[curLoc - 1]){
            q.push(make_pair(curLoc - 1, curSec + 1));
        }
        if (curLoc * 2 < MAX && !visited[curLoc * 2]){
            q.push(make_pair(curLoc * 2, curSec + 1));
        }
	}
}
int main() {
	int n,k;
	cin >> n >> k;
	bfs(n,k);
	cout << ansTime << '\n' << ansWay;
	return 0;
}