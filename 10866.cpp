#include <iostream>
#include <deque>
using namespace std;
int main() {
	int n,tmp;
	string s;
	cin >> n;
	deque <int> q;
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		if(s == "push_front"){
			cin >> tmp;
			q.push_front(tmp);
		}
		else if(s == "push_back"){
			cin >> tmp;
			q.push_back(tmp);
		}
		else if (s == "pop_front"){
			if(q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop_front();
			}
		}
		else if (s == "pop_back"){
			if(q.empty())
				cout << -1 << '\n';
			else {
				cout << q.back() << '\n';
				q.pop_back();
			}
		}
		else if (s == "size"){
			cout << q.size() << '\n';
		}
		else if( s == "empty"){
			if(q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(s == "front"){
			if(q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if(s == "back"){
			if(q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
	return 0;
}