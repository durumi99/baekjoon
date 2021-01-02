#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool comp(string a, string b) {
    if (a.length() == b.length()) 
    	return a < b;
    return a.length() < b.length();
}

int main() {
	int tc;
	cin >> tc;
	string arr[tc];
	for(int i = 0 ; i < tc ; i++){
		cin >> arr[i];
	}
	sort(arr,arr+tc,comp);
	cout << arr[0] << endl;
	for(int i = 1 ; i < tc ; i++){
		if (arr[i] != arr[i-1])
			cout << arr[i] << endl;
	}
	return 0;
}