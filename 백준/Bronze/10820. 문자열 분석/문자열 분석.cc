#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int main() {
  string s;
  while(getline(cin, s)){
    int small = 0;
    int large = 0;
    int num = 0;
    int space = 0;
    for(int i = 0 ; i < s.length() ; i++) {
      if(s[i] >= 'a' && s[i] <= 'z') {
        small++;
      } else if(s[i] >= 'A' && s[i] <= 'Z') {
        large++;
      } else if(s[i] == ' ') {
        space++;
      } else if(s[i] >= '0' && s[i] <= '9') {
        num ++;
      }
    }
    cout << small << ' ' << large << ' ' << num << ' ' << space << '\n';
  }
  
  return 0;
}