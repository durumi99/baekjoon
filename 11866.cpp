#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n,k;
	queue <int> q;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
		q.push(i);
	cout << '<';
	while(true){
		int cnt = k;
		while(--cnt){
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if(q.empty())
			break;
		else
			cout << ", ";
	}
	cout << '>';
	return 0;
}