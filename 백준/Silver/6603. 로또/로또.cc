#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int k;
int lotto[15];
void bt(int idx, vector <int> v) {
	if(idx == k) {
		if(v.size() == 6) {
			for(int i = 0 ; i < 6 ; i++)
				cout << v[i] << ' ';
			cout << '\n';
		}
		return;
	}
	
	v.push_back(lotto[idx]);
	bt(idx+1, v);
	v.pop_back();
	bt(idx+1, v);
}
int main() {
	while(true) {
		cin >> k;
		if(k == 0)
			break;
		for(int i = 0 ; i < k ; i++)
			cin >> lotto[i];
		vector <int> v;
		bt(0, v);
		cout << '\n';
	}
	return 0;
}