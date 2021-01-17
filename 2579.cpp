#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[300],ans[300];
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	ans[0] = arr[0];
	ans[1] = arr[0] + arr[1];
	ans[2] = arr[2] + max(arr[0],arr[1]);
	for(int i = 3; i < n ; i++)
		ans[i] = arr[i] + max(ans[i-2],ans[i-3]+arr[i-1]);
	cout << ans[n-1] << '\n';
	return 0;
}