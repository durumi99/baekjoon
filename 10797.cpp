#include <iostream>
using namespace std;

int main() {
	int n,k[5],cnt=0;
	cin >> n;
	for(int i = 0 ; i < 5 ; i++){
		cin >> k[i];
		if(k[i] == n)
			cnt++;
	}
	cout << cnt;
	return 0;
}