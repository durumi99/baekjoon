#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
char map[6666][6666];
// void printMap(int y, int x){
// 	for(int i = y; i < y+3 ; i++) {
// 		for(int j = x; i < x+3 ; j++) {
// 			if(i == 1 && j == 1){
				
// 			}
// 		}
// 	}
// }
void DQ(int y, int x, int n) {
	if(n == 1) {
		map[y][x] = '*';
	} else {
		for(int i = 0 ; i < n; i += n/3) {
			for(int j = 0 ; j < n ; j += n/3) {
				if(i == n/3 && j == n/3){
					continue;
				}
				DQ(i+y, j+x, n/3);
			}
		}
	}
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0 ; i < N ; i++) {
		for(int j = 0 ; j < N ; j++){
			map[i][j] = ' ';
		}
	}
	DQ(0, 0, N);
	
	for(int i = 0 ; i < N ; i++) {
		for(int j = 0 ; j < N ; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
    return 0;
}