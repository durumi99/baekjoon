#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	priority_queue <long long,vector <long long>, greater <long long> > q;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		long long input;
		cin >> input;
		if(input > 0)
			q.push(input);
		else{
			if(q.empty())
				cout << 0 << '\n';
			else{
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
	return 0;
}