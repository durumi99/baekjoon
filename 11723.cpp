#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
vector <int>::iterator it;

void adder(int tmp){
	it = find(v.begin(),v.end(),tmp);
	if( it == v.end())
		v.push_back(tmp);
}
void remover(int tmp){
	it = find(v.begin(),v.end(),tmp);
	if( it != v.end())
		v.erase(it);
}
void checker(int tmp){
	it = find(v.begin(),v.end(),tmp);
	if( it == v.end())
		cout << 0 << '\n';
	else
		cout << 1 << '\n';
}
void toggler(int tmp){
	it = find(v.begin(),v.end(),tmp);
	if( it == v.end())
		adder(tmp);
	else
		remover(tmp);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,tmp;
	string str;
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		cin >> str;
		if(str == "add"){
			cin >> tmp;
			adder(tmp);
		}
		else if(str == "remove"){
			cin >> tmp;
			remover(tmp);
		}
		else if(str == "check"){
			cin >> tmp;
			checker(tmp);
		}
		else if(str == "toggle"){
			cin >> tmp;
			toggler(tmp);
		}
		else if(str == "all"){
			v.clear();
			for(int i = 1; i <= 20; i++)
				v.push_back(i);
		}
		else if(str == "empty"){
			v.clear();
		}
	}
}