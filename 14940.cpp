#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[1001][1001];
int checked[1001][1001];
bool visited[1001][1001];
int cnt,n,m;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
void f(int i,int j){
	visited[i][j] = true;
	queue< pair <int,int> > q;
	q.push(make_pair(i,j));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int k = 0 ; k < 4; k++){
			int newX = x + dx[k];
			int newY = y + dy[k];
			 if (0 <= newX && newX < n && 0 <= newY && newY < m && arr[newX][newY] == 1 && !visited[newX][newY] && checked[newX][newY] == 0) {
                checked[newX][newY] = checked[x][y] + 1;
                visited[newX][newY] = true;
                q.push(make_pair(newX, newY));
            }
        }
	}
}
int main() {
	int startX,startY;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 2)			{
				startX = i;
				startY = j;
			}
		}
	f(startX,startY);	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(arr[i][j] == 1 && checked[i][j] == 0)
				cout << -1 << ' ';
			else
				cout << checked[i][j] << ' ';
			}
		cout << '\n';
	}
	
	return 0;
}