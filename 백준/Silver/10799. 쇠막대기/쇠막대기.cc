#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
  int answer = 0;
  stack <char> s;
  string str; cin >> str;
  for(int i = 0 ; i < str.length() ; i++) {
    if (str[i] == '(')
      s.push('(');
    else {
      s.pop();
      if(str[i-1] == '(')
        answer += s.size();
      else 
        answer++;
    }
  }
  cout << answer;
  return 0;
}