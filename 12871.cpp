#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string s,t,newS,newT;
    cin >> s >> t;
    int len = s.length() * t.length();
    for(int i = 0 ; i  < len / s.length() ; i++)
        newS += s;
    for(int i = 0 ; i  < len / t.length() ; i++)
        newT += t;
    if(newS == newT)
        cout << 1;
    else
        cout << 0;
    return 0;
}