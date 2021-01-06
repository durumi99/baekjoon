#include <iostream>

using namespace std;

int main() {
	int tc,h,w,n;
	cin >> tc;
	for(int i = 0 ; i < tc ; i++){
		cin >> h >> w >> n;
		int num = (n+h-1) / h;
		int floor = n % h;
		if (floor == 0)
			floor = h;
		int res = floor * 100 + num;
		cout << res << endl;
	}
	return 0;
}