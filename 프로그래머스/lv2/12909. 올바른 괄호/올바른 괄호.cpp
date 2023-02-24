#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack <char> st;
    for(auto it : s) {
        if(it == '(') {
            st.push(it);
        } else {
            if(st.empty()) {
                answer = false;
                break;
            } else {
                st.pop();
            }
        }
    }
    
    if(!st.empty())
        answer = false;
    return answer;
}