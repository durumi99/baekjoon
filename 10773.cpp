#include <iostream>
#include <stack>

using namespace std;

int main() {
	int k,sum=0;
	cin >> k;
	stack <int> s;
	while(k--){
		int tmp;
		cin >> tmp;
		if(tmp == 0)
			s.pop();
		else
			s.push(tmp);
	}
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}