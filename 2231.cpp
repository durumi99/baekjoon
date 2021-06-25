#include <iostream>

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,tmp,sum;
	cin >> n;
	for(int i = 1 ; i < n ; i++){
		sum = i;
		tmp = i;
		while(tmp){
			sum += tmp %10;
			tmp /= 10;
		}
		
		if(sum == n){
			cout <<  i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}