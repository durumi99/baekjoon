#include <iostream>
#include <map>
using namespace std;

int main() {
	int tc,n;
	cin >> tc;
	for(int t = 0 ; t < tc ; t++){
		cin >> n;
		string clname,cltype;
		map <string,int> map;
		for(int i = 0 ; i < n ; i++){
			cin >> clname >> cltype;
			if(map.find(cltype) == map.end())
				map.insert({cltype,1});
			else
				map[cltype]++;
		}
		int ans = 1;
		for(auto j : map)
			ans *= (j.second+1);
		ans -= 1;
		cout << ans << '\n';
	}
	return 0;
}