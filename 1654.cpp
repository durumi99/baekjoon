#include <iostream>
#include <algorithm>
using namespace std;

int k,n;
long long arr[10000];

bool possible(long long len){
	int cnt = 0;

	for (int i = 0; i < k; i++)
		cnt += arr[i] / len;
	if (cnt >=  n)
		return true;
	return false;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k >> n;

	for(int i = 0 ; i < k ; i++)
		cin >> arr[i];
		
	sort(arr,arr+k);
	long long left = 1, right = arr[k-1],res = 0;
	
	while(left <= right){
		long long mid = (left + right) / 2;
		if(possible(mid)){
			if(res < mid)
				res = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << res << '\n';
	
	return 0;
}