#include <iostream>
using namespace std;

int main() {
	int a[2][3];
	for(int i = 0 ; i < 2; i++){
		for(int j = 0 ; j < 3; j++){
			cin >> a[i][j];
		}
	}
	if(a[1][1] > a[0][1])
		cout << a[1][0]-a[0][0]<< endl;
	else if (a[1][1] == a[0][1] && a[1][2] >= a[0][2])
		cout << a[1][0]-a[0][0]<< endl;
	else
		cout << a[1][0]-a[0][0]-1<< endl;
	cout << a[1][0]-a[0][0]+1 << endl;
	cout << a[1][0]-a[0][0];
	
	return 0;
}