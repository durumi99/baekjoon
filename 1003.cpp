#include <iostream>
using namespace std;
int main() {
	pair<int,int> p[41];
	p[0] = make_pair(1,0);
	p[1] = make_pair(0,1);
	for(int i = 2 ; i <= 40 ; i++){
		p[i] = make_pair(p[i-2].first+p[i-1].first,p[i-2].second+p[i-1].second);
	}
	int tc,tmp;
	cin >> tc;
	for(int i = 0 ; i < tc ; i++){
		cin >> tmp;
		cout << p[tmp].first << ' ' << p[tmp].second << '\n';
	}
	return 0;
}