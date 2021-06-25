#include <iostream>
using namespace std;

int main() {
	int n , m ,sum,min = 0;
	cin >> n >> m;
	int arr[100];
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	for(int i = 0 ; i < n ; i++)
		for(int j = i + 1 ; j < n ; j++)
			for(int k = j + 1 ; k < n ; k++){
				sum = arr[i] + arr[j] + arr[k];
				if(sum == m){
					cout << sum << '\n';
					return 0;
				}
				else if(min < sum && sum < m )
					min = sum;
			}
	cout << min << '\n';
	return 0;
}