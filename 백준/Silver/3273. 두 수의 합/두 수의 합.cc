#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

int N;
int a[MAX];
int x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
	cin >> N;
	for(int i = 0 ; i < N ; i++)
		cin >> a[i];
	sort(a, a+N);
	cin >> x;
	int left = 0;
	int right = N-1;
	int sum;
	int ans = 0;
	while(left < right) {
		sum = a[left] + a[right];
		if(sum == x) {
			ans++;
			left++;
		} else if(sum < x) {
			left++;
		} else {
			right--;
		}
	}
	
	cout << ans;
    return 0;
}