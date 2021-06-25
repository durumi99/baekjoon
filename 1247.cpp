#include <iostream>
#include <climits>
using namespace std;

int main() {
	int n;
	long long sum = 0;
	long long tmp;
	int of = 0;
	for(int i = 0 ; i < 3 ; i ++){
		of = 0;
		sum = 0;
		cin >> n;
		
		for(int j = 0 ; j < n ; j++){
			cin >> tmp;
			if(sum > 0 && tmp > 0 && sum > LLONG_MAX - tmp)
				of++;
			else if(sum < 0 && tmp < 0 && sum < LLONG_MIN - tmp)
				of--;
			sum += tmp;
		}
		if(of > 0)
			cout << '+';
		else if (of < 0)
			cout << '-';
		else {
			if(sum > 0)
				cout << '+';
			else if (sum == 0)
				cout << '0';
			else
				cout << '-';
		}
		cout << endl;
	}
	return 0;
}