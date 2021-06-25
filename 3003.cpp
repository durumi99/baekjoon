#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int arr[]={1,1,2,2,2,8};
	int tmp;
	for(int i = 0 ; i < 6 ; i++){
		cin >> tmp;
		arr[i] -= tmp;
	}
	for(int i = 0 ; i < 6 ; i++){
		cout << arr[i] << " ";
	}
	return 0;
}