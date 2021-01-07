#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n,tmp;
	string s;
	cin >> n;
	stack <int> st;
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		if(s == "push"){
			cin >> tmp;
			st.push(tmp);
		}
		else if (s == "pop"){
			if(st.empty())
				cout << -1 << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (s == "size"){
			cout << st.size() << '\n';
		}
		else if( s == "empty"){
			if(st.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(s == "top"){
			if(st.empty())
				cout << -1 << '\n';
			else
				cout << st.top() << '\n';
		}
	}
	return 0;
}