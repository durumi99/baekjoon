#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,m,cnt=0,min = 64;
	cin >> n >> m;
	char board[n][m];
	char board1[8][8] = {
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',

	};
	char board2[8][8] = {
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B'
	};
	
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> board[i][j];
	
	for(int k = 0 ; k <= n-8 ; k++)
		for(int l = 0 ; l <= m-8 ; l++){
			int tmp1 = 0, tmp2 = 0;
			
			for(int i = 0 ; i < 8 ; i++)
				for (int j = 0 ; j < 8 ; j++)
					if(board1[i][j] != board[k+i][l+j])
						tmp1++;

			for(int i = 0 ; i < 8 ; i++)
				for (int j = 0 ; j < 8 ; j++)
					if(board2[i][j] != board[k+i][l+j])	
						tmp2++;
						
			cnt = (tmp1<tmp2) ? tmp1 : tmp2;
			if(cnt < min)
				min = cnt;
		}
	cout << min << endl;
 	return 0;
}