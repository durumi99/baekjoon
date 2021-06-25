#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n,m,tmp;
	cin >> n;
	long long arr[n];
	for(int i = 0 ; i< n ; i++)
		cin >> arr[i];
	sort(arr,arr+n);
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		bool k = false;
		cin >> tmp;
		int left = 0, right = n-1;
		while(left <= right){
			int mid = (left+right) / 2;
			if(tmp > arr[mid])
				left = mid + 1;
			else if (tmp < arr[mid])
				right = mid - 1;
			else{
				cout << 1 << '\n';
				k = true;
				break;
			}
		}
		if(!k)
			cout << 0 << '\n';
	}
	return 0;
}