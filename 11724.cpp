
#include <iostream>
using namespace std;

int arr[1001][1001];
int n;
void f(int prev,int next){
	arr[prev][next] = arr[next][prev] = 0;
	for(int k = 1 ; k <= n; k++)
		if(arr[next][k] == 1)
			f(next,k);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,cnt = 0;
	cin >> n >> m;

	for(int i = 0 ; i < m ; i++){
		int u,v;
		cin >> u >> v;
		arr[v][u] = arr[u][v] = 1;
	}
	for(int i = 1 ; i <= n ; i++)
		arr[i][i] = 1;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1; j <= n ; j++)
			if(arr[i][j] == 1){
				f(i,j);
				cnt++;
			}

	cout << cnt;
	return 0;
}