#include <iostream>
#include <algorithm>

using namespace std;
long long card[100001];

int main() {
	// your code goes here
	int N; cin >> N;
	for(int i = 0 ; i < N ; i++) {
		cin >> card[i];
	} 
	sort(card, card+N);
	long long ans = card[0];
	int cnt = 1;
	int max = 1;
	for(int i = 1 ; i < N ; i++) {
		if(card[i] == card[i-1]) 
			cnt++;
		else
			cnt = 1;
			
		if(cnt > max) {
			max = cnt;
			ans = card[i];
		}
	}
	cout << ans;
	return 0;
}