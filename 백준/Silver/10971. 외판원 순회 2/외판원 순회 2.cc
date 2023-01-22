#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int W[10][10];
int visited[10];
long long minCost = 10000000;

void tsp(int curLoc, long long curCost, int visitCnt) {
	if(visitCnt == N && W[curLoc][0] != 0) {
		minCost = min(minCost, curCost + W[curLoc][0]);
		return;
	}
	for(int i = 0 ; i < N ; i++){
		if(i == curLoc || W[curLoc][i] == 0)
			continue;
		if(!visited[i]) {
			visited[i] = 1;
			tsp(i, curCost+W[curLoc][i], visitCnt+1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> N;
	for(int i = 0 ; i < N ; i++)
		for(int j = 0; j < N ; j++)
			cin >> W[i][j];
	visited[0] = 1;
	tsp(0, 0, 1);
	cout << minCost;
	return 0;
}