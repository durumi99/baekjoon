#include <iostream>
#include <vector>
#include <utility>
using namespace std;
char tree[26][2] = {'.',};
void pre(char root){
	if(root == '.')
		return;
	cout << root;
	pre(tree[root-'A'][0]);
	pre(tree[root-'A'][1]);
}
void in(char root){
	if(root == '.')
		return;
	in(tree[root-'A'][0]);
	cout << root;
	in(tree[root-'A'][1]);
}
void post(char root){
	if(root == '.')
		return;
	post(tree[root-'A'][0]);
	post(tree[root-'A'][1]);
	cout << root;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,w;
	const char MN = 30;
	vector <char> g[MN];
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		char root,left,right;
		cin >> root >> left >> right;
		tree[root-'A'][0] = left;
		tree[root-'A'][1] = right;
	}
	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
	cout << '\n';
	
	return 0;
}