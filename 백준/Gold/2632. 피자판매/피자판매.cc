#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int pSize;
int m, n;
vector <long long> a, b;
vector <long long> aa;
vector <long long> bb;
long long ans = 0;
int main() {
	// your code goes here
	cin >> pSize;
	cin >> m >> n ;
	long long sum = 0;
	for(int i = 0 ; i < m ; i++) {
		long long tmp; cin >> tmp;
		a.push_back(tmp);
		sum += tmp;
	}
	if(sum < pSize)
		aa.push_back(sum);
	if(sum == pSize)
		ans++;
	
	sum = 0;
	for(int i = 0 ; i < n ; i++) {
		long long tmp; cin >> tmp;
		b.push_back(tmp);
		sum += tmp;
	}
	if(sum < pSize)
		bb.push_back(sum);
	if(sum == pSize)
		ans++;
		
	for(int i = 0 ; i < m ; i++) {
		long long sum = 0;
		for(int j = 0 ; j < m-1 ; j++) {
			sum += a[j];
			if(sum < pSize)		
				aa.push_back(sum);
			if(sum == pSize)
				ans++;
	
		}
		a.insert(a.begin(), a.back());
		a.pop_back();
	}

	sort(aa.begin(), aa.end());
	// for(int i = 0 ; i < aa.size() ; i++) {
	// 	cout << aa[i] << '\n';
	// }
	
	for(int i = 0 ; i < n ; i++) {
		long long sum = 0;
		for(int j = 0 ; j < n-1 ; j++) {
			sum += b[j];
			if(sum < pSize)		
				bb.push_back(sum);
			if(sum == pSize)
				ans++;
		}
		b.insert(b.begin(), b.back());
		b.pop_back();
	}

	sort(bb.begin(), bb.end());
	
	// for(int i = 0 ; i < bb.size() ; i++) {
	// 	cout << bb[i] << '\n';
	// }
	
	for(int i = 0 ; i < aa.size() ; i++) {
		long long upper = upper_bound(bb.begin(), bb.end(), pSize-aa[i]) - bb.begin();
		long long lower = lower_bound(bb.begin(), bb.end(), pSize-aa[i]) - bb.begin();
		// cout << aa[i] << ' ' << (upper-lower) << '\n';
		ans += (upper-lower);
	}
	
	cout << ans;
	return 0;
}