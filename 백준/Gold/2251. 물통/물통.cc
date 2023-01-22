#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int A, B, C;
set <int> s;
int visited[201][201][201];
void dfs(int a, int b, int c){
	if(visited[a][b][c]){
		return;
	}
	visited[a][b][c] = 1;
	if(a == 0)		
		s.insert(c);
	// A -> B
	if(b < B && a != 0) {
		int tmp = min(a, B-b);
		dfs(a-tmp, b+tmp, c);
	}
	// A -> C
	if(c < C && a != 0) {
		int tmp = min(a, C-c);
		dfs(a-tmp, b, c+tmp);
	}
	// B -> A
	if(a < A && b != 0) {
		int tmp = min(A-a, b);
		dfs(a+tmp, b-tmp, c);
	}
	// B -> C
	if(c < C && b != 0) {
		int tmp = min(b, C-c);
		dfs(a, b-tmp, c+tmp);
	}
	// C -> A
	if(a < A && c != 0) {
		int tmp = min(c, A-a);
		dfs(a+tmp, b, c-tmp);
	}
	// C -> B
	if(b < B && c != 0) {
		int tmp = min(c, B-b);
		dfs(a, b+tmp, c-tmp);
	}
}
int main() {
	cin >> A >> B >> C;
	
	dfs(0, 0, C);
	
	for(auto i: s)
		cout << i << ' ';
	return 0;
}