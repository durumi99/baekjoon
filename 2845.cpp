#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int answer = 0;
	int a,b;
	int arr[5];
	cin >> a >> b;
	answer = a*b;

	for(int i = 0  ; i < 5 ; i++){
		cin >> arr[i];
		arr[i] -= answer;
	}
	for(int i = 0  ; i < 5 ; i++){
		cout << arr[i] << " " ;
	}
	return 0;
}