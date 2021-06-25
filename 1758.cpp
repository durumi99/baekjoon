#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,m;
	long long tip = 0;
	cin >> n;
	vector<int> v;
	for(int i = 0 ; i < n ; i++){
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(),v.end(),greater <int> ());
	for(int i = 0 ; i < n ; i++ ){
		if(v[i]-i > 0)
			tip += v[i]-i;
	}
	cout << tip;
	return 0;
}