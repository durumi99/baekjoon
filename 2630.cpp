#include <iostream>
using namespace std;

int arr[128][128];
int ans[2];

bool samenum(int size, int row, int col){
	int tmp = arr[row][col];
	for(int i = row ; i < row+size ; i++){
		for (int j = col ; j < col+size ; j++){
			if(arr[i][j] != tmp)
				return false;
		}
	}
	return true;
}

void f(int size,int row,int col){
	if(samenum(size,row,col)){
		ans[arr[row][col]]++;
		return;
	}
	int nextsize = size /2;
	for(int i = 0 ; i < 2 ; i++){
		for (int j = 0 ; j < 2 ; j++){
			f(nextsize,row+i*nextsize,col+j*nextsize);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> arr[i][j];
	f(n,0,0);
	cout << ans[0] << '\n';
	cout << ans[1] << '\n';
	return 0;
}