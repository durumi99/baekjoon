#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[N+1];
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for(int i = 4 ; i <= N; i++){
		if(i % 6 == 0)
			arr[i] = min(min(arr[i-1],arr[i/2]),arr[i/3]) + 1;
		else if(i % 3 == 0)
			arr[i] = min(arr[i-1],arr[i/3])+1;
		else if(i % 2 == 0)
			arr[i] = min(arr[i-1],arr[i/2])+1;
		else
			arr[i] = arr[i-1] + 1;
	}
	cout << arr[N];
	return 0;
}