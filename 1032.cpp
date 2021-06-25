#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string str[50];
	string res;
	cin >> n;
	cin >> res;
	for(int i = 1 ; i < n ; i++){
		cin >> str[i];
		for(int j = 0 ; j < res.size() ; j++)
			if(res[j] != str[i][j])
				res[j] = '?';
	}
	cout << res << '\n';
	return 0;
}