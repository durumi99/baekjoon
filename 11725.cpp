#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> tree[111111];
bool visited[111111];
int parent[111111];
void findParent(int node){
	visited[node] = true;
	for(int i = 0 ; i < tree[node].size() ; i++){
		int next = tree[node][i];
		if(!visited[next]){
			parent[next] = node;
			findParent(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int tmp1,tmp2;
	cin >> n;
	for(int i = 0 ; i < n-1 ; i++){
		cin >> tmp1 >> tmp2;
		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
	}
	findParent(1);
	for(int i = 2; i <= n ; i++)
		cout << parent[i] << '\n';
	return 0;
}