#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	const int MN = 101010;
	vector <int>g[MN];
	int n,q;
	int tmp;
	cin >> n;
	for(int i = 0 ; i < n-1 ; i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> q;
	for(int i = 0 ; i < q; i++){
		int tmp;
		cin >> tmp;
		if(tmp == 1){
			int vertex;
			cin >> vertex;
			if(g[vertex].size() == 1)
				cout << "no" << '\n';
			else
				cout << "yes" << '\n';
		}
		else{
			cin >> tmp;
			cout << "yes" << '\n';
		}
	}
	return 0;
}