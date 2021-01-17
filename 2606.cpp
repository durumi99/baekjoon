#include <iostream>
#include <vector>
using namespace std;

int arr[101][101];
int cnt = 0;
bool visited[101];
vector <int> g[101];

void f(int n){
	visited[n] = true;
	for(int next:g[n]){
		if(visited[next] == false){
			cnt++;
			f(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n;
	cin >> m;

	for(int i = 0 ; i < m ; i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	f(1);
	cout << cnt;
	
	return 0;
}