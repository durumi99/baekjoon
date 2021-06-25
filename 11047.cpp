#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long int n,k;
	cin >> n >> k;
	vector< long long int> v;
	for(int i = 0 ; i < n ; i++){
		long long int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),greater<>());
	
	int ans = 0;
	for(auto i : v)
		if(k >= i){
			ans += k / i ;
			k %= i;
		}
	cout << ans;
	return 0;
}