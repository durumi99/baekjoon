#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
int n,m;
void floyd(){
	for(int k = 1 ; k <= n; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++){
				if(i == j)
					continue;
				if(arr[i][k] && arr[k][j]){
					if(arr[i][j]==0)
						arr[i][j] = arr[i][k]+ arr[k][j];
					else
						arr[i][j] = min(arr[i][j],arr[i][k]+ arr[k][j]);
				}
			}
}

int main() {
	int min = 1000000,user;
	cin >> n >> m;

	for(int i = 0 ; i < m; i++){
		int u,v;
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	floyd();
	
	for(int i = 1 ; i <= n ; i++){
		int sum = 0;
		for(int j = 1 ; j <= n ; j++)
			sum += arr[i][j];
			
		if (sum < min){
			min = sum;
			user = i;
		}
	}	
	
	cout << user ;
	return 0;
}