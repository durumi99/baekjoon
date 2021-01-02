#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum=0;
	string tmp;
	cin >> tmp;
	for(int i = 0 ; i < n ; i++){
		sum += tmp[i]-'0';
	}	
	cout << sum << endl;
 	return 0;
}