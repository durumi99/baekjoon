#include <iostream>
using namespace std;
int sum[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	int num;
	
	for(int i = 1 ; i <= n ; i++){
		cin >> num;
		sum[i] = sum[i-1] + num;
	}

	for(int k = 0 ; k < m ; k++){
		int i,j;
		cin >> i >> j;
		cout << sum[j] - sum[i-1] << '\n';
	}
	
	return 0;
}