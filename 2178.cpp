#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int arr[100][100];
int checked[100][100];
bool visited[100][100];
int cnt,n,m;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
void f(int i,int j){
	visited[i][j] = true;
	queue< pair <int,int> > q;
	q.push(make_pair(i,j));
	while(!q.empty()){
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		
		for(int k = 0 ; k < 4; k++){
			int newX = x + dx[k];
			int newY = y + dy[k];
			 if (0 <= newX && newX < m && 0 <= newY && newY < n && arr[newY][newX] == 1 && !visited[newY][newX] && checked[newY][newX] == 0) {
                checked[newY][newX] = checked[y][x] + 1;
                visited[newY][newX] = true;
                q.push(make_pair(newY, newX));
            }
        }
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			scanf("%1d",&arr[i][j]);
	f(0,0);	
	cout << checked[n-1][m-1]+1;
	return 0;
}