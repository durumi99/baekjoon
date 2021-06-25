#include <iostream>
using namespace std;

int main() {
	int n,m,cnt=0,ans = 0;
	cin >> n >> m;
	int ary[501][501]={0};
	
	for(int i = 1 ; i <= m ; i++){
		int tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		ary[tmp1][tmp2] = -1; 
		ary[tmp2][tmp1] = 1;
	}
	
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ;j++){
				if(ary[i][k] == ary[k][j] && ary[i][k] != 0 && ary[k][j] != 0)
					ary[i][j] = ary[i][k];
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++){
		cnt = 0;
		for(int j = 1 ; j <= n ; j++){
			if(ary[i][j] != 0)
				cnt++;
		}
		if(cnt == n-1)
			ans++;
	}
	cout << ans;
	return 0;
}