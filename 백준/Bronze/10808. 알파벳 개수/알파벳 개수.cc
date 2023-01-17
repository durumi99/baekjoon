#include <iostream>

using namespace std;

int main() {
  int alph[30]={0, };
  string s; cin >> s;
  for(int i = 0 ; i < s.length() ; i++) {
    alph[s[i]-'a']++;
  }
  for(int i = 0 ; i <= 'z' - 'a' ; i++)
    cout << alph[i] << ' ';
  return 0;
}