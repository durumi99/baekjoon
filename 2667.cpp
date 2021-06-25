#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> vc;
int n;
int map[25][25]={0};
int room;
typedef struct{
	int dx, dy;
}dir;

dir direction[4] = { {-1,0}, {0,-1}, {1,0}, {0,1} };
void countLand(int y,int x){
	map[y][x] = 0;
	room++;
	for (int i = 0; i < 4; i++){
		int newY = y + direction[i].dy;
		int newX = x + direction[i].dx;
		if (newX >= 0 && newX < n && newY >= 0 && newY < n && map[newY][newX] == 1)
			countLand(newY, newX);
    }
}
int main() {
	
	cin >> n;
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%1d",&map[i][j]);
   
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(map[i][j] == 1){
				room = 0;
				countLand(i,j);
				vc.push_back(room);
			}
			
	sort(vc.begin(), vc.end());
    printf("%d\n",vc.size());
    for(int i=0;i<vc.size();i++){
            printf("%d\n",vc[i]);
    }
	return 0;
}