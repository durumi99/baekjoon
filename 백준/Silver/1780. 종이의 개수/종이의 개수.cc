#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int paper[2200][2200];
int cnt[3];

bool sameNum(int y, int x, int n) {
	int tmp = paper[y][x];
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			if(paper[y+i][x+j] != tmp){
				return false;
			}
		}
	}
	
	return true;
};

void DQ(int y, int x, int n) {
	if(sameNum(y, x, n)) {
		cnt[paper[y][x]+1]++;
		return;
	}
	
	for(int i = 0 ; i < n ; i += n/3)
		for(int j = 0 ; j < n ; j += n/3) {
			DQ(y+i, x+j, n/3);
		}
};

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> paper[i][j];
    DQ(0, 0, n);
    
    for(int i = 0 ; i < 3 ; i++)
    	cout << cnt[i] << '\n';
    return 0;
}