
#include <iostream>
#include <queue>
using namespace std;
typedef long long int lli;

void bfs(lli start, lli end){
	bool visited[end+1];
    lli ans = -1;
	queue<pair<lli, lli>> q;
	q.push({start,1});
	while(!q.empty()){
		lli curLoc = q.front().first;
		lli curSec = q.front().second;
		q.pop();
		if(curLoc == end){ 
	        ans = curSec;
	        break;
		}
		
		if (curLoc * 2 <= end){
            q.push({curLoc * 2, curSec + 1});
        }
		if (curLoc * 10 + 1 <= end){
            q.push({curLoc * 10 + 1, curSec + 1});
        }
	}
	cout << ans;
}
int main() {
	lli a,b;
	cin >> a >> b;
	bfs(a,b);
	return 0;
}