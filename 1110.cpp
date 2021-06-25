#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,tmp,cnt=0;
	cin >> n;
	tmp = n;
	while(true){
		tmp = (tmp / 10 + tmp % 10 ) % 10 + tmp % 10 * 10;
		cnt++;
		if(tmp == n)
			break;
	}
	cout << cnt << '\n';
	return 0;
}