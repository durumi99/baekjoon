#include <iostream>
using namespace std;

int main() {
	int n;
	int rest[9][4]= {
		{1,1,1,1},
		{6,2,4,8},
		{1,3,9,7},
		{6,4,6,4},
		{5,5,5,5},
		{6,6,6,6},
		{1,7,9,3},
		{6,8,4,2},
		{1,9,1,9}
	};
	
	cin >> n;
	int ary[n][2];
	
	for(int i = 0 ; i < n ; i++)
		cin >> ary[i][0] >> ary[i][1];
		
	for(int i = 0 ; i < n ; i++){
		if(ary[i][0] % 10 == 0)	
			cout << 10 << endl;
		else
			cout << rest[ary[i][0] % 10 -1][ary[i][1] % 4] << endl;
	}
	return 0;
}