#include <iostream>
#include <stack>
using namespace std;
int main() {
	string str;
	while(getline(cin,str)){
		stack <char> s;
		if(str == ".")
			break;
		for(int i = 0; i < str.size();i++){
			if(str[i] == '(')
				s.push('(');
			else if (str[i] == '[')
				s.push('[');
				
			else if (str[i] == ')'){
				if (!s.empty() && s.top() == '(')
					s.pop();
				else{
					s.push(')');
					break;
				}
			}
			
			else if ( str[i] == ']'){
				if (!s.empty() && s.top() == '[')
					s.pop();
				else{
					s.push(')');
					break;
				}
			}
			
		}
		if(s.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	} 
	return 0;
}