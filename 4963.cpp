#include <iostream>
#include <cstring>
using namespace std;

int w,h;
int map[50][50];
bool visited[50][50];
typedef struct{
	int dx, dy;
}dir;

dir direction[8] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} }; //E

void countLand(int y,int x){
	if (!map[y][x] || visited[y][x])
		return;
	visited[y][x] = true; //해당 지점 방문 표시
	
	for (int i = 0; i < 8; i++){
		int newY = y + direction[i].dy;
		int newX = x + direction[i].dx;
		if (newX >= 0 && newX < w && newY >= 0 && newY < h)
			countLand(newY, newX);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin >> w >> h){
		if(w == 0 && h == 0)
			break;
		memset(visited, false, sizeof(visited));
		for(int i = 0 ; i < h ; i++)
			for(int j = 0 ; j < w ; j++)
				cin >> map[i][j];
		int land = 0;
		for(int i = 0 ; i < h ; i++)
			for(int j = 0 ; j < w ; j++)
				if(map[i][j] && !visited[i][j]){
					countLand(i,j);
					land++;
				}
		cout << land << '\n';
		
	}
	return 0;
}