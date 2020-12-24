#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	int ary[tc];
	for(int i = 0 ; i < tc ; i++)
		cin >> ary[i];
	sort(ary,ary+tc);
	for(int i = 0 ; i < tc ; i++)
		cout << ary[i] << endl;
	return 0;
}