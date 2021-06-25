#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,j=0;
	cin >> n;
	int arr[n];
	stack <int> s;
	vector <char>v;
	for(int i = 0 ; i < n ; i++)
		cin >>arr[i];
	for(int i = 1; i <= n ;i++){
		s.push(i);
		v.push_back('+');
		while(!s.empty() && s.top() == arr[j]){
			s.pop();
			v.push_back('-');
			j++;
		}
	}
	if(!s.empty())
		cout << "NO" << '\n';
	else 
		for(int i = 0 ; i < v.size() ; i ++)
			cout << v[i] << '\n';
	return 0;
}