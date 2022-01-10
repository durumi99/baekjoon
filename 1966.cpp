#include <iostream>
#include <queue>
using namespace std;

int main() {
	int tc,tmp;
	cin >> tc;
	int n,m;
	for(int i = 0 ; i < tc ; i++){
		cin >> n >> m;
		int cnt = 0;
		queue <pair<int,int>> q;
		priority_queue <int> pq;
		for(int j = 0 ; j < n ; j++){
			cin >> tmp;
			q.push({tmp,j});
			pq.push(tmp);
		}
		while(!q.empty()){
			int nowval = q.front().first;
			int nowindx = q.front().second;
			q.pop();
			if(pq.top() == nowval){
				pq.pop();
				cnt++;
				if(nowindx == m){
					cout << cnt << endl;
					break;
				}
			}
			else{
				q.push({nowval,nowindx});
			}
		}
	}
	return 0;
}