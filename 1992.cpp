#include <iostream>
using namespace std;
int arr[64][64];
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
		cout << arr[row][col] ; 
		return;
	}
	cout << '(';
	int nextsize = size / 2;
	for(int i = 0 ; i < 2 ; i++){
		for (int j = 0 ; j < 2 ; j++){
			f(nextsize,row+i*nextsize,col+j*nextsize);
		}
	}
	cout << ')';
}

int main() {
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			scanf("%1d",&arr[i][j]);
	f(n,0,0);	
	return 0;
}