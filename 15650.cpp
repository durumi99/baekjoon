#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector <int> v;
bool visited[8];
void print(){
	for(int j = 0 ; j < m ; j++)
		cout << v[j] << ' ';
	cout << '\n';
}
void backtracking(int num,int cnt){
	if(cnt == m){
		print();
		return;
	}
	for(int i = num ; i <= n ;i++){
		if(!visited[i]){
			visited[i] = true;
			v.push_back(i);
			backtracking(i+1,cnt+1);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	backtracking(1,0);
	return 0;
}