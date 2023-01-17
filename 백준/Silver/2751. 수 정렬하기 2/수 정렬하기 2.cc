#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	int ary[1000000];
	for(int i = 0 ; i < tc ; i++)
		cin >> ary[i];
	sort(ary,ary+tc);
	for(int i = 0 ; i < tc ; i++)
		cout << ary[i] << '\n';
	return 0;
}