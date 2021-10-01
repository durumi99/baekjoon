#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
vector <int> v;
vector <int> number;
bool visited[10000];
void print(){
	for(int j = 0 ; j < m ; j++){
		cout << v[j] << ' ';
	}
	cout << '\n';
}
void backtracking(int num,int cnt){
	if(cnt == m){
		print();
		return;
	}
	int before = -1;
	for(int i = 0 ; i < n ;i++){
		if(!visited[i] && (i == 0 || before != number[i]) ){
		    before = number[i];
			visited[i] = true;
			v.push_back(number[i]);
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
	int tmp;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
	    cin >> tmp;
	    number.push_back(tmp);
	}
	sort(number.begin(),number.end());
	
	
    
    backtracking(0,0);
	return 0;
}