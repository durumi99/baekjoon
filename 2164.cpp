#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n == 1){
		cout << 1;
		return 0;
	}
	queue <int> q;
	for(int i = 1 ; i <= n ;i++){
		q.push(i);
	}
	while(true){
		q.pop();
		q.push(q.front());
		q.pop();
		if(q.size() == 1){
			cout << q.back();
			break;
		}
	}
	return 0;
}