#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N,cnt = 0;
	cin >> N;
	int tmp =5;
	while(true){
		if(N / tmp == 0)
			break;
		cnt += N / tmp;
		tmp *= 5;
	}
	cout << cnt;
	return 0;
}