#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main() {
  string str; cin >> str;
  stack <char> l,r;
  for(int i = 0 ; i < str.length() ; i++)
    l.push(str[i]);
  int n; cin >> n;
  while(n--) {
    // cout << s << ' ' << cursor << '\n';
    char oper; cin >> oper;
    if(oper == 'P') {
      char tmp; cin >> tmp;
      l.push(tmp);
    } else if(oper == 'L') {
      if(!l.empty()) {
        r.push(l.top());
        l.pop();
      }
    } else if(oper == 'D') {
      if(!r.empty()) {
        l.push(r.top());
        r.pop();
      }
    } else if(oper == 'B') {
      if(!l.empty())
        l.pop();
    }
  }
  while(!l.empty()) {
    r.push(l.top());
    l.pop();
  }
  while(!r.empty()) {
    cout << r.top();
    r.pop();
  }
  return 0;
}