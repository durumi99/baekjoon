#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,tmp;
	int arr[10001] = {0,};
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> tmp;
		arr[tmp]++;
	}
	for(int i = 0 ; i <= 10000 ; i++){
		for(int j = 0 ; j < arr[i] ; j++){
			cout << i << '\n';
		}
	}
	return 0;
}