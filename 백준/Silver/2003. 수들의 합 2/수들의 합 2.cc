#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long N, M; cin >> N >> M;
	int cnt = 0;
	long long arr[N];
	for(int i = 0 ; i < N ; i++){
		cin >> arr[i];
	}
	
	int left = 0;
	int right = 0;
	long long sum = arr[0];
	
	while(left <= right && right < N) {
		// cout << left << ' ' << right << '\n';
		if(sum <= M) {
			if(sum == M) {
				cnt++;
			}
			right++;
			sum += arr[right];
		} else {
			sum -= arr[left];
			left++;
			if(left > right) {
				right = left;
				sum = arr[left];
			}
		}
	}	
	
	cout << cnt;
	return 0;
}