#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int leafcnt = 0;
	int n,w;
	const int MN = 501010;
	vector <int>g[MN];
	cin >> n >> w;
	for(int i = 0 ; i < n-1 ; i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1 ; i <= n ; i++){
		if(g[i].size() == 1 && i != 1)
			leafcnt++;
	}
	printf("%.9f",(double)w/leafcnt);
	return 0;
}