#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack <char> stack;
	int n,k=0;
	bool check;
	cin >> n;
	string tmp;
	for(int i = 0 ; i < n; i ++){
		cin >> tmp;
		
		for(int j = 0 ; j < tmp.size(); j++){
			if(tmp[j] == '(')
				k++;
			else
				k--;
		}
		if(k != 0){
			cout << "NO" << endl;
			k = 0;
			continue;
		}
		
		for(int j = 0 ; j < tmp.size(); j++){
			if(tmp[j] == '(')
				stack.push('(');
			else if(stack.empty()){
				cout << "NO" << endl;
				check = true;
				break;
			}
			else{
				stack.pop();
			}
		}
		if(check == false){
			if(stack.empty())
				cout << "YES" << endl;
			else{
				cout << "NO" << endl;
				while(!stack.empty()){
					stack.pop();
				}
			}
		}
		else {
			check = false;
		}
	}
	return 0;
}