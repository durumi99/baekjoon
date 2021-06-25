#include <iostream>
using namespace std;

int main() {
	int n;
	double max = 0, sum = 0;
	cin >> n;
	double arr[n];
	for(int i = 0 ; i < n ;i++){
		cin >> arr[i];
		if (max < arr[i]){
			max = arr[i];
		}
	}
	for(int i = 0 ; i < n ;i++){
		arr[i] = arr[i] * 100 / max;
		sum += arr[i];
	}
	cout << sum / n << endl;
	return 0;
}