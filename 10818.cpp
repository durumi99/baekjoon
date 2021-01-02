#include <iostream>
using namespace std;

int main() {
	long long n,tmp;
	cin >> n;
	long max = -1000000, min = 1000000;
	for(int i = 0 ; i < n ; i++){
		cin >> tmp;
		if(tmp > max)
			max = tmp;
		if(tmp < min)
			min = tmp;
	}
	cout << min << ' ' << max << endl;
 	return 0;
}