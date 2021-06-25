#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int tmt[1000][1000];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

queue < pair<int,int>> q;
queue < pair<int,int>> tmp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n,check = 0,days = 0;
	cin >> m >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ;j++){
			cin >> tmt[i][j];
			if(tmt[i][j] == 1)
				q.push(make_pair(i,j));
			else if(tmt[i][j] == 0)
				check++;
		}
	}
	if(check == 0){
		cout << 0;
		return 0;
	}
	
	while(true){
		int currsize = q.size();
		days++;
		
		for(int k = 0 ; k < currsize ; k++){
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for(int i = 0 ; i < 4 ; i++){
				int newX = x + dx[i];
				int newY = y + dy[i];
				if(0 <= newX && newX < m && 0 <= newY && newY < n && tmt[newY][newX] == 0){
					tmt[newY][newX] = 1;
					check--;
					q.push(make_pair(newY,newX));
				}
			}
		}
	
		if(check == 0){
			cout << days;
			break;
		}
		if(days > m * n){
			cout << -1;
			break;
		}
	}
}