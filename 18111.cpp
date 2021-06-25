#include <iostream>
#include <climits>
using namespace std;

int main() {
	int n,m,b;
	cin >> n >> m >> b;
	int arr[501][501];
	int min = INT_MAX;
	int max = 0;
	for(int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < m ; j++){
			cin >> arr[i][j];
			if (arr[i][j] < min)
				min = arr[i][j];
			if (arr[i][j] > max)
				max = arr[i][j];
			
		}
	int res = INT_MAX,cnt,resH;	
	for(int h = min ; h <= max ; h++){
		int tmpB = b;
		int cnt = 0;
		for(int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < m ; j++){
				if (arr[i][j] > h){ // 1번
					cnt += (arr[i][j] - h) * 2;
					tmpB += arr[i][j] - h;
				}	
				else { // 2번
					cnt += h - arr[i][j];
					tmpB -= h - arr[i][j];
				}
			}
			
		if (tmpB < 0)
			continue;
		if (cnt < res){
			resH = h;
			res = cnt;
		}
		else if (cnt == res && h > resH){
			resH = h;
		}
	}
	cout << res << ' ' << resH;
	return 0;
}