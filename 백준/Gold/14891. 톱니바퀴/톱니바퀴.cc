#include <bits/stdc++.h>

using namespace std;

int gear[5][8];
int ans = 0;
int point[5] = {0, 1, 2, 4, 8};
int visited[5];

void moveGear(int num, int dir) {

	if(num-1 >= 1 && !visited[num-1] && gear[num][6] != gear[num-1][2]) {
		visited[num-1] = 1;
		moveGear(num-1, -dir);
	}
	
	if(num+1 <= 4 && !visited[num+1] && gear[num][2] != gear[num+1][6]) {
		visited[num+1] = 1;
		moveGear(num+1, -dir);
	}
	
	if(dir == 1) {
		int tmp = gear[num][7];
		for(int i = 7 ; i >= 1 ; i--) {
			gear[num][i] = gear[num][i-1];
		}
		gear[num][0]= tmp;
	} else {
		int tmp = gear[num][0];	
		for(int i = 1 ; i <= 7 ; i++) {
			gear[num][i-1] = gear[num][i];
		}
		gear[num][7]= tmp;
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 1 ; i <= 4 ; i++) {
    	string tmp; cin >> tmp;
    	for(int j = 0 ; j < 8 ; j++) {
    		gear[i][j] = tmp[j]-'0';
    	}
    }
    int k; cin >> k;
    
    while(k--) {
    	int num, dir; cin >> num >> dir;
    	visited[num] = 1;
    	moveGear(num, dir);
    	memset(visited, 0, sizeof(int) * 5);
    }
    
    for(int i = 1 ; i <= 4 ; i++) {
    	if(gear[i][0] == 1) {
    		ans += point[i];
    	}
    }
    cout << ans;
    return 0;
}