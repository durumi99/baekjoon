#include <iostream>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack <char> stack;
    for(int i = 0 ; i < s.size();i++){
        if(!stack.empty() && stack.top() == s[i])
            stack.pop();
        else
            stack.push(s[i]);
    }
    if(stack.empty())
        answer = 1;
    return answer;
}