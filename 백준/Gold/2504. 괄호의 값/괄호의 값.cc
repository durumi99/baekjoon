#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; cin >> str;
    
    stack <char> s;
    int ans = 0, tmp = 1;
    
    for(int i = 0 ; i < str.length() ; i++) {
        if(str[i] == '(') {
            tmp *= 2;
            s.push(str[i]);
        } else if(str[i] == '[') {
            tmp *= 3;
            s.push(str[i]);
        } else if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {
                ans = 0;
                break;
            } 
            if(str[i-1] == '(') {
                ans += tmp;
            } 
            tmp /= 2;
            s.pop();
        } else {
            if(s.empty() || s.top() != '[') {
                ans = 0;
                break;
            } 
            if(str[i-1] == '[') {
                ans += tmp;
            } 
            tmp /= 3;
            s.pop();
        }
    }
    
    if(!s.empty())
        ans = 0;
        
    cout << ans;
    return 0;
}