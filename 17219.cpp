#include <iostream>
#include <map>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a,b,input;
	int n,m;
	cin >> n >> m;
	map <string,string> map;
	for(int i = 0 ; i < n ; i++){
		cin >> a >> b;
		map.insert({a,b});
	}
	for(int i = 0 ; i < m ; i++){
		cin >> input;
		cout << map.find(input)->second << '\n';
	}
	return 0;
}