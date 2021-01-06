#include <iostream>
#include <algorithm>
using namespace std;
#define llu unsigned long long
int main() {
	llu n , m , res = 0;
	cin >> n >> m;
	llu arr[1000000];
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];
	
	sort(arr,arr+n);

	llu left = 0;
	llu right = arr[n-1];
	while(left <= right){

		llu mid = (left+right) / 2;
		llu tmp = 0;
		for(int i = 0 ; i < n ; i++)
			if(arr[i] > mid)
				tmp += arr[i] - mid;

		if(tmp == m){
			res = mid;
			break;
		}
		else if(tmp > m){
			left = mid + 1;
			if(res < mid)
				res = mid;
		}
		else
			right = mid -1;
	
	}
	cout << res << '\n';
	return 0;
}