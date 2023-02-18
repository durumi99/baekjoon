#include <bits/stdc++.h>

#define MAX 21
using namespace std;

int N, M, x, y, k;
int arr[MAX][MAX];
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

vector<int> dice(7);

void moveDice(int oper) {
	
	if(oper == 1) { // 동쪽
		dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
	} else if(oper == 2) { // 서쪽	
		dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
	} else if(oper == 3) { // 북쪽
		dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
	} else if(oper == 4){ // 남쪽쪽
		dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
	}
		
	cout << dice[1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N >> M >> y >> x >> k;
	for(int i = 0 ; i < N ; i++) {
		for(int j = 0 ; j < M ; j++) {
			cin >> arr[i][j];
		}
	}
	
	int oper;
	while(k--) {
		cin >> oper;
		
		int nY = y + dy[oper];
		int nX = x + dx[oper];
		if(nY < 0 || nY >= N || nX < 0 || nX >= M)
			continue;
			
		y = nY;
		x = nX;
		
		moveDice(oper);
		
		if(arr[y][x]) {
			dice[6] = arr[y][x];
			arr[y][x] = 0;	
		} else {
			arr[y][x] = dice[6];
		}
	}
    return 0;
}