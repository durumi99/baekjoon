#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector <int> v;
int number[8];
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
	for(int i = num ; i < n ;i++){
	   v.push_back(number[i]);
	   backtracking(i,cnt+1);
	   v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
	    cin >> number[i];
	sort(number,number+n);
    backtracking(0,0);
	return 0;
}