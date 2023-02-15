#include <bits/stdc++.h>

#define MAX 55
using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int room[MAX][MAX];
int y, x;
int dir;

bool check(int y, int x) {
	if(y < 0 || x < 0 || y >= N || x >= M) 
		return false;
	if(room[y][x] != 0)
		return false;
	
	return true;
}

bool check2(int y, int x) {
	if(y < 0 || x < 0 || y >= N || x >= M) 
		return false;
	if(room[y][x] == 1)
		return false;
	
	return true;
}

bool check4(int y, int x) {
	for(int i = 0 ; i < 4 ; i++) {
		int nY = y + dy[i];
		int nX = x + dx[i];
		if(check(nY, nX))
			return true;
	} 
	
	return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    cin >> y >> x >> dir;
    for(int i = 0 ; i < N ; i++) {
    	for(int j = 0 ; j < M ; j++) {
    		cin >> room[i][j];
    	}
    }		
    		
	int ans = 0;
	
	
	
	while(true) {
		
		if(room[y][x] == 0) { // 1번의 경우
			ans++;
			room[y][x] = -1;
		} else if(!check4(y, x)) { // 2번의 경우
			int nY = y - dy[dir];
			int nX = x - dx[dir];
			if(check2(nY, nX)) {
				y = nY;
				x = nX;
			} else {
				cout << ans;
				break;
			}
		} else { // 3번의 경우
			dir = (dir+3) % 4;
			int nY = y + dy[dir];
			int nX = x + dx[dir];
			if(check(nY, nX)) {
				y = nY;
				x = nX;
			}
		}
	}
	
    return 0;
}