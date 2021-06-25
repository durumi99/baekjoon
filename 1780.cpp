#include <iostream>
using namespace std;
int ans[3];
int arr[2187][2187];

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
		//cout<< '!' <<'\n';
		return;
	}
	int nextsize = size /3;
	for(int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			f(nextsize,row+i*nextsize,col+j*nextsize);
		}
	}
}


int main() {
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
			for (int j = 0 ; j < n ; j++){
				int input;
				cin >> input;
				arr[i][j] = ++input;
			}
	}
	f(n,0,0);
	for(int i = 0 ; i < 3 ; i++){
		cout << ans[i] << '\n';
	}
	return 0;
}