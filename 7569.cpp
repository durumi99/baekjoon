#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
int tmt[100][100][100];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int dz[2]={1,-1};
queue< tuple <int,int,int> > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n,h,check = 0,days = 0;
	cin >> m >> n >> h;
	for(int k = 0 ; k < h ; k++)
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ;j++){
				cin >> tmt[k][i][j];
				if(tmt[k][i][j] == 1)
					q.push(make_tuple(k,i,j));
				else if(tmt[k][i][j] == 0)
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
			int x = get<2>(q.front());
			int y = get<1>(q.front());
			int z = get<0>(q.front());
			q.pop();
			for(int i = 0 ; i < 4 ; i++){
				int newX = x + dx[i];
				int newY = y + dy[i];
				if(0 <= newX && newX < m && 0 <= newY && newY < n && tmt[z][newY][newX] == 0){
					tmt[z][newY][newX] = 1;
					check--;
					q.push(make_tuple(z,newY,newX));
				}
			}
			for(int i = 0 ; i < 2 ; i++){
				int newZ = z + dz[i];
				if(0 <= newZ && newZ < h && tmt[newZ][y][x] == 0){
					tmt[newZ][y][x] = 1;
					check--;
					q.push(make_tuple(newZ,y,x));
				}
			}
		}
	
		if(check == 0){
			cout << days;
			break;
		}
		if(days > m * n * h){
			cout << -1;
			break;
		}
	}
}